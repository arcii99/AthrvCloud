//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    int i, j;
    int* count = (int*)calloc(n, sizeof(int));
    for (i = 0; i < n; i++) {
        ++count[arr[i]];
    }
    for (i = 0, j = 0; i < n; i++) {
        for (; count[i] > 0; count[i]--) {
            arr[j++] = i;
        }
    }
    free(count);
}

int main() {
    int i, n;
    printf("Good morning, Watson. Today we will use a bucket sort algorithm to sort out some cases.\n");
    printf("But first, how many cases do we have today? ");
    scanf("%d", &n);

    int arr[n];
    printf("Please enter the values of the cases one by one, separating them with spaces and pressing Enter key: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Thank you, Watson. The cases are now sorted as follows:\n");
    
    bucketSort(arr, n);

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nElementary, my dear Watson. Another case solved.\n");
    return 0;
}