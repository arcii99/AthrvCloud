//FormAI DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main(){
    int* ptr = (int*)malloc(sizeof(int)*5); // allocate memory for 5 integers
    if(ptr == NULL) // check if the memory allocation was successful
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        printf("Memory allocation successful\n");
        
        // store values in the allocated memory
        *(ptr+0) = 10;
        *(ptr+1) = 20;
        *(ptr+2) = 30;
        *(ptr+3) = 40;
        *(ptr+4) = 50;
        
         // print the values stored in the allocated memory
        printf("Printing values stored in the allocated memory:\n");
        for(int i=0; i<5; i++){
            printf("%d\n", *(ptr+i));
        }
        
        // reallocate memory for 10 integers
        int* new_ptr = (int*)realloc(ptr, sizeof(int)*10);
        
        if(new_ptr == NULL) // check if reallocation was successful
        {
            printf("Memory reallocation failed\n");
        }
        else
        {
            printf("Memory reallocation successful\n");
            ptr = new_ptr;
            
            // store new values in the reallocated memory
            *(ptr+5) = 60;
            *(ptr+6) = 70;
            *(ptr+7) = 80;
            *(ptr+8) = 90;
            *(ptr+9) = 100;
            
            // print the values stored in the reallocated memory
            printf("Printing values stored in the reallocated memory:\n");
            for(int i=0; i<10; i++){
                printf("%d\n", *(ptr+i));
            }
        }
        
        // freeing the allocated memory
        free(ptr);
    }
    return 0;
}