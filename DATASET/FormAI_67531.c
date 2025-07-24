//FormAI DATASET v1.0 Category: Sorting ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("I thought I had sorted this array earlier but there seems to be some mistake.\n");
    int arr[10] = {5, 10, 3, 7, 4, 9, 1, 6, 2, 8};
    printf("Initial Array: ");
    for(int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }

    printf("\n\nI'm going to sort this array now using selection sort method, and I'm determined to make it work!");

    for(int i=0; i<10; i++){
        int min = i;
        for(int j=i+1; j<10; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    printf("\n\nHallelujah! The array has been successfully sorted with the following result: ");

    for(int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}