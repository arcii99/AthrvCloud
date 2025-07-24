//FormAI DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* ptr;
    int* ptr2;
    
    printf("Welcome to my memory management program!\n");
    printf("First, I will allocate memory for a single integer using malloc.\n");
    
    ptr = (int*)malloc(sizeof(int));
    
    if (ptr == NULL) {
        printf("Sorry, unable to allocate memory.\n");
    }
    else {
        printf("Memory allocation successful!\n");
        printf("Next, I will store the value 10 in the allocated memory.\n");
        
        *ptr = 10;
        printf("The value stored in the allocated memory is: %d \n", *ptr);
        
        printf("Now, I will free the allocated memory.\n");
        free(ptr);
        printf("Memory freed successfully!\n");
    }
    
    printf("Next, I will allocate memory for an array of integers using calloc.\n");
    printf("The array will have 3 elements.\n");
    
    ptr2 = (int*)calloc(3, sizeof(int));
    
    if (ptr2 == NULL) {
        printf("Sorry, unable to allocate memory.\n");
    }
    else {
        printf("Memory allocation successful!\n");
        printf("Next, I will store values in the allocated memory.\n");
        
        ptr2[0] = 1;
        ptr2[1] = 2;
        ptr2[2] = 3;
        
        printf("The values stored in the allocated memory are: %d, %d, %d \n", ptr2[0], ptr2[1], ptr2[2]);
        
        printf("Now, I will reallocate the memory for the array using realloc.\n");
        ptr2 = (int*)realloc(ptr2, 5*sizeof(int));
        
        if (ptr2 == NULL) {
            printf("Sorry, unable to reallocate memory.\n");
        }
        else {
            printf("Memory reallocation successful!\n");
            printf("Next, I will store more values in the reallocated memory.\n");
            
            ptr2[3] = 4;
            ptr2[4] = 5;
            
            printf("The values stored in the allocated memory are: %d, %d, %d, %d, %d \n", ptr2[0], ptr2[1], ptr2[2],
                   ptr2[3], ptr2[4]);
            
            printf("Now, I will free the reallocated memory.\n");
            free(ptr2);
            printf("Memory freed successfully!\n");
        }
    }
    
    printf("Thank you for using my memory management program!\n");
    
    return 0;
}