//FormAI DATASET v1.0 Category: System boot optimizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 100

void clear_buffer() {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

void print_logo() {
    printf("==========================\n");
    printf(" C BOOT OPTIMIZER PROGRAM\n");
    printf("==========================\n");
}

void print_menu() {
    printf("1. Check Current Boot Sequence\n");
    printf("2. Optimize Boot Sequence\n");
    printf("0. Exit\n");
}

void get_command(char* command) {
    printf("Enter Command: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = '\0';
}

void run_command(char* command) {
    if (strcmp(command, "1") == 0) {
        printf("Current Boot Sequence: \n");
        // command to get current boot sequence goes here
    } else if (strcmp(command, "2") == 0) {
        printf("Optimizing Boot Sequence...\n");
        // command to optimize boot sequence goes here
    } else if (strcmp(command, "0") == 0) {
        printf("Exiting Program...\n");
        exit(0);
    } else {
        printf("Invalid Command!\n");
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH] = "";
    while (1) {
        print_logo();
        print_menu();
        get_command(command);
        run_command(command);
        clear_buffer();
    }
    return 0;
}