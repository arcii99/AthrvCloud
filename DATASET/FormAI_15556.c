//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RAM 4096 // Max RAM in MB

int main() {
    srand(time(NULL)); // Initialize random seed based on time
    int used_ram = 0; // Initialize used RAM to 0 MB
    int i, r;
    char c;

    printf("Monitoring RAM usage...\n");

    while(1) { // Infinite loop
        used_ram += (rand() % 10) + 1; // Randomly increase RAM usage by 1-10 MB
        if(used_ram > MAX_RAM) used_ram = MAX_RAM; // Cap RAM usage at max value
        printf("Used RAM: %d MB\n", used_ram);

        if(used_ram >= MAX_RAM) {
            printf("WARNING: RAM usage has exceeded maximum capacity!\n");
        }

        for(i = 0; i < used_ram * 1024; i++) { // Allocate memory proportional to used RAM
            r = rand();
            c = (char)r; // Store random ASCII character in memory location
        }

        for(i = 0; i < used_ram * 1024; i++) { // Free allocated memory
            r = rand();
            c = (char)r; // Retrieve random character from memory location
        }

        sleep(1); // Pause for 1 second
    }

    return 0;
}