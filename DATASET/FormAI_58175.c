//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i, total = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &num);
    int array[num];
    printf("Enter the elements in the array:\n");
    for (i = 0; i < num; i++) {
        scanf("%d", &array[i]);
    }
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    if (k >= num) {
        printf("Error: Value of k should be less than the size of the array!\n");
        exit(0);
    }
    for (i = 0; i < k; i++) {
        total += array[i];
    }
    int max_sum = total;
    int start = 0;
    for (i = k; i < num; i++) {
        total += array[i] - array[i-k];
        if (total > max_sum) {
            max_sum = total;
            start = i - k + 1;
        }
    }
    printf("The subarray with maximum sum is:\n");
    for (i = start; i < start + k; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("The maximum sum is: %d", max_sum);
    return 0;
}