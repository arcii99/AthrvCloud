//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(float arr[], int n) {
    int i, j;
    int count[n];
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }
    for (i = 0; i < n; i++) {
        count[(int) arr[i]]++;
    }
    for (i = 0, j = 0; i < n; i++) {
        for(; count[i] > 0; (count[i])--) {
            arr[j++] = i;
        }
    }   
}

int main() {
    float arr[] = {0.3, 0.1, 0.5, 0.8, 0.6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bucket_sort(arr, n);
    
    printf("Sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    
    return 0;
}