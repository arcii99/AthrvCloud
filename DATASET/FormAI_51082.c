//FormAI DATASET v1.0 Category: System event logger ; Style: mind-bending
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_LOGS 100
#define MAX_LINE_LENGTH 256

// Define struct for log data
typedef struct {
    time_t log_time;
    char log_level[10];
    char log_message[MAX_LINE_LENGTH];
} log_data;

// Define main function
int main() {
    // Declare variables
    log_data log_array[MAX_LOGS];
    int num_logs = 0;
    char user_input[MAX_LINE_LENGTH];
    char log_levels[][10] = {"INFO", "WARNING", "ERROR"};

    // Welcome message
    printf("Welcome to my C System Event Logger!\n");

    // Ask user for input
    while (num_logs < MAX_LOGS) {
        printf("Please enter your log message ('q' to quit): ");
        fgets(user_input, MAX_LINE_LENGTH, stdin);
        user_input[strcspn(user_input, "\n")] = '\0';

        // Check if user wants to quit
        if (strcmp(user_input, "q") == 0) {
            break;
        }

        // Generate random log level
        int rand_index = rand() % 3;
        char rand_level[10];
        strcpy(rand_level, log_levels[rand_index]);

        // Get current time
        time_t current_time;
        time(&current_time);

        // Create log data struct
        log_data current_log;
        current_log.log_time = current_time;
        strcpy(current_log.log_level, rand_level);
        strcpy(current_log.log_message, user_input);

        // Add log data to array
        log_array[num_logs] = current_log;

        // Increment num_logs
        num_logs++;

        // Print confirmation message
        printf("Log entry added!\n");
    }

    // Print all log entries
    printf("Here are all your log entries:\n");
    for (int i = 0; i < num_logs; i++) {
        log_data current_log = log_array[i];
        printf("%s %s: %s\n", asctime(localtime(&current_log.log_time)), current_log.log_level, current_log.log_message);
    }

    // Exit program
    return 0;
}