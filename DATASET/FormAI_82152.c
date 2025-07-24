//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to get the current C RAM usage
double getCurrentRAMUsage() {
    FILE* file = fopen("/proc/self/status", "r");
    double result = -1.0;
    char line[128];

    while (fgets(line, 128, file) != NULL) {
        if (strncmp(line, "VmRSS:", 6) == 0) {
            result = atof(line + 6);
            break;
        }
    }
    fclose(file);
    return result;
}

// Function to print the futuristic style output
void printRAMUsage(double currentUsage) {
    printf("\033[0;36m"); // Set output color to cyan
    printf("---------------------------------\n");
    printf("|    C RAM Usage Monitor v1.0   |\n");
    printf("---------------------------------\n");
    printf("| Current Usage: %8.2f MB     |\n", currentUsage);
    printf("---------------------------------\n");
    printf("\033[0m"); // Reset output color to default
}

int main() {
    double currentUsage;

    while(1) {
        currentUsage = getCurrentRAMUsage() / 1024.0; // Convert to MB
        printRAMUsage(currentUsage);
        sleep(1); // Sleep for 1 second
        system("clear"); // Clear console output
    }

    return 0;
}