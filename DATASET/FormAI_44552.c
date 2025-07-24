//FormAI DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>

int search(int arr[], int n, int key) {
    int i, j = n-1;
    for(i=0; i<=j; ) {
        if(arr[i] == key) {
            return i;
        }
        if(arr[j] == key) {
            return j;
        }
        i++;
        j--;
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 4;
    printf("Index of %d in the array is %d", key, search(arr, n, key));
    return 0;
}