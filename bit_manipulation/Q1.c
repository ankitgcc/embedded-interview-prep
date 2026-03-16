//Check if a number is power of two

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    // The check (n > 0) is necessary because the expression also returns 
    // true for n = 0, which is not a power of 2.
    return (n > 0) && ((n & (n - 1)) == 0); 
}


int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPowerOfTwo(n))
        printf("%d is a power of two\n", n);
    else
        printf("%d is NOT a power of two\n", n);

    return 0;
}


// gcc Q1.c -o build/Q1
// ./Q1
