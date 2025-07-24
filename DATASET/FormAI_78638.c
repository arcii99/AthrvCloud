//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[255];
    char password[10] = "password";
    int attempts = 0;
    int logged_in = 0;

    while(!logged_in && attempts < 3) {
        printf("Enter password: ");
        scanf("%s", buffer);

        if (strcmp(buffer, password) == 0) {
            printf("Successfully logged in!\n");
            logged_in = 1;
        } else {
            printf("Incorrect password. Try again.\n");
            attempts++;
        }
    }

    if (attempts == 3 && !logged_in) {
        printf("Maximum login attempts exceeded. Exiting.\n");
        return 0;
    }

    char command[255];
    while(logged_in) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strstr(command, "sudo") != NULL) {
            printf("Intrusion detected! Exiting.\n");
            return 0;
        } else {
            printf("Executing command...\n");
            // some code to execute the command
        }
    }

    return 0;
}