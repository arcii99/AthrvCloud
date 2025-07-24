//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Claude Shannon
#include <stdio.h>

// Function to calculate the checksum of a given integer array
int checksum(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[100];
    int size;

    // Asking for array size from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Asking for the elements of the array from the user
    printf("Enter the elements of the array: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculating the checksum of the array
    int sum = checksum(arr, size);

    // Displaying the checksum of the array
    printf("The checksum of the given array is %d.\n", sum);

    return 0;
}