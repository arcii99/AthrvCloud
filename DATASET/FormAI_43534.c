//FormAI DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>

int search(int arr[], int size, int num){
    int i, flag=0;
    for(i=0; i<size; i++){
        if(arr[i] == num){
            flag = 1;
            break;
        }
    }

    if(flag == 1)
        return i;
    else
        return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int num = 7;
    int pos = search(arr, size, num);

    if(pos == -1)
        printf("Number not found in array.\n");
    else
        printf("Number found at position %d.\n", pos+1);

    return 0;
}