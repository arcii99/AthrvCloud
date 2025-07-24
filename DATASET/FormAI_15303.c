//FormAI DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include<stdio.h>

void printSpaces(int n){
    for(int i=0; i<n; i++){
        printf(" ");
    }
}

void visualize(int arr[], int n, int index, int level){
    if(index == n){
        return;
    }

    visualize(arr, n, 2*index+2, level+1);

    printSpaces(level*4);
    printf("%d\n", arr[index]);

    visualize(arr, n, 2*index+1, level+1);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    int n = sizeof(arr)/sizeof(arr[0]);

    visualize(arr, n, 0, 0);

    return 0;
}