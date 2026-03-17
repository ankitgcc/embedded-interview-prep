//Find the only non-repeating element in array

#include <stdio.h>

int find_unique(int arr[], int n) {
    int result = 0;
    // XOR all elements in the array
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    return result;
}

int main() {
    int arr[] = {4, 1, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int unique_element = find_unique(arr, n);
    printf("The only non-repeating element is: %d\n", unique_element);
    return 0;
}