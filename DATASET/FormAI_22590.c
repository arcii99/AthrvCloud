//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
/* A Custom Searching Algorithm */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool search(int arr[], int n, int x);

int main()
{
    int arr[100];
    int n, i;
    int x;

    printf("Enter size of array\n");
    scanf("%d", &n);

    printf("Enter the elements of the array\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search\n");
    scanf("%d", &x);

    if (search(arr, n, x)) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}

bool search(int arr[], int n, int x)
{
    int i = 0;

    while (i < n) {
        if (arr[i] == x) {
            return true;   // return true if element is found
        }
        i++;
    }

    return false;  // return false if element is not found
}