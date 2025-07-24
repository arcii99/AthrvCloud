//FormAI DATASET v1.0 Category: System administration ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char option[100];

    printf("Welcome to the system administration program. Choose an option from the menu:\n");
    printf("1. Check system uptime\n");
    printf("2. Check disk usage\n");
    printf("3. Check memory usage\n");
    printf("4. Check network connections\n");
    printf("5. Exit program\n");

    while (1) {
        printf("\nEnter option number: ");
        fgets(option, 100, stdin);

        if (strcmp(option, "1\n") == 0) {
            system("uptime");
        }
        else if (strcmp(option, "2\n") == 0) {
            system("df -h");
        }
        else if (strcmp(option, "3\n") == 0) {
            system("free -h");
        }
        else if (strcmp(option, "4\n") == 0) {
            system("netstat -a");
        }
        else if (strcmp(option, "5\n") == 0) {
            printf("Exiting program...\n");
            break;
        }
        else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}