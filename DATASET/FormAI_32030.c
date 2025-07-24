//FormAI DATASET v1.0 Category: Log analysis ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

/* Function to parse a line of C logs */
void parseCLogLine(char *line) {
    /* Separate the timestamp and the log message */
    char *timestamp = strtok(line, " ");
    char *message = strtok(NULL, "\n");

    /* Print the timestamp and log message */
    printf("[%s] %s\n", timestamp, message);
}

/* Function to read and parse a file of C logs */
void readCLogFile(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        parseCLogLine(line);
    }

    fclose(file);
}

/* Main function */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: Please specify a file name as an argument\n");
        return 1;
    }

    char *filename = argv[1];

    readCLogFile(filename);

    return 0;
}