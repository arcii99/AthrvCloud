//FormAI DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h> 

int main() { 
    //create an integer pointer variable 
    int* ptr; 
  
    //allocate memory using malloc() function 
    ptr = (int*) malloc(10 * sizeof(int)); 
  
    //check if memory was successfully allocated 
    if (ptr == NULL) { 
        printf("Memory allocation failed\n"); 
        return 0; 
    } 
  
    //use the allocated memory 
    for (int i = 0; i < 10; i++) { 
        *(ptr + i) = i + 1; //assign values to allocated memory 
        printf("%d ", *(ptr + i)); //print values of allocated memory 
    } 
  
    //deallocate the memory using free() function 
    free(ptr); 
    printf("\nMemory deallocated successfully!\n"); 
  
    return 0; 
}