//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

void logEvent(char *username, char *password, char *eventName);

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Username: ");
    scanf("%s", username);
    
    printf("Password: ");
    scanf("%s", password);
    
    if (strcmp(username, "root") == 0 && strcmp(password, "secret") == 0) {
        printf("Access granted.\n");
        logEvent(username, password, "successful login");
    } else {
        printf("Access denied.\n");
        logEvent(username, password, "failed login");
    }
    
    return 0;
}

void logEvent(char *username, char *password, char *eventName) {
    char command[100];
    
    snprintf(command, sizeof(command), "echo 'Username: %s\nPassword: %s\nEvent: %s' >> /var/log/system.log", username, password, eventName);
    
    system(command);
}