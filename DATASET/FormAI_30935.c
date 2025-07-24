//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

// Custom sorting function to sort the array in ascending order
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to calculate minimum sum possible after selecting k elements from the array
int minimum_sum(int arr[], int n, int k) {
    int sum = 0;
    qsort(arr, n, sizeof(int), compare); // Sorting the array in ascending order
    for(int i = 0; i < k; i++) {
        sum += arr[i]; // Adding the first k elements of the sorted array to the sum
    }
    return sum;
}

int main() {
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);
    printf("The minimum sum after selecting %d elements from the array is: %d", k, minimum_sum(arr, n, k));
    return 0;
}