//FormAI DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>

int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = 10, x, i, j, flag = 0;

    printf("Enter the element to search: ");
    scanf("%d", &x);

    printf("\nSearching for element %d...\n", x);

    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Element found at index %d.\n", i);
            flag = 1;
            break;
        }
    }

    if (!flag) {
        printf("Element not found in the array.\n");
    }
    
    return 0;
}