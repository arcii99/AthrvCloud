//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_LINE_LENGTH 1024

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error reading file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char line[MAX_CSV_LINE_LENGTH];
    char *delimiter = ",";
    int line_num = 0;

    printf("Reading file: %s...\n", argv[1]);

    while (fgets(line, MAX_CSV_LINE_LENGTH, fp) != NULL) {
        // Replace newline with null terminator
        line[strcspn(line, "\n")] = '\0';

        if (line_num == 0) {
            // Header line
            printf("Header line detected: %s\n", line);
        } else {
            // Data line
            printf("Data line %d detected: ", line_num);

            char *field = strtok(line, delimiter);
            while (field != NULL) {
                printf("%s, ", field);
                field = strtok(NULL, delimiter);
            }

            printf("\n");
        }

        line_num++;
    }

    printf("Finished reading file: %s\n", argv[1]);

    fclose(fp);
    return 0;
}