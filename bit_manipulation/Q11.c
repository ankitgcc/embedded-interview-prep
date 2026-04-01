#include <stdio.h>

int findMissingNumber(int arr[], int n) {
    // n is the count of elements that should be present if none were missing.
    // The array 'arr' has a size of n-1.
    
    // Initialize xor_sum with the first number in the range (1)
    int xor_sum = 1;
    
    // XOR all numbers from 2 to N
    for (int i = 2; i <= n; i++) {
        xor_sum ^= i;
    }
    
    // XOR the result with all elements in the given array
    for (int i = 0; i < n - 1; i++) {
        xor_sum ^= arr[i];
    }
    
    // The remaining value in xor_sum is the missing number
    return xor_sum;
}

int main() {
    int arr[] = {1, 2, 4, 5, 6}; // Missing number is 3
    int n = 6; // Range of numbers is 1 to 6
    
    int missing = findMissingNumber(arr, n);
    printf("The missing number is: %d\n", missing);
    
    return 0;
}
