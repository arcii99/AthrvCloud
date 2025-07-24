//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10
#define MAX_FIELD_LENGTH 50
#define MAX_RECORD_LENGTH (MAX_FIELDS * MAX_FIELD_LENGTH)

/*
 * Read a CSV file and print its contents row by row.
 */
int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    FILE* csv_file = fopen(argv[1], "r");
    if (!csv_file) {
        printf("Failed to open %s\n", argv[1]);
        return 1;
    }

    char record[MAX_RECORD_LENGTH];
    int field_count = 0;
    char* fields[MAX_FIELDS];

    while (fgets(record, MAX_RECORD_LENGTH, csv_file)) {
        // Remove newline character
        char* newline = strchr(record, '\n');
        if (newline) {
            *newline = '\0';
        }

        field_count = 0;
        char* field = strtok(record, ",");
        while (field) {
            // Remove leading and trailing whitespace
            while (*field == ' ') {
                ++field;
            }
            char* end = field + strlen(field) - 1;
            while (end > field && *end == ' ') {
                --end;
            }
            *(end + 1) = '\0';

            fields[field_count++] = field;
            if (field_count == MAX_FIELDS) {
                break;
            }

            field = strtok(NULL, ",");
        }

        // Print fields
        for (int i = 0; i < field_count; ++i) {
            printf("%s%s", fields[i], i == field_count - 1 ? "\n" : ",");
        }
    }

    if (ferror(csv_file)) {
        printf("Error while reading from %s\n", argv[1]);
        return 1;
    }

    fclose(csv_file);
    return 0;
}