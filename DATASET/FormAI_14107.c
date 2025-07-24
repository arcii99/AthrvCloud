//FormAI DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>

int search(int arr[], int n, int x){
    int i;
    for (i = 0; i < n; i++){
        if (arr[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {23, 12, 45, 67, 89, 54};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 67;
    int result = search(arr, n, x);
    if(result == -1){
        printf("Element not present\n");
    }else{
        printf("Element found at index %d\n", result);
    }
    return 0;
}