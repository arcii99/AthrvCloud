//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 20

/*
 *  This function splits a CSV line into separate fields and returns
 *  the number of fields found.
 */
int split_csv_line(char *line, char **fields, int max_fields) {
    char *p = line;
    int field_count = 0;

    // Loop through the line, looking for commas separating fields.
    while (*p && field_count < max_fields) {
        if (*p == ',') {
            // Replace the comma with a null terminator and
            // add the field to the list.
            *p = '\0';
            fields[field_count++] = line;
            line = p + 1;
        }
        p++;
    }

    // Add the last field (or the only field) to the list.
    fields[field_count++] = line;

    return field_count;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the CSV file for reading.
    FILE *csv_file = fopen(argv[1], "r");
    if (csv_file == NULL) {
        printf("Error: cannot open file '%s'\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LEN];
    char *fields[MAX_FIELDS];
    int field_count;

    // Read and process each line of the file.
    while (fgets(line, MAX_LINE_LEN, csv_file)) {
        // Remove the newline character from the end of the line.
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }

        // Split the line into fields.
        field_count = split_csv_line(line, fields, MAX_FIELDS);

        // Do something with the fields...
        for (int i = 0; i < field_count; i++) {
            printf("Field %d: '%s'\n", i, fields[i]);
        }
        printf("\n");
    }

    // Close the file.
    fclose(csv_file);

    return 0;
}