//FormAI DATASET v1.0 Category: System administration ; Style: artistic
/*
 * Program Name: The Artistic System Administrator
 * Programmer: [Your Name]
 * Purpose: A creative program that simulates the tasks of a system administrator.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
struct User {
    char username[20];
    char password[20];
    int isAdmin;
};

struct Process {
    int pid;
    char name[50];
    int ownerID;
    int priority;
};

struct DiskDrive {
    char name[50];
    int sizeInGB;
    char fileSystem[50];
};


// Function prototypes
void welcomeMessage();
void printMenu();
int authenticateUser(struct User *users, int numOfUsers);
void viewProcesses(struct Process *processes, int numOfProcesses);
void viewDiskDrives(struct DiskDrive *diskDrives, int numOfDrives);
void exitProgram();


// Main function
int main() {
    // Declare variables
    int numOfUsers = 2, numOfProcesses = 4, numOfDrives = 3;
    struct User users[numOfUsers];
    struct Process processes[numOfProcesses];
    struct DiskDrive diskDrives[numOfDrives];
    int loggedInUser, choice;

    // Initialize users
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "password");
    users[0].isAdmin = 1;

    strcpy(users[1].username, "user");
    strcpy(users[1].password, "password");
    users[1].isAdmin = 0;

    // Initialize processes
    processes[0].pid = 1000;
    strcpy(processes[0].name, "Chrome");
    processes[0].ownerID = 1; // User
    processes[0].priority = 10;

    processes[1].pid = 1001;
    strcpy(processes[1].name, "Notepad");
    processes[1].ownerID = 1; // User
    processes[1].priority = 5;

    processes[2].pid = 1002;
    strcpy(processes[2].name, "Task Manager");
    processes[2].ownerID = 0; // Admin
    processes[2].priority = 8;

    processes[3].pid = 1003;
    strcpy(processes[3].name, "Calculator");
    processes[3].ownerID = 1; // User
    processes[3].priority = 3;

    // Initialize disk drives
    strcpy(diskDrives[0].name, "C:");
    diskDrives[0].sizeInGB = 50;
    strcpy(diskDrives[0].fileSystem, "NTFS");

    strcpy(diskDrives[1].name, "D:");
    diskDrives[1].sizeInGB = 100;
    strcpy(diskDrives[1].fileSystem, "FAT32");

    strcpy(diskDrives[2].name, "E:");
    diskDrives[2].sizeInGB = 200;
    strcpy(diskDrives[2].fileSystem, "exFAT");
    
    // Display welcome message
    welcomeMessage();

    // Authenticate user
    loggedInUser = authenticateUser(users, numOfUsers);

    // Display menu and perform tasks
    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n-- Viewing Processes --\n");
                viewProcesses(processes, numOfProcesses);
                break;
            case 2:
                printf("\n-- Viewing Disk Drives --\n");
                viewDiskDrives(diskDrives, numOfDrives);
                break;
            case 3:
                printf("\n-- Logging Out --\n");
                loggedInUser = authenticateUser(users, numOfUsers);
                break;
            case 4:
                printf("\n-- Exiting Program --\n");
                exitProgram();
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}


// Function definitions
void welcomeMessage() {
    printf("============================================\n");
    printf("||                                        ||\n");
    printf("|| Welcome to The Artistic Sys Admin v1.0! ||\n");
    printf("||                                        ||\n");
    printf("============================================\n\n");
}

void printMenu() {
    printf("\n-- Main Menu --\n");
    printf("1. View Processes\n");
    printf("2. View Disk Drives\n");
    printf("3. Log Out\n");
    printf("4. Exit Program\n");
    printf("Enter your choice: ");
}

int authenticateUser(struct User *users, int numOfUsers) {
    char username[20], password[20];
    int i;

    printf("\n-- Log In --\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    for (i = 0; i < numOfUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("\nWelcome, %s!\n", username);
            return i;
        }
    }

    printf("\nInvalid username or password.\n");
    return -1;
}

void viewProcesses(struct Process *processes, int numOfProcesses) {
    int i;

    printf("\n%-10s %-20s %-15s %-10s\n", "PID", "Name", "Owner ID", "Priority");

    for (i = 0; i < numOfProcesses; i++) {
        printf("%-10d %-20s %-15d %-10d\n", processes[i].pid, processes[i].name, processes[i].ownerID, processes[i].priority);
    }

    printf("\n");
}

void viewDiskDrives(struct DiskDrive *diskDrives, int numOfDrives) {
    int i;

    printf("\n%-10s %-15s %-20s\n", "Drive", "Size (GB)", "File System");

    for (i = 0; i < numOfDrives; i++) {
        printf("%-10s %-15d %-20s\n", diskDrives[i].name, diskDrives[i].sizeInGB, diskDrives[i].fileSystem);
    }

    printf("\n");
}

void exitProgram() {
    printf("Thank you for using The Artistic Sys Admin v1.0!\n");
    exit(0);
}