//Swap two numbers without temp variable

#include <stdio.h>

int main() {
    int a = 10, b = 20;

    printf("Before swapping: a = %d, b = %d\n", a, b);

    // Swapping logic
    a = a ^ b; // a now holds the XOR of original a and b
    b = a ^ b; // b now holds the original value of a
    a = a ^ b; // a now holds the original value of b

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}
