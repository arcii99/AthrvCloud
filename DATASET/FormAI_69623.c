//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n){
    int i, j;
    float temp;
    int count[n];

    for (i = 0; i < n; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        (count[(int)arr[i]])++;

    for (i = 0, j = 0; i < n; i++){
        for (; count[i]>0; (count[i])--){
            arr[j++] = i;
            arr[j++] = '.';
        }
    }
 
    printf("Sorted array using bucket sort: ");
    for (i = 0; i < n-1; i++)
        printf("%f, ", arr[i]);

    printf("%f\n", arr[n - 1]);
}
 
// Driver program to test above function
int main(){
    float arr[] = {0.25, 0.42, 0.39, 0.14, 0.5, 0.31};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n);
    return 0;
}