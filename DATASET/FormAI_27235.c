//FormAI DATASET v1.0 Category: System administration ; Style: dynamic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define ARRAY_SIZE 10 // Size of Dynamic Array

int main() {
    char* cmd[ARRAY_SIZE] = {NULL}; // Dynamic array of commands
    char str[100]; // Temporary string to store user input

    int i = 0; // Current index in the dynamic array
    int exitFlag = 0; // Flag to indicate when to exit program

    while (!exitFlag) {
        printf("Enter a command (type 'exit' to quit): ");
        fgets(str, sizeof(str), stdin);

        if (strcmp(str, "exit\n") == 0) { // Exit program if user types "exit"
            printf("Exiting program...\n");
            for (int j = 0; j < ARRAY_SIZE; j++) {
                free(cmd[j]); // Free allocated memory before exiting
            }
            exitFlag = 1;
        }
        else {
            cmd[i] = (char*) malloc(strlen(str) * sizeof(char)); // Allocate memory for new command
            if (cmd[i] == NULL) {
                printf("Error: Unable to allocate memory.\n");
                exit(1);
            }
            strcpy(cmd[i], str); // Copy command into dynamic array
            i++;

            if (i == ARRAY_SIZE) { // Check if dynamic array is full
                printf("Dynamic array is full. Exiting program...\n");
                for (int j = 0; j < ARRAY_SIZE; j++) {
                    free(cmd[j]); // Free allocated memory before exiting
                }
                exitFlag = 1;
            }
        }
    }

    return 0;
}