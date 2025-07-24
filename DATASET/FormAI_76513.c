//FormAI DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>

int search(int arr[], int n, int x)
{
    /* Start at the beginning of the array and iterate through each element */
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            /* If the element matches the target x, return the index */
            return i;
        } else if (arr[i] > x) {
            /*
             * If the current element is greater than the target x, it
             * means that the element was not found in the array
             */
            return -1;
        }
    }

    /* If the end of the array is reached and x was not found, return -1 */
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;

    /* Call the search function to find the index of x in the array */
    int result = search(arr, n, x);

    /* Check if x was found in the array */
    if (result == -1) {
        printf("Sorry, the element was not found in the array.\n");
    } else {
        printf("The element was found at index %d.\n", result);
    }

    return 0;
}