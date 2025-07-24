//FormAI DATASET v1.0 Category: Sorting ; Style: introspective
/* This program is designed to implement selection sort on an array */
#include<stdio.h> 

int main() 
{ 
    int i, j, n, temp; 
    int arr[] = {64, 25, 12, 22, 11}; 
    
    // print the array
    printf("Unsorted array: ");
    for(i=0; i<5; i++) 
        printf("%d ", arr[i]); 
        
    printf("\n\n");
    
    // selection sort algorithm
    for(i=0; i<5; i++) 
    { 
        for(j=i+1; j<5; j++) 
        { 
            if(arr[j]<arr[i]) 
            { 
                // swap two elements
                temp = arr[i]; 
                arr[i]=arr[j]; 
                arr[j]=temp; 
            } 
        } 
    } 
    
    // print the sorted array
    printf("Sorted array: ");
    for(i=0; i<5; i++) 
        printf("%d ", arr[i]); 
        
    return 0; 
}