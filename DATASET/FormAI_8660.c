//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: mathematical
#include <stdio.h>

int main() {
    int sum = 0;
    int n, i, j;
    printf("Enter the number of integers you want to calculate the checksum for: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the integers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        printf("[%d]: ", arr[i]); // Display the element that is being processed
        for (j = 0; j < arr[i]; j++) {
            printf("*"); // Display asterisks to simulate the mathematical process
        }
        printf("\n");
        sum += arr[i];
    }
    printf("The Unweighted Checksum is %d\n", sum);
    int weighted_sum = 0;
    int weights[n];
    printf("Enter the weights:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    for (i = 0; i < n; i++) {
        printf("[%d]: ", arr[i]); // Display the element that is being processed
        for (j = 0; j < weights[i]; j++) {
            printf("*"); // Display asterisks to simulate the mathematical process
        }
        printf("\n");
        weighted_sum += arr[i] * weights[i];
    }
    printf("The Weighted Checksum is %d\n", weighted_sum);
    return 0;
}