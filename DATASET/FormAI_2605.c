//FormAI DATASET v1.0 Category: Sorting ; Style: enthusiastic
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

void bubbleSort(int arr[], int n) 
{ 
   int i, j, temp; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already sorted 
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              { 
                temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 
              } 
} 


int main() 
{ 
    int arr[100], n, i,j; 
    
    printf("Enter number of elements: "); 
    scanf("%d", &n); 

    srand(time(NULL)); //setting seed for random number generator

    for(i=0;i<n;i++) 
        arr[i] = rand() % 1000 + 1; // assigning random numbers between 1 and 1000

    printf("\nUnsorted Array: "); 
    for(i=0;i<n;i++) 
        printf("%d ",arr[i]); 

    bubbleSort(arr,n); 

    printf("\n\nSorted Array: "); 
    for(j=0;j<n;j++) 
        printf("%d ",arr[j]); 
    
    return 0; 
}