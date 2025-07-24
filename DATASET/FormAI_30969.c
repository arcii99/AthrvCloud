//FormAI DATASET v1.0 Category: Log analysis ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <log file>\n", argv[0]);
        exit(1);
    }

    FILE *logFile = fopen(argv[1], "r");
    if(logFile == NULL) {
        perror("Error opening log file");
        exit(1);
    }

    int lineCount = 0;
    char line[256];

    while(fgets(line, sizeof(line), logFile)) {
        lineCount++;

        // Check if line contains malicious code
        if(strstr(line, "rm -rf /")) {
            printf("Malicious code found on line %d: %s\n", lineCount, line);
            printf("You are at risk of losing all your files. Please take action immediately.\n");
            exit(1);
        }

        // Check if line contains strange IP address
        char *ip = strtok(line, " ");
        if(ip != NULL) {
            char *dot;
            int count = 0;
            while((dot = strchr(ip, '.')) != NULL) {
                count++;
                ip = dot + 1;
            }
            if(count != 3) {
                printf("Strange IP address found on line %d: %s\n", lineCount, line);
                printf("This may indicate a security breach. Please investigate immediately.\n");
            }
        }

        // Check if line contains suspicious login attempt
        if(strstr(line, "Invalid user")) {
            char *user = strstr(line, "Invalid user") + strlen("Invalid user");
            char *from = strstr(line, " from ") + strlen(" from ");
            char *end = strchr(from, ' ');
            if(user != NULL && from != NULL && end != NULL) {
                char original = *end;
                *end = '\0';
                printf("Suspicious login attempt found on line %d: %s\n", lineCount, line);
                printf("User '%s' attempted to log in from '%s'\n", user, from);
                printf("This may indicate an attempt at unauthorized access. Please investigate immediately.\n");
                *end = original;
            }
        }
    }

    printf("Log analysis complete. No malicious activity found.\n");

    return 0;
}