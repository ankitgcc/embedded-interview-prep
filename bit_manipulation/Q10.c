// Find two non-repeating elements in an array
#include <stdio.h>

void find_two_non_repeating(int arr[], int n, int* x, int* y) {
    int xor_sum = 0;
    int set_bit_no;
    int i;

    // 1. XOR all elements to get the XOR sum of the two unique numbers
    for (i = 0; i < n; i++) {
        xor_sum ^= arr[i];
    }

    // 2. Find any set bit (rightmost is typical) in the XOR sum
    // This bit is set because it is different in the two unique numbers (x and y)
    set_bit_no = xor_sum & ~(xor_sum - 1);

    // 3. Divide elements into two groups based on whether that specific bit is set or not
    *x = 0;
    *y = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no) {
            *x ^= arr[i]; // XOR with the first group
        } else {
            *y ^= arr[i]; // XOR with the second group
        }
    }
    // The repeating pairs within each group cancel out, leaving the two unique elements
}

int main() {
    // Example array: elements 7 and 9 are the unique ones
    int arr[] = {2, 4, 7, 9, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x, y;

    find_two_non_repeating(arr, n, &x, &y);

    printf("The two non-repeating elements are %d and %d.\n", x, y);

    return 0;
}

