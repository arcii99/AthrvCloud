//FormAI DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>

int main() {
    int n, key, i, flag = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements into the array: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int low = 0, high = n - 1, mid = (low + high) / 2;

    while (low <= high) {
        if (arr[mid] == key) {
            flag = 1;
            printf("%d is found at index %d.\n", key, mid);
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
            mid = (low + high) / 2;
        }
        else {
            high = mid - 1;
            mid = (low + high) / 2;
        }
    }

    if (flag == 0) {
        printf("%d is not found in the array.\n", key);
    }

    return 0;
}