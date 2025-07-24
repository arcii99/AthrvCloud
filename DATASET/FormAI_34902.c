//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MB 1024 * 1024

int main() {
    int i;
    for(i=1; i<=10; i++){
        sleep(1);
        int *ptr = (int*) malloc(25 * MB);

        if(ptr == NULL){
            printf("Memory allocation failed on iteration %d \n", i);
            exit(1);
        }
        else
            printf("Allocated 25 MB of memory on iteration %d \n", i);

        free(ptr);
        printf("Freed memory on iteration %d \n", i);
    }

    return 0;
}