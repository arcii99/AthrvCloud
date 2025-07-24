//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: irregular
#include <stdio.h>

int main() {
    int n, i, j, max, sum = 0, temp;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements in the array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n - 1; i++) {
        max = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] > arr[max]) {
                max = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }

    printf("The sorted array is: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    for(i = 0; i < n; i++) {
        if(sum + arr[i] <= 500) {
            sum += arr[i];
            printf("%d ", arr[i]);
        }
    }

    printf("\nThe maximum profit is %d", sum);

    return 0;
}