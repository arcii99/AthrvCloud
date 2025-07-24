//FormAI DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>

int search(int arr[], int n, int x)
{
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main(void)
{
    int arr[100], n, x, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be found: ");
    scanf("%d", &x);
    int result = search(arr, n, x);
    if (result == -1) {
        printf("%d is not present in the array.\n", x);
    } else {
        printf("%d is present at index %d.\n", x, result);
    }
    return 0;
}