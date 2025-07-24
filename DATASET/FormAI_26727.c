//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int array[], int n) {
    int i, j, k;
    int count[n];
    for(i = 0; i < n; i++)
        count[i] = 0;
    for(i = 0; i < n; i++)
        (count[array[i]])++;
    for(i = 0, j = 0; i < n; i++) {
        for(k = count[i]; k > 0; k--) {
            array[j++] = i;
        }
    }
}

int main() {
    int i, n;
    
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    bucket_sort(arr, n);
    
    printf("Sorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}