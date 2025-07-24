//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024 // maximum size of a line in the CSV file

int main(int argc, char *argv[]) {
    FILE *csvFile; // CSV file pointer
    char *line = NULL; // stores the line read from the CSV file
    char *token = NULL; // stores the current token being processed
    char *delimiter = ","; // delimiter for tokenizing the line
    size_t lineSize = MAX_LINE_SIZE; // initial size of the line buffer
    ssize_t charactersRead; // stores the number of characters read by getline()

    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    csvFile = fopen(argv[1], "r"); // open the CSV file for reading

    if (csvFile == NULL) { // check if the file was opened successfully
        printf("Error: failed to open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // read the CSV file line by line
    while ((charactersRead = getline(&line, &lineSize, csvFile)) != -1 ) {
        // tokenize the line and print each token
        while ((token = strsep(&line, delimiter)) != NULL) {
            printf("%s\n", token);
        }
    }

    // free memory and close the file
    free(line);
    fclose(csvFile);

    return 0;
}