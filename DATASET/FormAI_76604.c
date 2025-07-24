//FormAI DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *memory = (char*)malloc(100*sizeof(char));
    printf("Starting memory:\n%s\n", memory);
    
    printf("\nWriting code...\n");
    for(int i=0; i<10; i++) {
        memory[i] = 'C';
    }
    printf("Code written:\n%s\n", memory);

    int current_size = sizeof(memory)/sizeof(char);
    printf("\nCurrent memory size: %d bytes\n", current_size);

    printf("\nFilling up memory with nonsense...\n");
    for(int i=10; i<100; i++) {
        memory[i] = 'G';
    }
    printf("Memory now full of nonsense:\n%s\n", memory);

    printf("\nOops, running out of space. Let's reallocate memory.\n");
    char *new_memory = realloc(memory, 150*sizeof(char));
    if(new_memory != NULL) {
        memory = new_memory;
    }
    printf("Memory successfully reallocated.\n");

    printf("\nWriting more code...\n");
    for(int i=10; i<20; i++) {
        memory[i] = 'A';
    }
    printf("More code written:\n%s\n", memory);

    current_size = sizeof(memory)/sizeof(char);
    printf("\nCurrent memory size: %d bytes\n", current_size);

    printf("\nNow let's free up some memory.\n");
    free(memory);
    printf("Memory freed successfully.\n");

    printf("\nProgram complete. Goodbye!\n");

    return 0;
}