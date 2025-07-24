//FormAI DATASET v1.0 Category: Sorting ; Style: cheerful
// Welcome to the Sorting Funhouse!
// Let's sort some numbers with a smile :)
#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[10] = {5, 2, 8, 3, 9, 1, 0, 7, 4, 6};
    printf("Unsorted Array: ");
    for(int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Sorting using Bubble Sort
    for(int i=0; i<10; i++){
        for(int j=0; j<9-i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted Array: ");
    for(int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    printf("Thanks for sorting with me! See you again soon :)");
    return 0;
}