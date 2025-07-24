//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

char buffer[BUFFER_SIZE];

int main() {
    int count = 0;
    printf("Welcome to the Intrusion Detection System!\n");
    printf("Please enter the password to access the system: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    
    // Check if password is correct
    if(strcmp(buffer, "password\n") == 0) {
        printf("Access granted.\n");
        
        // Begin monitoring activity
        while(1) {
            printf("Enter command: ");
            fgets(buffer, BUFFER_SIZE, stdin);
            
            // Check for suspicious activity
            if(strstr(buffer, "rm") != NULL || strstr(buffer, "sudo") != NULL) {
                printf("INTRUSION DETECTED! Terminating program.\n");
                exit(0);
            }
            
            // Count number of valid commands entered
            count++;
            if(count % 10 == 0) {
                printf("Warning: %d commands have been entered.\n", count);
            }
        }
    } else {
        printf("Access denied.\n");
        exit(0);
    }
    return 0;
}