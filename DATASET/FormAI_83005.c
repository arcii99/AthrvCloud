//FormAI DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_warning(char* message) {
    printf("\033[1m\033[33m[WARNING]\033[0m %s\n", message);
}

void print_error(char* message) {
    printf("\033[1m\033[31m[ERROR]\033[0m %s\n", message);
}

int main(int argc, char** argv) {
    // Check if user has input a file to read
    if (argc < 2) {
        print_warning("No input file specified, using default file 'logfile.txt'");
        argv[1] = "logfile.txt";
    }

    // Try to open the file
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        print_error("Failed to open input file");
        exit(1);
    }

    // Display file information
    printf("\033[1m\033[36m[FILE INFO]\033[0m %s\n", argv[1]);

    // Start analyzing file
    char line[256];
    int line_number = 0;
    while (fgets(line, sizeof(line), file)) {
        // Increase line number
        line_number++;

        // Check if log line contains 'ERROR'
        if (strstr(line, "ERROR")) {
            printf("\033[1m\033[31m[ERROR]\033[0m [LINE %d] %s", line_number, line);
        }

        // Check if log line contains 'WARNING'
        if (strstr(line, "WARNING")) {
            printf("\033[1m\033[33m[WARNING]\033[0m [LINE %d] %s", line_number, line);
        }

        // Check if log line contains 'DEBUG'
        if (strstr(line, "DEBUG")) {
            printf("\033[1m\033[35m[DEBUG]\033[0m [LINE %d] %s", line_number, line);
        }
    }

    // Close the file
    fclose(file);
    
    return 0;
}