//FormAI DATASET v1.0 Category: System administration ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Welcome to the System Administration Example Program!\n");
    
    int choice;
    do {
        // Print Menu
        printf("\n\nPlease enter your choice:\n");
        printf("1. Check disk usage\n");
        printf("2. View system processes\n");
        printf("3. Kill a process\n");
        printf("4. Exit the program\n");
        printf("> ");
        scanf("%d", &choice);
        
        if (choice < 1 || choice > 4) {
            printf("Invalid choice, please try again.\n");
        } else {
            switch (choice) {
                case 1:
                    system("df -h");
                    break;
                case 2:
                    system("ps aux");
                    break;
                case 3:
                    int pid;
                    printf("Please enter the PID of the process to kill: ");
                    scanf("%d", &pid);
                    // Construct command string to kill process
                    char command[50];
                    sprintf(command, "kill %d", pid);
                    // Execute command in shell
                    system(command);
                    break;
                case 4:
                    printf("Exiting the program.\n");
                    break;
            }
        }
        sleep(1); // Wait for a second before printing menu again
    } while (choice != 4);
    
    return 0;
}