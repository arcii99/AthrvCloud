//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int n, i, j, temp, sum = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    i = 0;
    while (sum <= 3000 && i < n) {
        if (sum + arr[i] > 3000) {
            break;
        }
        sum += arr[i];
        i++;
    }
    printf("The maximum amount of money that can be collected is: %d", sum);
    return 0;
}