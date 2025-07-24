//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: brave
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int max = arr[0];
        int max_index = 0;
        for (int j = 1; j < n; j++) {
            if (arr[j] > max) {
                max = arr[j];
                max_index = j;
            }
        }
        sum += max;
        arr[max_index] = -1;
    }
    printf("The maximum sum of %d elements is: %d", k, sum);
    return 0;
}