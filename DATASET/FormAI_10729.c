//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: visionary
#include <stdio.h>

int main() {
    int n, a[1000], sum = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Reading input array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Sort the array in descending order
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Find the sum of top 3 elements
    for (int i = 0; i < 3; i++) {
        sum += a[i];
    }

    printf("Sum of top 3 elements is: %d\n", sum);

    return 0;
}