//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>

void bucketSort(int arr[], int n) {
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;
 
    for (i = 0; i < n; i++)
        (count[arr[i]])++;
 
    for (i = 0, j = 0; i < n; i++) {
        for (; count[i] > 0; (count[i])--) {
            arr[j++] = i;
        }
    }
}
 
int main() {
    int arr[] = {15, 20, 5, 1, 99, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }   
    return 0;
}