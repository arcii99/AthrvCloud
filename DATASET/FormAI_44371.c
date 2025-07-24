//FormAI DATASET v1.0 Category: Log analysis ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <logfile>", argv[0]); // Display usage information
        return 1;
    }

    char *logfile = argv[1];
    FILE *file = fopen(logfile, "r");
    if(file == NULL) {
        printf("Error opening file: %s", logfile);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int count = 0, line = 1;
    while(fgets(buffer, BUFFER_SIZE, file)) { // Iterate through each line of the file
        if(strstr(buffer, "ERROR") != NULL) { // If the line contains the string "ERROR"
            printf("Line %d: %s", line, buffer);
            count++;
        }
        line++;
    }

    printf("Found %d errors in %s", count, logfile);
    fclose(file); // Close the file
    return 0;
}