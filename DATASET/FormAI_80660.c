//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MB (1024*1024)
#define MAX_RAM 1024

int main(void)
{
    int ram_usage = 0;
    void *mem;

    while(1) {
        mem = malloc(MB);
        if(mem == NULL) {
            fprintf(stderr,"Out of memory!\n");
            exit(1);
        } else {
            ram_usage += 1;
            printf("Current RAM usage: %d MB\n", ram_usage);
        }

        if(ram_usage >= MAX_RAM) {
            printf("Max RAM reached, exiting...\n");
            free(mem);
            exit(0);
        }

        sleep(1);
    }

    return 0;
}