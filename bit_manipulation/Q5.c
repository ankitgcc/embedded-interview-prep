// Reverse bits of a number

#include <stdio.h>

unsigned int reverseBits(unsigned int num) {
    unsigned int rev = 0;

    for (int i = 0; i < 4; i++) { //for 4 bits, change to 32 if needed
        rev <<= 1;          // Make space for next bit
        rev |= (num & 1);   // Copy LSB of num to rev
        num >>= 1;          // Shift num to process next bit
    }

    return rev;
}

int main() {
    unsigned int n = 5; // 000...0101
    unsigned int result = reverseBits(n); //look up dry run examples
    printf("Reversed: %u\n", result);
    return 0;
}