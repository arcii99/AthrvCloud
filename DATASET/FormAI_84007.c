//FormAI DATASET v1.0 Category: System administration ; Style: excited
// Welcome to the coolest System Administration Example program ever created!
// With just a few simple commands, you can control your entire system like a boss!

#include <stdio.h> // standard input/output library
#include <stdlib.h> // standard library
#include <string.h> // string manipulation library
#include <unistd.h> // POSIX library
#include <fcntl.h> // file control library

int main() {

    char command[50]; // variable to store user input

    printf("Welcome to the coolest System Administration Example program ever created!\n");
    printf("With just a few simple commands, you can control your entire system like a boss!\n\n");

    while (1) { // infinite loop for continuous user input

        printf("Enter a command: "); // prompt user for input
        fgets(command, sizeof(command), stdin); // read user input

        if (strstr(command, "reboot")) { // check if command contains "reboot"
            printf("Rebooting system...\n");
            system("reboot");
        }

        else if (strstr(command, "shutdown")) { // check if command contains "shutdown"
            printf("Shutting down system...\n");
            system("shutdown now");
        }

        else if (strstr(command, "restart")) { // check if command contains "restart"
            printf("Restarting system...\n");
            system("service xrdp restart");
        }

        else if (strstr(command, "lock")) { // check if command contains "lock"
            printf("Locking screen...\n");
            system("gnome-screensaver-command -l");
        }

        else if (strstr(command, "list")) { // check if command contains "list"
            printf("List of all files and directories in current directory:\n");
            system("ls");
        }

        else if (strstr(command, "clear")) { // check if command contains "clear"
            printf("Clearing screen...\n");
            system("clear");
        }

        else if (strstr(command, "edit")) { // check if command contains "edit"
            char file[50];
            printf("Enter file name to edit: ");
            scanf("%s", file);
            printf("Opening %s for editing...\n", file);
            char path[100] = "/usr/bin/nano ";
            strcat(path, file);
            system(path);
        }

        else if (strstr(command, "exit")) { // check if command contains "exit"
            printf("Exiting program...\n");
            exit(0);
        }

        else { // if command is not recognized
            printf("Command not recognized. Please try again.\n");
        }

    }

    return 0;
}