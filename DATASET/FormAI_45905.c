//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: mind-bending
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

    int count = 0;
    int* ptr;
    int* prev_ptr = NULL;

    while(1){
        ptr = malloc(1000 * sizeof(int)); // allocate memory in chunks of 1000 ints
        
        if(ptr == NULL){
            printf("Error: Out of memory!\n"); // handle out of memory error
            exit(EXIT_FAILURE);
        }
        
        if(prev_ptr != NULL){ // print RAM usage stats
            printf("RAM usage for chunk %d: %d bytes\n", count, (ptr - prev_ptr) * sizeof(int));
        }
        
        prev_ptr = ptr;
        count++;
        sleep(1); // wait for 1 second before allocating more memory
    }

    return 0;
}