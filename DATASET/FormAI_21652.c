//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: ultraprecise
#include <stdio.h>

/* function to calculate the checksum value for an array of integers */
int calculateChecksum(int arr[], int n) {
    int sum = 0, i;
 
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
 
    /* return the checksum value by subtracting the sum from 255 */
    return (255 - sum);
}

int main() {
    int arr[10];
    int i, n;

    /* get the size of the array from the user */
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    /* get the elements of the array from the user */
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /* calculate the checksum value for the array */
    int checksum = calculateChecksum(arr, n);

    /* print the checksum value for the array */
    printf("The checksum value for the array is: %d\n", checksum);

    return 0;
}