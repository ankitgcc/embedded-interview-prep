# Microcontroller Boot Process

When a **microcontroller boots**, a sequence of **hardware and firmware operations** occur before the application code starts running. This process begins when power is applied and ends when the program reaches the `main()` function (or `app_main()` in some frameworks).

---

# 1. Power-On Reset (POR)

When power is applied to the microcontroller:

- Internal **power monitoring circuits** ensure the supply voltage is stable.
- The **reset circuit** keeps the CPU in a reset state until the voltage reaches a safe level.

Common hardware circuits involved:

- **Power-On Reset (POR)**
- **Brown-Out Detector (BOD)**
- **External Reset Pin**

If the supply voltage drops below a threshold during operation, the **brown-out detector resets the MCU** to prevent unpredictable behavior.

At this stage:

- The CPU **is not executing instructions yet**.

---

# 2. Clock Initialization

The CPU requires a **clock signal** to operate.

When the reset is released, the microcontroller enables its **default clock source**, typically:

- **Internal RC oscillator** (fast startup)
- **External crystal oscillator** (if configured)

Once the clock stabilizes, the CPU can begin executing instructions.

---

# 3. CPU Exits Reset

After reset is released:

- The **Program Counter (PC)** must know where to start execution.
- Every microcontroller has a **fixed reset vector address** defined in hardware.

Typical reset vector addresses:

| Architecture | Reset Vector Address |
|--------------|---------------------|
| ARM Cortex-M | `0x00000004` |
| AVR | `0x0000` |
| PIC | `0x0000` |

For **ARM Cortex-M processors**, the first two values in flash memory are:

```
Address 0x00000000 → Initial Stack Pointer
Address 0x00000004 → Reset Handler Address
```

The CPU performs the following steps:

1. Load the **stack pointer** from address `0x00000000`
2. Load the **reset handler address** from `0x00000004`
3. Jump to the **Reset Handler**

---

# 4. Boot Mode Selection

Some microcontrollers support multiple **boot modes**.

The MCU may check:

- Boot configuration pins
- Boot fuses
- Boot configuration registers

Possible boot sources include:

- **Main flash memory**
- **Internal bootloader**
- **ROM bootloader**
- **External memory**


---

# 5. Boot ROM Execution

Many modern microcontrollers contain a **ROM bootloader** stored inside the chip.

This firmware performs basic initialization tasks such as:

- Initial hardware setup
- Flash initialization
- Secure boot verification
- Firmware validation

After these checks, the ROM bootloader loads the **user firmware**.

---

# 6. Reset Handler (Startup Code)

Once the firmware image is located, execution jumps to the **Reset Handler**, which is part of the **startup code**.

Startup code is usually written in **assembly** or **low-level C** and provided by the toolchain.

Common file names include:

- `startup_stm32.s`
- `crt0.c`
- `startup.c`

This code prepares the memory before the application starts.

---

# 7. Memory Initialization

The startup code initializes memory sections required for C programs.

## .data Section

The `.data` section contains **initialized global and static variables**.

Example:

```c
int counter = 10;
```

Steps performed:

1. Initial values are stored in **Flash memory**
2. They are **copied into RAM during startup**

## .bss Section

The `.bss` section contains **uninitialized global and static variables**.

Example:

```c
int buffer[100];
```

Steps performed:

1. Memory is allocated in **RAM**
2. It is **cleared to zero during startup**

Startup code typically performs the following operations:

```
Copy .data from FLASH → RAM
Zero initialize .bss
```

---

# 8. System Initialization

Additional system-level initialization may occur before the application starts.

Examples include:

- System clock configuration
- Floating Point Unit (FPU) enable
- Interrupt vector table setup
- Watchdog timer configuration
- Memory protection configuration

This is often handled by a function such as:

```c
SystemInit();
```

---

# 9. C Runtime Initialization

Before entering the application, the **C runtime environment** is initialized.

Tasks may include:

- Initializing the standard library
- Running constructors for global C++ objects

---

# 10. Application Entry Point

Finally, execution reaches the application entry point.

In standard embedded C programs:

```c
int main(void)
{
    // Application code
}
```

At this point, the firmware begins configuring peripherals and running the application logic.

---

# Boot Flow Summary

```
Power On
   │
   ▼
Power-On Reset
   │
   ▼
Clock Initialization
   │
   ▼
CPU Reads Reset Vector
   │
   ▼
Boot ROM Execution (if present)
   │
   ▼
Reset Handler (Startup Code)
   │
   ▼
Initialize .data and .bss
   │
   ▼
System Initialization
   │
   ▼
C Runtime Initialization
   │
   ▼
main()
   │
   ▼
Application Runs
```

---

# Example: ARM Cortex-M Vector Table

A typical **vector table** placed at the beginning of flash memory looks like:

```c
__attribute__((section(".isr_vector")))
void (* const vector_table[])(void) =
{
    (void (*)(void)) &_estack,  // Initial stack pointer
    Reset_Handler,              // Reset handler
    NMI_Handler,
    HardFault_Handler,
};
```

This table is usually located at **flash address `0x00000000`**.

---

