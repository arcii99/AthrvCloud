//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of coins: ");
    scanf("%d", &n);

    int value[n];
    printf("Enter the value of each coin:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }

    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (target >= value[i]) {
            target -= value[i];
            count++;
        }
    }

    printf("Minimum number of coins required: %d\n", count);

    return 0;
}