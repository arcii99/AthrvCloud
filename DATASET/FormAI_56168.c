//FormAI DATASET v1.0 Category: Bitwise operations ; Style: future-proof
#include <stdio.h>

// Bitwise ORing each element of an array with the given value
void bitwiseOr(int arr[], int len, int value) {
    for (int i = 0; i < len; i++) {
        arr[i] |= value;
    }
}

// Bitwise XORing each element of an array with the given value
void bitwiseXor(int arr[], int len, int value) {
    for (int i = 0; i < len; i++) {
        arr[i] ^= value;
    }
}

// Bitwise ANDing each element of an array with the given value
void bitwiseAnd(int arr[], int len, int value) {
    for (int i = 0; i < len; i++) {
        arr[i] &= value;
    }
}

int main() {
    // Example usage of the bitwise operations
    int arr[5] = { 5, 7, 9, 3, 1 };
    int len = sizeof(arr)/sizeof(int);
    int value = 6;

    bitwiseOr(arr, len, value);
    printf("Array after bitwise ORing with %d: ", value);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bitwiseXor(arr, len, value);
    printf("Array after bitwise XORing with %d: ", value);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bitwiseAnd(arr, len, value);
    printf("Array after bitwise ANDing with %d: ", value);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}