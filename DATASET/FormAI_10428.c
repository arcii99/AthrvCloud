//FormAI DATASET v1.0 Category: System event logger ; Style: happy
// Happy C System Event Logger Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome Message
    printf("Welcome to the C System Event Logger!!\n");

    // Time variables
    time_t current_time;
    char* c_time_string;

    // File pointer
    FILE *fp;

    // Open file
    fp = fopen("system_event.log", "w");

    // Log startup event
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    fprintf(fp, "%s: System Startup\n", c_time_string);

    // Random system events
    char events[][100] = {
        "System Update Applied",
        "New User Account Created",
        "File System Changes Detected",
        "Security Breach Detected",
        "Critical Error Resolved",
        "New Software Installed",
        "Hard Drive Space Running Low",
        "Memory Leaks Detected"
    };

    int i;
    for (i = 0; i < 5; i++) {
        // Generate random event
        int rand_index = rand() % 8;
        char* event_name = events[rand_index];

        // Log event
        current_time = time(NULL);
        c_time_string = ctime(&current_time);
        fprintf(fp, "%s: %s\n", c_time_string, event_name);
    }

    // Log shutdown event
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    fprintf(fp, "%s: System Shutdown\n", c_time_string);

    // Close file
    fclose(fp);

    // Goodbye Message
    printf("System event logging complete. Goodbye!!\n");

    return 0;
}