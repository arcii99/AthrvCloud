//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A simple Intrusion Detection System that monitors login attempts */

int main(void) {
    /* Define variables */
    int attempt_count = 0;
    char username[16], password[16];

    /* Start monitoring */
    while (1) {
        /* Get login information from user */
        printf("Enter your username: ");
        scanf("%15s", username);  /* Limit to 15 characters to prevent buffer overflow */
        
        printf("Enter your password: ");
        scanf("%15s", password);

        /* Check login information */
        if (strcmp(username, "admin") == 0 && strcmp(password, "p@ssw0rd") == 0) {
            /* Login successful */
            printf("Welcome, Admin!\n");
            break;
        } else {
            /* Login failed */
            printf("Invalid login attempt.\n");
            attempt_count++;
            
            /* Check for brute force attack */
            if (attempt_count >= 3) {
                printf("Possible brute force attack detected. Exiting program.\n");
                exit(0);
            }
        }
    }

    return 0;
}