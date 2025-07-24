//FormAI DATASET v1.0 Category: Error handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {

    FILE *file = fopen("non_existent_file.txt", "r"); // Attempt to open a file that does not exist
    
    if (file == NULL) { // Check if file could not be opened
        perror("Error"); // Print error message with system error message
        exit(EXIT_FAILURE); // Terminate program with failure status
    }
    
    return 0;
}