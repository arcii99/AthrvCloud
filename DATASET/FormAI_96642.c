//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include<stdio.h>

int main(){
    while (1) {
        FILE *filePointer;
        char data[100];
        int memory;

        // Open the file in read-only mode
        filePointer = fopen("/proc/meminfo", "r");

        // Read the contents from the file
        while(fgets(data, 100, filePointer)) {

            // Parse the line that holds the total memory
            if (sscanf(data, "MemTotal: %d", &memory) == 1) {
                break;
            }
        }

        // Calculate the RAM usage percentage
        int usage = 100 - ((memory / 1024) * 100) / 8192;

        printf("RAM usage: %d%%\n", usage);

        // Close the file
        fclose(filePointer);

        // Wait for 1 second
        sleep(1);
    }
    return 0;
}