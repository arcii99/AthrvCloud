//FormAI DATASET v1.0 Category: Searching algorithm ; Style: retro
#include<stdio.h>
#define MAX 100

int main() {
    int arr[MAX], n, item, pos, i;

    // Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get the elements of the array
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the item to be searched
    printf("Enter the item to be searched: ");
    scanf("%d", &item);

    // Linear search algorithm
    for (i = 0; i < n; i++) {
        if (arr[i] == item) {
            pos = i;
            break;
        }
    }

    // Print the result
    if (i == n) {
        printf("Item not found!");
    } else {
        printf("Item found at index %d", pos);
    }

    return 0;
}