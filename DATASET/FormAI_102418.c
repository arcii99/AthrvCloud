//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

    unsigned long int count = 0;

    // Allocate Memory
    char * mem;
    mem = (char*) malloc(1024*1024*10*sizeof(char));

    if (mem == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Monitor Memory Usage
    while(1) {
        sleep(1);
        count++;
        printf("Memory usage: %lu MB\n", count*10);
    }

    // Free Memory
    free(mem);
    return 0;
}