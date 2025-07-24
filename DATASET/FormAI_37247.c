//FormAI DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>

int main() {
    int arr[] = {15, 57, 22, 42, 31, 11, 67, 99, 75, 44, 88, 66, 33, 20, 51};
    int n = sizeof(arr) / sizeof(int);
    int x, i, j;
    printf("Enter the number to be searched: ");
    scanf("%d", &x);
    printf("Searching for %d...\n\n", x);
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("%d found at position %d\n", x, i + 1);
            break;
        }
        if (i == n - 1) {
            printf("%d not found in the given list\n", x);
        }
    }
    return 0;
}