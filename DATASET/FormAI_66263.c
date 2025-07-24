//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: realistic
#include <stdio.h>
#include <string.h>

#define MAX_LOGINS 3

int main() {
    char username[20];
    char password[20];
    int login_attempts = 0;

    while (login_attempts < MAX_LOGINS) {
        printf("Username: ");
        scanf("%s", username);

        printf("Password: ");
        scanf("%s", password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
            printf("Login successful!\n");
            break;
        }
        else {
            printf("Invalid username or password. Please try again.\n");
            login_attempts++;
        }
    }

    if (login_attempts == MAX_LOGINS) {
        printf("Maximum login attempts reached. Logging out.\n");

        // Log intrusion attempt
        FILE *log_file = fopen("intrusion_log.txt", "a");

        if (log_file == NULL) {
            printf("Error opening log file.\n");
            return 1;
        }

        fprintf(log_file, "Intrusion attempt detected: %s\n", username);
        fclose(log_file);
    }

    return 0;
}