//FormAI DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Let's allocate memory for an array of 100 integers
    int* ptr = (int*) malloc(100 * sizeof(int));
    
    // Check if memory allocation was successful
    if (ptr == NULL) {
        printf("Oops! Memory allocation failed.");
        exit(1);
    }
    
    // Let's assign some values to the array 
    for (int i = 0; i < 100; i++) {
        ptr[i] = i+1;
    }
    
    // Now let's deallocate the memory to free up space
    free(ptr);
    
    // Oops, we forgot to assign NULL to ptr after deallocating memory!
    // This can lead to runtime errors if ptr is accessed afterwards
    ptr = NULL;
    
    // Let's allocate some more memory for a new array of 50 floats
    float* ptr2 = (float*) calloc(50, sizeof(float));
    
    // Let's check if memory allocation was successful
    if (ptr2 == NULL) {
        printf("Oops! Memory allocation failed.");
        exit(1);
    }
    
    // Now let's assign some values to the new array 
    for (int i = 0; i < 50; i++) {
        ptr2[i] = (float) i/2;
    }
    
    // Let's print out the values of the new array 
    printf("New array values: ");
    for (int i = 0; i < 50; i++) {
        printf("%.2f ", ptr2[i]);
    }
    
    // Now we want to resize the new array to make it bigger
    // We will use realloc() for this
    
    // Let's allocate memory for a new array of 100 floats
    float* new_ptr2 = (float*) realloc(ptr2, 100 * sizeof(float));
    
    // Check if memory allocation was successful after resizing
    if (new_ptr2 == NULL) {
        printf("Oops! Memory allocation failed.");
        // No need to exit this time, since we have the original ptr2 to fall back on
    }
    
    // Let's assign some new values to the resized array
    for (int i = 50; i < 100; i++) {
        new_ptr2[i] = (float) (i+1)/2;
    }
    
    // Let's print out the values of the resized array
    printf("\nResized array values: ");
    for (int i = 0; i < 100; i++) {
        printf("%.2f ", new_ptr2[i]);
    }
    
    // Now let's deallocate the memory to free up space
    free(new_ptr2);
    
    // And finally, let's assign NULL to new_ptr2 to avoid runtime errors
    new_ptr2 = NULL;
    
    // Excitedly, we have successfully allocated and deallocated memory for two arrays, assigned values to them, resized one of them, and printed out their values! We are memory management champions!
    
    return 0;
}