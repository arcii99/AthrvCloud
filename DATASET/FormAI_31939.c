//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/sysinfo.h>

int main() {

    int i;
    struct sysinfo memInfo;
    int totalMem, freeMem, usedMem;

    // Set the memory usage alarm limit to 90%
    float alarmLimit = 0.9;

    printf("Starting C RAM usage monitor...\n\n");

    // Loop forever
    while (1) {

        // Get memory information
        sysinfo(&memInfo);
        totalMem = memInfo.totalram / 1024;
        freeMem = memInfo.freeram / 1024;
        usedMem = totalMem - freeMem;

        // Print memory usage information
        printf("Total memory: %d KB\n", totalMem);
        printf("Free memory: %d KB\n", freeMem);
        printf("Used memory: %d KB\n", usedMem);

        // Check if memory usage is above alarm limit
        if (((float)usedMem / (float)totalMem) > alarmLimit) {
            printf("\nALERT: Memory usage above %d%%\n", (int)(alarmLimit * 100));
            // Take appropriate action here
        }

        // Wait for 1 second before checking again
        sleep(1);

        // Clear the console to keep the output clean
        system("clear");

    }

    // We never actually reach this point, but it's good practice to have a return statement
    return 0;

}