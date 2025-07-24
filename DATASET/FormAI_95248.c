//FormAI DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>

int main()
{   
    int* ptr; 
    ptr = (int*)malloc(5 * sizeof(int)); //allocate memory for 5 integers
    
    if(ptr == NULL) //if pointer is null, then allocation failed
    {
        printf("Memory allocation failed\n");
        return 0;
    }
    
    //assign values to the integers in the memory block
    ptr[0] = 5;
    ptr[1] = 10;
    ptr[2] = 15;
    ptr[3] = 20;
    ptr[4] = 25;
    
    printf("The values stored in the memory block are: \n");
    
    //print the values stored in the memory block using pointer arithmetic
    for(int i=0; i<5; i++)
    {
        printf("%d ", *(ptr+i));
    }
    
    printf("\n");
    
    //increase the size of the memory block using realloc
    ptr = (int*)realloc(ptr, 10 * sizeof(int));
    
    //if realloc fails, the original memory block is still accessible
    if(ptr == NULL)
    {
        printf("Memory reallocation failed\n");
    }
    else
    {
        //assign new values to the newly allocated memory block
        ptr[5] = 30;
        ptr[6] = 35;
        ptr[7] = 40;
        ptr[8] = 45;
        ptr[9] = 50;
        
        printf("The values stored in the expanded memory block are: \n");
        
        //print the values stored in the expanded memory block
        for(int i=0; i<10; i++)
        {
            printf("%d ", *(ptr+i));
        }
        
        printf("\n");
        
        //free the memory block when no longer needed
        free(ptr);
    }
    
    return 0;
}