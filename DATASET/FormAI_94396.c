//FormAI DATASET v1.0 Category: System administration ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to check if the user running the program is root
int check_root() {
    if (geteuid() != 0) {
        printf("This program must be run as root!\n");
        return 0;
    }
    return 1;
}

// Function to perform a reboot of the system
void reboot() {
    printf("Rebooting system...\n");
    system("reboot");
}

// Function to display the current system time
void show_time() {
    char buffer[80];
    time_t current_time = time(NULL);
    strftime(buffer, 80, "%c", localtime(&current_time));
    printf("The current time is %s.\n", buffer);
}

// Main function to display menu options
int main(void) {
    char selection;

    // Check if user is root
    if (!check_root()) {
        exit(1);
    }

    // Display menu
    printf("System Administration Menu\n");
    printf("----------------------------\n");
    printf("1. Reboot system\n");
    printf("2. Display current time\n");
    printf("Q. Quit program\n\n");

    // Get user selection
    printf("Please enter your selection: ");
    scanf("%c", &selection);

    // Perform action based on user selection
    switch (selection) {
        case '1':
            reboot();
            break;
        case '2':
            show_time();
            break;
        case 'Q':
            printf("Quitting program...\n");
            break;
        default:
            printf("Invalid selection.\n");
            break;
    }

    return 0;
}