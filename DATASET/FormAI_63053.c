//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: light-weight
#include <stdio.h>

// Function to calculate the checksum of an array of integers
int checksum(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = checksum(arr, 10);
    printf("The checksum is: %d\n", sum);
    return 0;
}