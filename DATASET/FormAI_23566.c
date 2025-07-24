//FormAI DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include<stdio.h>

int my_search(int arr[], int n, int key){
    int i;
    for(i=0; i<n;i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {3,5,9,12,15,17,18,21,23,25,28,31,32,35,38,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 21;
    int index = my_search(arr,n,key);

    if(index == -1){
        printf("Key not found!\n");
    }else{
        printf("Key found at index %d\n", index);
    }
    return 0;
}