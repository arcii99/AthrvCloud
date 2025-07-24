//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int i = 0;
    int *ptr;
    while (1) {
        i++;
        ptr = (int*)malloc(sizeof(int)*i*10);
        if (ptr == NULL) {
            printf("Oops! Not enough memory.\n");
            break;
        } else {
            printf("Allocated %d0 bytes of memory.\n", i);
            printf("Current C RAM Usage: %d0 bytes.\n", i*10);
            free(ptr);
            sleep(1);
        }
    }
    printf("Terminating program...\n");
    exit(0);
}