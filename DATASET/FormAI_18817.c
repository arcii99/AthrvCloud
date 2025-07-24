//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: standalone
#include<stdio.h>

void main() {
    int ram; // Variable to store RAM usage.
    int threshold = 80; // Set the threshold for warning when usage exceeds 80%.
    char* warning = "WARNING: RAM usage is above 80%!";
    while(1) { // Loop infinitely to keep monitoring RAM usage.
        FILE* meminfo = fopen("/proc/meminfo", "r"); // Open the memory info file for reading.
        if(meminfo == NULL) { // Check if file opened successfully.
            perror("Failed to open meminfo file");
            return;
        }
        char line[256]; // Create a buffer to read each line from the file.
        while(fgets(line, sizeof(line), meminfo)) { // Loop through each line of the file.
            if(sscanf(line, "MemAvailable: %d", &ram) == 1) { // Extract the RAM usage from the line containing "MemAvailable".
                int usage_percent = (1.0 - (ram/64000.0)) * 100; // Calculate the percentage of RAM used.
                printf("Current RAM Usage: %d%%\n", usage_percent); // Display the current RAM usage.
                if(usage_percent > threshold) { // Check if RAM usage exceeds the threshold.
                    printf("%s\n", warning); // Display the warning message.
                }
                break; // Break the inner loop to avoid unnecessary iterations.
            }
        }
        fclose(meminfo); // Close the file.
        sleep(5); // Wait for 5 seconds before checking RAM usage again.
    }
}