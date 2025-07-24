//FormAI DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include<stdio.h>

int search(int arr[], int n, int x) {
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 7, 23, 45, 67, 98, 131};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Enter Search Element: ");
    scanf("%d", &x);

    int index = search(arr, n, x);

    if (index == -1) {
        printf("%d not found!\n", x);
    } else {
        printf("%d found at index: %d\n", x, index);
    }

    return 0;
}