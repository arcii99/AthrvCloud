//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include<stdio.h>
#define MAX 100

void bucketSort(int arr[], int n) {
    int i, j;
    int count[MAX] = {0};
 
    for (i = 0; i < n; i++)
        count[arr[i]]++;
 
    for (i = 0, j = 0; i < MAX; i++) {
        while(count[i]--)
            arr[j++] = i;
    }
}
 
int main() {
    int n, arr[MAX];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}