//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: energetic
#include <stdio.h>

int main() {
    printf("Welcome to the Greedy Algorithm program!\n");

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    int count = 0;
    printf("The Greedy Algorithm output:\n");
    for (int i = 0; i < n; i++) {
        if (sum + arr[i] <= 100) {
            sum += arr[i];
            count++;
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
    printf("The minimum number of elements to form the sum of 100: %d\n", count);

    return 0;
}