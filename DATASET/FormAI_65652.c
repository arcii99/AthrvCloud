//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate RAM usage
void getRAMUsage() {
    FILE *fp;
    char path[100];
    char buffer[500];

    // Initialize path variable with command to get RAM usage
    strcpy(path, "free -m | grep Mem | awk '{print $4/$2 * 100.0}'");

    // Open the command for reading
    fp = popen(path, "r");

    // If command is successfully executed
    if (fp != NULL) {
        // Read the output from the command
        fgets(buffer, sizeof(buffer), fp);

        // Print the RAM usage percentage
        printf("RAM usage: %s%%\n", buffer);

        // Close the command
        pclose(fp);
    }
    else {
        // If command cannot be executed
        printf("Failed to get RAM usage\n");
        exit(1);
    }
}

// Main function to execute the program
int main() {
    printf("Welcome to RAM Usage Monitor\n");

    // Continuously get RAM usage at regular intervals
    while(1) {
        getRAMUsage();
        sleep(5); // Sleep for 5 seconds
    }

    return 0;
}