//FormAI DATASET v1.0 Category: System administration ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to the most exciting System administration program!\n");
    printf("With this program, you can easily manage your system like never before.\n");
    
    // Code to get user input for system administration task
    char task[20];
    printf("\nEnter the task you want to perform: ");
    scanf("%s", task);
    
    // Code to perform system administration task
    if(strcmp(task, "reboot") == 0) {
        printf("\nYour system is now rebooting...");
        // Code to reboot system
    }
    else if(strcmp(task, "shutdown") == 0) {
        printf("\nYour system is now shutting down...");
        // Code to shutdown system
    }
    else if(strcmp(task, "status") == 0) {
        printf("\nHere's the status of your system:");
        // Code to display system status
    }
    else {
        printf("\nInvalid task entered. Please try again.");
    }

    printf("\nThank you for using our exciting System administration program! Goodbye!\n");
    return 0;
}