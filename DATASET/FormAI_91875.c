//FormAI DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include<stdio.h>

void search(int arr[], int n, int key){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==key){
            printf("Element found at index %d\n", i);
            return;
        }
    }
    printf("Element not found in the array\n");
}

int main(){
    int arr[10] = {2,3,1,6,5,4,7,9,8,10};
    int key = 7;
    int n = sizeof(arr)/sizeof(arr[0]);
    search(arr, n, key);
    return 0;
}