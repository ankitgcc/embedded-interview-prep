// Count number of set bits

#include <stdio.h>

unsigned int countSetBits(unsigned int n) {
    unsigned int count = 0;
    while (n > 0) {
        n &= (n - 1); // Unsets the rightmost set bit
        count++;      // Increment count on each unset operation
    }
    return count;
}

int main() {
    int i = 9; // Binary 1001, 2 set bits
    printf("%d has %d set bits\n", i, countSetBits(i));
    return 0;
}
