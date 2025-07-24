//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: minimalist
#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Error: Size can not be larger than %d", MAX_SIZE);
        return -1;
    }

    printf("Enter %d elements:\n", n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the average
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += arr[i];
    }
    float avg = sum / (float) n;

    // Calculate the standard deviation
    float diff_sum = 0;
    for (int i=0; i<n; i++) {
        diff_sum += ((arr[i] - avg) * (arr[i] - avg));
    }
    float std_dev = sqrt(diff_sum / (float) n);

    printf("The average is: %.2f\n", avg);
    printf("The standard deviation is: %.2f\n", std_dev);

    return 0;
}