//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024     // Maximum length of a line in the CSV file
#define MAX_FIELD_LENGTH 128     // Maximum length of a field in the CSV file
#define MAX_NUM_FIELDS 20        // Maximum number of fields in a single line

int read_csv_file(char *filename);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    read_csv_file(argv[1]);

    return 0;
}

// Read the CSV file and print its contents
int read_csv_file(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;   // Return error code
    }

    char line[MAX_LINE_LENGTH];
    char *fields[MAX_NUM_FIELDS];
    int num_fields;

    // Read each line from the file until the end-of-file is reached
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Get the number of fields and split the line into fields
        num_fields = 0;
        fields[num_fields] = strtok(line, ",\n");
        while (fields[num_fields] != NULL && num_fields < MAX_NUM_FIELDS) {
            num_fields++;
            fields[num_fields] = strtok(NULL, ",\n");
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