//FormAI DATASET v1.0 Category: System administration ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char command[100] = "";
    printf("Welcome to the System Administration program!\n");

    while(1) {
        printf("\nPlease enter a command: ");
        fgets(command, 100, stdin);
        command[strcspn(command, "\r\n")] = 0; // remove newline character
        
        if(strcmp(command, "shutdown") == 0) {
            printf("Are you sure you want to shut down the system? (y/n): ");
            char confirm;
            scanf("%c", &confirm);
            getchar(); // remove newline character
            
            if(confirm == 'y' || confirm == 'Y') {
                printf("Shutting down...\n");
                system("shutdown now");
                break;
            } else {
                printf("Aborting shutdown...\n");
            }

        } else {
            printf("Command not recognized. Please try again.\n");
        }
    }

    printf("Program has ended.\n");
    return 0;
}