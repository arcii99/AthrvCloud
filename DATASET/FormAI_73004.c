//FormAI DATASET v1.0 Category: Sorting ; Style: Cryptic
#include <stdio.h>
int main()
{
    int arr[] = {12, 43, 54, 67, 78, 89, 99, 101, 121};
    int i, j, k, temp, n = 9;
    for (i=0; i<n; ++i) {
        for (j=i+1; j<n; ++j) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for (i=0; i<n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}