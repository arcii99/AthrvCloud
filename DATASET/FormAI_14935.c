//FormAI DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>

int search(int arr[], int n, int key) {
    int i, flag = 0;
    
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            flag = 1;
            break;
        }
    }
    
    if(flag == 1) {
        printf("Key found at position %d\n", i+1);
        return i;
    } else {
        printf("Key not found in the array\n");
        return -1;
    }
}

int main() {
    int arr[10] = {1, 3, 5, 6, 8, 9, 12, 15, 18, 20};
    int key = 9;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int pos = search(arr, n, key);
    
    return 0;
}