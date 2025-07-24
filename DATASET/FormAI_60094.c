//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Checksum Calculator!\n");

    int arrSize;
    printf("Enter the size of the array: ");
    scanf("%d", &arrSize);

    int arr[arrSize];
    for(int i = 0; i < arrSize; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for(int i = 0; i < arrSize; i++) {
        sum += arr[i];
    }

    int checksum = sum % 256;
    printf("Calculated checksum: %d\n", checksum);

    printf("Thanks for using the Checksum Calculator!\n");
    return 0;
}