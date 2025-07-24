//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Starting C RAM usage monitor...\n");
    printf("Press Ctrl-C to exit.\n\n");

    long cur_mem, max_mem = 0;
    int count = 0;

    while(1) {
        cur_mem = (long)sbrk(0); // get current memory usage
        if(cur_mem == -1) { // check for error
            printf("Error getting memory usage.\n");
            exit(1);
        }

        if(cur_mem > max_mem) max_mem = cur_mem; // update max memory usage

        if(++count % 100 == 0) { // print memory usage every 100 cycles
            printf("Current memory usage: %ld bytes\n", cur_mem);
            printf("Max memory usage: %ld bytes\n\n", max_mem);
        }

        usleep(10000); // wait for 10 milliseconds before checking again
    }

    return 0;
}