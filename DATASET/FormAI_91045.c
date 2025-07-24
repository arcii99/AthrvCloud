//FormAI DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 256

int main() {

    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the file to write to: ");
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "w");

    if(!file) {
        printf("Error opening file!\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int line_count = 1;

    printf("Enter text to write to file. Enter 'quit' to exit.\n");

    do {
        printf("Line %d: ", line_count);
        scanf(" %[^\n]", line);

        if(!strcmp(line, "quit")) {
            break;
        }

        fprintf(file, "%d. %s\n", line_count, line);

        line_count++;

    } while(1);

    printf("File written successfully!\n");

    fclose(file);

    return 0;

}