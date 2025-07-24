//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// function to get the current RAM usage
int getRAMUsage() {
    FILE *fp = fopen("/proc/meminfo", "r");
    char line[256];
    int ramUsage = 0;
    
    while(fgets(line, 256, fp)) {
        if(strncmp(line, "MemFree:", 8) == 0) {
            sscanf(line + 8, "%d", &ramUsage);
            break;
        }
    }

    fclose(fp);
    return ramUsage;
}

int main() {
    int ramUsage = 0;
    int maxRAMUsage = 0;

    printf("Welcome to the C RAM Usage Monitor!\n");
    printf("Monitoring your RAM usage now...\n\n");

    while(1) {
        ramUsage = getRAMUsage();
        if(ramUsage > maxRAMUsage)
            maxRAMUsage = ramUsage;

        printf("Current RAM usage: %d kB\n", ramUsage);
        printf("Max RAM usage so far: %d kB\n", maxRAMUsage);

        // just for fun, let's add some sleep time to make the program slower
        sleep(2);
    }

    // this code will never run, as the while loop will never exit
    return 0;
}