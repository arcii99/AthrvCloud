//FormAI DATASET v1.0 Category: Searching algorithm ; Style: bold
#include <stdio.h>

int c_search(int arr[], int n, int x){
    int i = 0;
    while (i < n && arr[i] <= x)
        i += 2;
    int start = i / 2;
    int end = i < n ? i : n-1;
    for (int j = start; j <= end; j++){
        if (arr[j] == x)
            return j;
    }
    return -1;
}

int main(){
    int arr[10] = {1, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    int n = 10;
    int x = 12;
    int result = c_search(arr, n, x);
    if (result == -1)
        printf("Element not found in the array.");
    else
        printf("Element found at index %d", result);
    return 0;
}