//FormAI DATASET v1.0 Category: System boot optimizer ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void print_menu() {
    printf("Welcome to C System Boot Optimizer\n");
    printf("1. Remove unused services\n");
    printf("2. Defragment the disk\n");
    printf("3. Update system drivers\n");
    printf("4. Shutdown the computer\n");
    printf("Enter your choice: ");
}

bool is_valid_choice(int choice) {
    return choice >= 1 && choice <= 4;
}

void remove_unused_services() {
    // Code to remove unused services goes here
    printf("Unused services have been removed from the system.\n");
}

void defragment_disk() {
    // Code to defragment the disk goes here
    printf("The disk has been defragmented successfully.\n");
}

void update_system_drivers() {
    // Code to update system drivers goes here
    printf("System drivers have been updated.\n");
}

void shutdown_computer() {
    // Code to shutdown the computer goes here
    printf("The computer will now shutdown.\n");
    exit(0);
}

int main() {
    int choice;
    char command[MAX_COMMAND_LENGTH];
    bool running = true;
    
    while (running) {
        print_menu();
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        choice = atoi(command);
        
        if (!is_valid_choice(choice)) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        
        switch (choice) {
            case 1:
                remove_unused_services();
                break;
            case 2:
                defragment_disk();
                break;
            case 3:
                update_system_drivers();
                break;
            case 4:
                shutdown_computer();
                break;
        }
    }
    
    return 0;
}