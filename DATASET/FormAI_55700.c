//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int ramUsage = 0;
    printf("Checking RAM usage...\n");
    while(1) {
        // check RAM usage here and assign the value to ramUsage variable
        printf("\rRAM usage is: %d", ramUsage);
        fflush(stdout);
        sleep(5); // every 5 seconds, check the RAM usage again
    }
    return 0;
}