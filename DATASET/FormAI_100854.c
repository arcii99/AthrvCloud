//FormAI DATASET v1.0 Category: Sorting ; Style: retro
#include <stdio.h>
#include <stdlib.h> 

void bubbleSort(int arr[], int n) // Bubble Sort function
{ 
   int i, j, temp; 
   for (i = 0; i < n-1; i++)     
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
   int arr[100], n, i; 
   printf("Enter number of elements to be sorted (less than 100): ");
   scanf("%d", &n); //User input for number of elements in the array
   printf("Enter the elements to be sorted: ");
   for(i=0;i<n;i++){
        scanf("%d", &arr[i]); //User input for elements of the array
   }
   bubbleSort(arr, n); //Calling Bubble Sort function to sort the elements of the array
   printf("Sorted Array: "); 
   for(i=0;i<n;i++){
        printf("%d ", arr[i]); //Outputting the sorted array
   }
   return 0; 
}