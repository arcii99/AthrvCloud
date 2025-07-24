//FormAI DATASET v1.0 Category: Sorting ; Style: peaceful
/* This is a peaceful sorting program, where each element is treated with love and kindness*/
#include <stdio.h>
#include <stdlib.h>

void peacefulSort(int arr[], int n) 
{ 
    int i, j, temp; 
    for (i = 0; i < n-1; i++) 
    { 
        // Inner loop to compare each element with the next one
        for (j = i+1; j < n; j++) 
        {   
           // If element at i is greater than element at j, swap them 
           if (arr[i] > arr[j]) 
           { 
               printf("Let's swap element %d and element %d with love and care.\n", arr[i], arr[j]);
               temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
               printf("Now the array looks like this: ");
               for(int index=0; index<n; index++){
                   printf("%d ",arr[index]);
               }
               printf("\n");
           } 
        } 
    } 
    printf("Sorting is now complete. Let's take a moment to appreciate each element in the array.\n"); 
}

int main() 
{ 
    int arr[] = { 10, 7, 9, 3, 5, 11, 18, 22, 16 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    printf("Welcome to the peaceful sorting program. Let's appreciate each element in the array before we begin:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\nNow, let's begin the sorting process with peace and tranquility.\n-----------------------------------------------------------\n");
    
    peacefulSort(arr, n); // Calling the sorting function
    
    printf("-----------------------------------------------------------\nSorting is now complete. Let's take a moment to appreciate the sorted array.\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\nThank you for using the peaceful sorting program. Have a wonderful day ahead!\n"); 
    
    return 0; 
}