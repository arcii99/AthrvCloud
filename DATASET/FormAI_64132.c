//FormAI DATASET v1.0 Category: System boot optimizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bootOptimizer() {
    printf("Starting system boot optimizer...\n");

    // Simulating boot optimization steps
    printf("Optimizing startup programs...\n");
    srand(time(NULL));
    int numPrograms = rand() % 20 + 5; // Generating random number of programs
    for (int i = 0; i < numPrograms; i++) {
        int programID = rand() % 1000 + 1; // Generating random program ID
        printf("Program #%d optimized.\n", programID);
    }

    printf("Cleaning up temporary files...\n");
    int numFiles = rand() % 50 + 10; // Generating random number of files
    for (int j = 0; j < numFiles; j++) {
        int fileID = rand() % 10000 + 1; // Generating random file ID
        printf("File #%d deleted.\n", fileID);
    }

    printf("Disk defragmentation...\n");
    printf("Optimizing system registry...\n");

    printf("System boot optimization complete.\n");
}

int main() {
    printf("Welcome to Boot Optimizer program!\n");
    printf("Press 'y' for running boot optimization process: ");
    char choice;
    scanf("%c", &choice);

    if (choice == 'y') {
        bootOptimizer();
    } else {
        printf("Exiting program.\n");
    }

    return 0;
}