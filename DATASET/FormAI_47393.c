//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_NUM_FIELDS 10

int main(int argc, char *argv[]) {

    // Check if file path is provided
    if (argc < 2) {
        printf("Please provide the file path.\n");
        return 1;
    }

    // Open the CSV file
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Initialize variables
    char line[MAX_LINE_SIZE];
    char *field;
    char *fields[MAX_NUM_FIELDS];
    int num_fields;

    // Read and print each line
    while (fgets(line, MAX_LINE_SIZE, fp)) {

        // Count the number of fields in the line
        num_fields = 0;
        field = strtok(line, ",");
        while (field != NULL && num_fields < MAX_NUM_FIELDS) {
            fields[num_fields++] = field;
            field = strtok(NULL, ",");
        }

        // Print the fields
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");
    }

    // Close the file
    fclose(fp);

    return 0;
}