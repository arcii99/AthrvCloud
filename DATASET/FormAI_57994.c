//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: random
#include <stdio.h>
#define MAX 1000001

int main() {
    int n, k;
    int arr[MAX];
    int i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the values of array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    // Sort the array in non-decreasing order using Bubble Sort
    for(i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Find the sum of first k elements
    int sum = 0;
    for(i = 0; i < k; i++) {
        sum += arr[i];
    }

    printf("The sum of first %d elements of the array is %d\n", k, sum);

    return 0;
}