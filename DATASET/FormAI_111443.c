//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
#include <stdio.h>

// function to sort the array in descending order using selection sort algorithm
void selectionSort(int arr[], int n) {
    int i, j, max_idx;
    for (i = 0; i < n-1; i++) {
        max_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    int sum = 0, i = 0;
    while (sum < n/2) {
        sum += arr[i];
        i++;
    }
    printf("The minimum number of elements needed to add up to at least half the sum of the array is: %d", i);
    return 0;
}