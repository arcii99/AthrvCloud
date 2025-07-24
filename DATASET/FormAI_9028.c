//FormAI DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>

int brave_search(int arr[], int n, int x){
    int i;
    for (i = 0; i < n; i++){
        if (arr[i] == x){
            printf("Boom! Found it at index %d\n", i);
            return i;
        }
    }
    printf("Sorry, the requested element is not present in the array.\n");
    return -1;
}

int main(){
    int arr[] = {3, 9, 1, 4, 7, 5, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 7;
    brave_search(arr, n, x);
    return 0;
}