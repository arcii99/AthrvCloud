//FormAI DATASET v1.0 Category: System administration ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Hello and welcome to my unique C System Administration program!\n\n");

    char option[10];

    do {
        printf("Please select an option:\n");
        printf("1. Display System Information\n");
        printf("2. Check Disk Space\n");
        printf("3. Check Memory Usage\n");
        printf("4. Stop a Running Process\n");
        printf("5. Exit Program\n\n");

        printf("Enter your choice: ");
        fgets(option, 10, stdin);

        if (strcmp(option, "1\n") == 0) {
            system("uname -a"); // Display system information
        } else if (strcmp(option, "2\n") == 0) {
            system("df -h"); // Check disk space
        } else if (strcmp(option, "3\n") == 0) {
            system("free -m"); // Check memory usage
        } else if (strcmp(option, "4\n") == 0) {
            char pid[10];
            printf("Enter the process ID you want to stop: ");
            fgets(pid, 10, stdin);
            char command[20] = "kill ";
            strcat(command, pid);
            system(command); // Stop a running process
        } else if (strcmp(option, "5\n") == 0) {
            printf("Thank you for using this program!\n");
            exit(0); // Exit program
        } else {
            printf("Invalid option. Please try again.\n");
        }

    } while (strcmp(option, "5\n") != 0);

    return 0;
}