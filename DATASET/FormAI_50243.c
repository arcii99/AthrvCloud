//FormAI DATASET v1.0 Category: Memory management ; Style: dynamic
#include <stdio.h>  
#include <stdlib.h>  
  
int main()  
{  
    //declare variables  
    int *arr;  
    int size, i;  
    int sum = 0;  
  
    // Get the size of the array  
    printf("Enter the size of the array:\n");  
    scanf("%d",&size);  
  
    // allocate memory for the array  
    arr = (int*)malloc(size * sizeof(int));  
      
    // Check if memory allocation was successful  
    if(arr == NULL)  
    {  
        printf("Memory allocation failed.\n");  
        exit(1);  
    }  
    
    //Get elements of the array from the user  
    printf("Enter %d elements of the array:\n", size);
    for(i=0; i<size; i++)  
    {    
       scanf("%d", &arr[i]);  
    }  
      
    //Display the elements of the array  
    printf("The elements of the array are:\n");  
    for(i=0; i<size; i++)  
    {  
       printf("%d ",arr[i]);  
       sum += arr[i];
    }
    printf("\n");
    
    //Free the allocated memory  
    free(arr);  
    printf("Memory freed!\n");  
    
    return 0;  
}