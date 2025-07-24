//FormAI DATASET v1.0 Category: Sorting ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

/*Satisfied C Sorting Example Program*/

int main(){
    int arr[100], n, i, j, temp;
    
    /*Take inputs*/
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    /*Print the unsorted array*/
    printf("\nUnsorted Array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    /*Sorting Algorithm*/
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                /*Swapping*/
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    /*Print the sorted array*/
    printf("\nSorted Array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}