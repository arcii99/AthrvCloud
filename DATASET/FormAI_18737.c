//FormAI DATASET v1.0 Category: Arithmetic ; Style: portable
#include<stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    float average = (float)sum / n;
    printf("Average: %.2f\n", average);

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Maximum number: %d\n", max);

    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Minimum number: %d\n", min);

    int product = 1;
    for (int i = 0; i < n; i++) {
        product *= arr[i];
    }
    printf("Product: %d\n", product);

    return 0;
}