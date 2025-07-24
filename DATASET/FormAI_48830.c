//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ATTEMPTS 3     // Maximum login attempts allowed
#define MAX_HISTORY 10     // Maximum history entries to store

struct Login_History {
    char timestamp[20];
    char ip_address[15];
};

int main() {
    char username[20];
    char password[20];
    char current_ip[15];

    int login_attempts = 0;
    bool is_login_successful = false;

    struct Login_History history[MAX_HISTORY];
    int history_index = 0;

    while (login_attempts < MAX_ATTEMPTS) {
        printf("Please enter your username: ");
        scanf("%s", username);

        printf("Please enter your password: ");
        scanf("%s", password);

        // Check for successful login
        if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
            printf("Login successful!\n");
            is_login_successful = true;
            break;
        } else {
            printf("Invalid username or password. Please try again.\n");
            login_attempts++;

            // Check if maximum login attempts have been reached
            if (login_attempts == MAX_ATTEMPTS) {
                printf("Maximum login attempts reached. Exiting program.\n");
                break;
            }
        }
    }

    // If login was successful, log history
    if (is_login_successful) {
        printf("Please enter the current IP address: ");
        scanf("%s", current_ip);

        // Log history entry
        struct Login_History entry;
        time_t now = time(NULL);
        strftime(entry.timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
        strcpy(entry.ip_address, current_ip);

        history[history_index] = entry;
        history_index++;

        // Print login history
        printf("Login history:\n");
        for (int i = 0; i < history_index; i++) {
            printf("%s -- %s\n", history[i].timestamp, history[i].ip_address);
        }
    }

    return 0;
}