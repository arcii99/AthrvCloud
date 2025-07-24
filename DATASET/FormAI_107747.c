//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: interoperable
#include<stdio.h>

int main() {
    char buffer[100];
    int login = 0; // To keep track of user login status

    // Infinite loop to simulate real-time monitoring
    while(1) {
        printf("Enter command: ");
        fgets(buffer, 100, stdin); // Take input from user
        
        // Check for possible intrusion commands
        if(strstr(buffer, "sudo")) {
            if(login == 0) {
                printf("\nUnauthorized access detected! Intrusion alert!\n");
                break; // Exit program in case of intrusion
            } else {
                printf("\nUser authenticated!\n");
            }
        }

        // Check for login command
        if(strstr(buffer, "login")) {
            login = 1; // Set login status to true
            printf("\nUser logged in!\n");
        }

        // Check for logout command
        if(strstr(buffer, "logout")) {
            login = 0; // Set login status to false
            printf("\nUser logged out!\n");
        }

    }

    return 0;
}