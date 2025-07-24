//FormAI DATASET v1.0 Category: Searching algorithm ; Style: bold
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE], i, n, search, flag = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to search: ");
    scanf("%d", &search);

    // Linear Search Algorithm
    for (i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("%d is found at location %d.\n", search, i + 1);
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("%d is not found in the array.\n", search);
    }

    return 0;
}