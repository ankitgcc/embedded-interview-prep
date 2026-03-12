# C Fundamentals

# Keywords

## static
In global scope, the variables and functions defined with the keyword static can only be called within that source file.
In local scope, variables defined with the keyword static retain their value across multiple calls after being initialized once. 

## volatile
In C, the volatile keyword is used to inform the compiler that the value of a variable may change at any time, without any action being taken by the code in the program. It is particularly useful in embedded systems where the value of the variable might change due to interrupts or hardware registers.

## const
The const keyword in C is a type qualifier used to declare that an object or variable is read-only, meaning its value cannot be modified after initialization by the program. 

## extern
The extern keyword in C is a storage class specifier used to declare a variable or function that is defined in another source file or elsewhere in the current file. It tells the compiler that the definition (memory allocation) for the identifier exists elsewhere, and the linker will resolve the reference at link time. 

##

## Memory layout of a C program
<img width="800" height="401" alt="image" src="https://github.com/user-attachments/assets/93915d80-da41-4a17-9ae5-53bb0456deba" />

Code Segment – Where the actual instructions of your program live.

Data Segment – Store all your global and static variables. Initialized and uninitialized (.bss).

Heap – The flexible area where memory grows as we create things dynamically during program execution. Dynamic memory allocation takes place here.

Stack – Keeps track of function calls and local variables. It grows and shrinks automatically as the program runs.

Command-line Arguments – The very top layer that stores input values passed when running the program.


