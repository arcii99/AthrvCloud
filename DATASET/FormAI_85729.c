//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 // max length of a line in the CSV file

int main(int argc, char **argv) {
    if (argc != 2) { // check if filename was provided as command line argument
        printf("Error: Please provide CSV filename as command line argument.\n");
        return 1; // exit program with error code
    }

    FILE *file = fopen(argv[1], "r"); // open file for reading
    if (file == NULL) { // check if file was opened successfully
        printf("Error: Failed to open file %s\n", argv[1]);
        return 1; // exit program with error code
    }

    char line[MAX_LINE_LENGTH];
    char *token;
    const char delimiters[] = ",\n"; // delimeters used in CSV file
    int row = 0, col = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) { // read each line from the CSV file
        token = strtok(line, delimiters); // tokenize the line using the delimiters

        while (token != NULL) { // loop through each token in the line
            if (col == 0) { // print row number for first column
                printf("Row %d: ", row);
            }

            printf("%s", token); // print token value

            token = strtok(NULL, delimiters); // get next token
            col++; // increment column counter
            if (token != NULL) { // print comma separator for all columns except last column
                printf(", ");
            }
        }

        printf("\n"); // move to next line
        row++; // increment row counter
        col = 0; // reset column counter
    }

    fclose(file); // close file
    return 0; // exit program with success code
}