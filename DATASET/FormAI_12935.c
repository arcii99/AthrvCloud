//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % k == 0) {
            ans += arr[i] / k;
        } else {
            ans += arr[i] / k + 1;
        }
    }

    printf("Minimum number of steps: %d\n", ans);

    return 0;
}