//FormAI DATASET v1.0 Category: Log analysis ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Global variables
int security_level = 0;
int intrusion_level = 0;
char log_buffer[512];

// Constants
const char *SECURITY_LOG = "security.log";
const char *INTRUSION_LOG = "intrusion.log";

// Function prototypes
void log_security(char *message);
void log_intrusion(char *message);
int hack_system();
void initiate_security_protocol();
void increase_intrusion_level();

int main() {
    // Print intro message
    printf("Welcome to the C Log Analysis Program.\n");
    printf("Initializing system...\n");

    // Initiate security protocol
    initiate_security_protocol();

    // Begin log analysis loop
    while (intrusion_level < 10) {
        // Simulate a hack attempt
        if (hack_system() == 1) {
            char message[256];
            sprintf(message, "HACK ATTEMPT DETECTED: Intrusion level increased to %d", intrusion_level);
            log_security(message);
            increase_intrusion_level();
        }
        else {
            log_security("No hack attempts detected.");
        }

        // Wait for 5 seconds before checking again
        sleep(5);
    }

    // Write final message to security log
    log_security("SYSTEM SHUTDOWN: Maximum intrusion level reached");

    // Print outro message
    printf("System has been shut down. Goodbye!\n");

    return 0;
}

/**
 * Writes a message to the security log.
 * @param message: The message to write to the log.
 */
void log_security(char *message) {
    // Append timestamp to message
    time_t current_time = time(NULL);
    char formatted_time[20];
    strftime(formatted_time, 20, "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    // Write message to log
    sprintf(log_buffer, "[%s] [Security Level: %d] %s\n", formatted_time, security_level, message);

    // Open security log and write message
    FILE *security_log = fopen(SECURITY_LOG, "a");
    if (security_log != NULL) {
        fprintf(security_log, "%s", log_buffer);
        fclose(security_log);
    }
}

/**
 * Writes a message to the intrusion log.
 * @param message: The message to write to the log.
 */
void log_intrusion(char *message) {
    // Append timestamp to message
    time_t current_time = time(NULL);
    char formatted_time[20];
    strftime(formatted_time, 20, "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    // Write message to log
    sprintf(log_buffer, "[%s] [Intrusion Level: %d] %s\n", formatted_time, intrusion_level, message);

    // Open intrusion log and write message
    FILE *intrusion_log = fopen(INTRUSION_LOG, "a");
    if (intrusion_log != NULL) {
        fprintf(intrusion_log, "%s", log_buffer);
        fclose(intrusion_log);
    }
}

/**
 * Simulates a hack attempt.
 * @return: 1 if a hack attempt was successful, 0 otherwise.
 */
int hack_system() {
    int success_chance = 50 + intrusion_level * 10;
    int hack_successful = (rand() % 100) < success_chance;

    if (hack_successful) {
        char message[256];
        sprintf(message, "Hack attempt successful. Intrusion level increased to %d", intrusion_level + 1);
        log_intrusion(message);
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * Initiates the security protocol and sets the security level.
 */
void initiate_security_protocol() {
    // Set a random security level between 0 and 5
    security_level = rand() % 6;

    char message[256];
    sprintf(message, "Security protocol initiated. Security level set to %d", security_level);
    log_security(message);
}

/**
 * Increases the intrusion level by 1 and logs the message.
 */
void increase_intrusion_level() {
    intrusion_level++;
    char message[256];
    sprintf(message, "Intrusion level increased to %d", intrusion_level);
    log_intrusion(message);
}