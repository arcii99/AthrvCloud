//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[100];
    char password[] = "password123";
    int attempts = 0;
    int detected = 0;
    
    while(1) {
        printf("Please enter your password:\n");
        fgets(buffer, 100, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character

        if(strcmp(buffer, password) == 0) {
            printf("Welcome!\n");
            break;
        } else {
            printf("Incorrect password. Please try again.\n");
            attempts++;
        }
        
        // Check for detection
        if(attempts % 3 == 0) {
            printf("INTRUSION DETECTED\n");
            detected = 1;
            break;
        }
    }
    
    if(detected) {
        printf("Please contact your system administrator for assistance.\n");
        exit(1);
    }
    
    // Rest of program
    printf("You have access to the system.\n");
    return 0;
}