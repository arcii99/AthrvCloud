//FormAI DATASET v1.0 Category: Memory management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define KB 1024
#define MB (KB * KB)

int main() {

    int* intPtr = (int*) malloc(4 * sizeof(int));
    if(intPtr == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return 1;
    }
  
    for(int i = 0; i < 4; i++) {
        *(intPtr + i) = i;
    }
    
    printf("Memory allocated: %d bytes.\n", 4 * sizeof(int));
    printf("Values at allocated memory location:\n");
    for(int i = 0; i < 4; i++) {
        printf("%d ", *(intPtr + i));
    }
    printf("\n\n");

    int* newIntPtr = (int*) realloc(intPtr, 8 * sizeof(int));
    if(newIntPtr == NULL) {
        printf("Error: Failed to reallocate memory.\n");
        free(intPtr);
        return 1;
    }

    printf("Unused memory after resizing: %d bytes.\n", 4 * sizeof(int));
    printf("Memory allocated after resizing: %d bytes.\n", 8 * sizeof(int));
    
    for(int i = 4; i < 8; i++) {
        *(newIntPtr + i) = i;
    }
    
    printf("Values at resized memory location:\n");
    for(int i = 0; i < 8; i++) {
        printf("%d ", *(newIntPtr + i));
    }
    printf("\n\n");

    free(newIntPtr);

    unsigned char* charPtr1 = (unsigned char*) calloc(128, sizeof(unsigned char));
    if(charPtr1 == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return 1;
    }

    printf("Memory allocated by calloc: %d bytes.\n", 128 * sizeof(unsigned char));

    free(charPtr1);

    unsigned char* charPtr2 = (unsigned char*) malloc(512 * KB);
    if(charPtr2 == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return 1;
    }

    printf("Memory allocated: %d bytes.\n", 512 * KB);

    free(charPtr2);

    unsigned char* charPtr3 = (unsigned char*) malloc(1024 * MB);
    if(charPtr3 == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return 1;
    }

    printf("Memory allocated: %d bytes.\n", 1024 * MB);

    free(charPtr3);

    return 0;
}