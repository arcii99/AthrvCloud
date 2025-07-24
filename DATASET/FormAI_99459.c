//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {

    int memory = 0;
    int *ptr = NULL;
    
    while(1) {
        ptr = malloc(sizeof(int)); // allocate memory
       
        if(ptr == NULL) { // out of memory
            printf("RAM USAGE MONITOR: You have used up all the available RAM.\n");
            printf("Please free up some memory and restart the program.\n");
            exit(0); // terminate program
        }
        
        memory += sizeof(int); // increment memory usage
        printf("RAM USAGE MONITOR: Current memory usage is %d bytes.\n", memory);
        free(ptr); // deallocate memory
    }
    return 0;
}