//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10
#define MAX_PROCESS_NAME_LENGTH 20
#define MAX_RAM_SIZE 2048
#define RAM_BLOCK_SIZE 32

// Define a process struct
struct Process {
    char name[MAX_PROCESS_NAME_LENGTH];
    int size;
};

// Define a ram struct
struct Ram {
    char blocks[MAX_RAM_SIZE/RAM_BLOCK_SIZE][RAM_BLOCK_SIZE];
    int usage[MAX_RAM_SIZE/RAM_BLOCK_SIZE];
};

// Function to print memory usage
void printMemoryUsage(struct Ram ram) {
    printf("Memory Usage:\n");
    for (int i = 0; i < MAX_RAM_SIZE/RAM_BLOCK_SIZE; i++) {
        if (ram.usage[i] == 0) {
            printf("Block #%d: Empty\n", i);
        } else {
            printf("Block #%d: Process '%s' (%d KB)\n", i, ram.blocks[i], ram.usage[i]);
        }
    }
}

// Function to allocate memory for a process
void allocateMemory(struct Process process, struct Ram *ram) {
    int blocksRequired = process.size/RAM_BLOCK_SIZE;
    int index = -1;
    for (int i = 0; i < MAX_RAM_SIZE/RAM_BLOCK_SIZE; i++) {
        if (index == -1 && ram->usage[i] == 0) {
            // Found first empty block
            index = i;
        } else if (index != -1 && ram->usage[i] == 0) {
            // Check if there are enough consecutive blocks available
            if (i-index >= blocksRequired) {
                // Allocate blocks and update usage
                for (int j = index; j < index+blocksRequired; j++) {
                    strcpy(ram->blocks[j], process.name);
                    ram->usage[j] = process.size;
                }
                return;
            } else {
                index = -1; // Reset index and continue searching
            }
        }
    }
    printf("Error: Could not allocate memory for process '%s' (%d KB)\n", process.name, process.size);
}

// Function to free memory for a process
void freeMemory(char *processName, struct Ram *ram) {
    for (int i = 0; i < MAX_RAM_SIZE/RAM_BLOCK_SIZE; i++) {
        if (strcmp(ram->blocks[i], processName) == 0) {
            // Free blocks and update usage
            ram->usage[i] = 0;
            memset(ram->blocks[i], 0, sizeof(ram->blocks[i]));
        }
    }
}

// Main function to run program
int main() {
    // Initialize ram and processes
    struct Ram ram;
    memset(&ram.usage, 0, sizeof(ram.usage));
    struct Process processes[MAX_PROCESSES];
    int numProcesses = 0;

    // Print initial memory usage
    printMemoryUsage(ram);

    // Loop to take user input
    char input[100];
    while (1) {
        printf("\nEnter a command ('help' for a list of commands): ");
        fgets(input, 100, stdin);
        input[strlen(input)-1] = '\0';

        // Help command
        if (strcmp(input, "help") == 0) {
            printf("Available commands:\n");
            printf("  'help': Display a list of commands\n");
            printf("  'add process': Add a process to the system\n");
            printf("  'remove process': Remove a process from the system\n");
            printf("  'print usage': Print the current memory usage\n");
            printf("  'quit': Quit the program\n");

        // Add process command
        } else if (strcmp(input, "add process") == 0) {
            if (numProcesses >= MAX_PROCESSES) {
                printf("Error: Maximum number of processes reached (%d)\n", MAX_PROCESSES);
            } else {
                // Get process name and size from user
                char name[MAX_PROCESS_NAME_LENGTH];
                int size;
                printf("Enter process name (up to %d characters): ", MAX_PROCESS_NAME_LENGTH-1);
                fgets(name, MAX_PROCESS_NAME_LENGTH, stdin);
                name[strlen(name)-1] = '\0'; // Remove newline character
                printf("Enter process size (in KB, up to %d): ", MAX_RAM_SIZE/1024);
                scanf("%d", &size);
                getchar(); // Remove newline character

                // Create process and allocate memory
                struct Process process;
                strcpy(process.name, name);
                process.size = size;
                processes[numProcesses] = process;
                numProcesses++;
                allocateMemory(process, &ram);

                // Print memory usage
                printMemoryUsage(ram);
            }

        // Remove process command
        } else if (strcmp(input, "remove process") == 0) {
            if (numProcesses == 0) {
                printf("Error: No processes to remove\n");
            } else {
                // Get process name from user
                char name[MAX_PROCESS_NAME_LENGTH];
                printf("Enter process name to remove: ");
                fgets(name, MAX_PROCESS_NAME_LENGTH, stdin);
                name[strlen(name)-1] = '\0'; // Remove newline character

                // Free memory and remove process
                freeMemory(name, &ram);
                int index = -1;
                for (int i = 0; i < numProcesses; i++) {
                    if (strcmp(processes[i].name, name) == 0) {
                        index = i;
                        break;
                    }
                }
                if (index == -1) {
                    printf("Error: Process '%s' not found\n", name);
                } else {
                    for (int i = index; i < numProcesses-1; i++) {
                        processes[i] = processes[i+1];
                    }
                    numProcesses--;
                    printf("Process '%s' removed\n", name);
                }

                // Print memory usage
                printMemoryUsage(ram);
            }

        // Print usage command
        } else if (strcmp(input, "print usage") == 0) {
            printMemoryUsage(ram);

        // Quit command
        } else if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;

        // Invalid command
        } else {
            printf("Error: Invalid command\n");
        }
    }

    return 0;
}