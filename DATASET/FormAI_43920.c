//FormAI DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>

int search(int arr[], int key, int size){
    int i;
    for(i=0; i<size; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 10, 6, 17, 9, 3};
    int key = 17;
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = search(arr, key, size);
    if(result == -1){
        printf("%d not found in the array", key);
    }
    else{
        printf("%d found at index %d", key, result);
    }
    return 0;
}