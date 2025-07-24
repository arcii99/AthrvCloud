//FormAI DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHeader(char* header) {
    printf("\n---------------- %s ----------------\n\n", header);
}

void printCommand(char* command) {
    printf("> %s\n", command);
}

void executeCommand(char* command) {
    printCommand(command);
    system(command);
}

void writeFile(char* filename, char* content) {
    printf("\n> Writing to file %s...\n", filename);

    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file %s.\n", filename);
        exit(1);
    }

    fprintf(fp, "%s", content);
    fclose(fp);

    printf("Done writing to file %s.\n", filename);
}

int main() {
    printHeader("Welcome to the System Administration Example Program!");

    char input[100];

    while (1) {
        printf("Enter a command ('help' for options): ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "help\n") == 0) {
            printf("\nAvailable commands:\n");
            printf("  help: Display available commands.\n");
            printf("  whoami: Print current user.\n");
            printf("  ls: List contents of current directory.\n");
            printf("  pwd: Print current working directory.\n");
            printf("  date: Print current date and time.\n");
            printf("  echo: Write a message to a file.\n");
            printf("  clear: Clear the terminal.\n");
            printf("  exit: Exit the program.\n");
        }
        else if (strcmp(input, "whoami\n") == 0) {
            executeCommand("whoami");
        }
        else if (strcmp(input, "ls\n") == 0) {
            executeCommand("ls -al");
        }
        else if (strcmp(input, "pwd\n") == 0) {
            executeCommand("pwd");
        }
        else if (strcmp(input, "date\n") == 0) {
            executeCommand("date");
        }
        else if (strcmp(input, "clear\n") == 0) {
            executeCommand("clear");
        }
        else if (strncmp(input, "echo ", 5) == 0) {
            char message[100];
            char filename[100];

            sscanf(input, "echo %[^\n]%*c %s", message, filename);
            printf("Writing message '%s' to file %s...\n", message, filename);

            writeFile(filename, message);
        }
        else if (strcmp(input, "exit\n") == 0) {
            printf("\nGoodbye!\n");
            exit(0);
        }
        else {
            printf("Invalid command. Type 'help' for options.\n");
        }
    }

    return 0;
}