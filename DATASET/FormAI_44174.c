//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

int main() {
    FILE *fp;
    char filename[MAX_LEN];
    char line[MAX_LEN];
    char *field;
    int line_count = 0;
    int field_count = 0;

    // Prompt user for input file name
    printf("Enter name of CSV file: ");
    fgets(filename, MAX_LEN, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character

    // Open input file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    // Read each line of file
    while (fgets(line, MAX_LEN, fp)) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;
        line_count++;

        // Parse line into fields
        field = strtok(line, ",");
        while (field != NULL) {
            printf("%s\n", field);
            field_count++;
            field = strtok(NULL, ",");
        }
    }

    // Close file and print results
    fclose(fp);
    printf("Number of lines: %d\n", line_count);
    printf("Number of fields: %d\n", field_count);
    
    return 0;
}