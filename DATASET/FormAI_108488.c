//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FIELDS 16

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: csvreader <filename>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    int num_fields = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        num_fields = 0;
        char *token = strtok(line, ",");
        while (token != NULL && num_fields < MAX_FIELDS) {
            fields[num_fields++] = token;
            token = strtok(NULL, ",");
        }

        // print out the fields
        for (int i = 0; i < num_fields; i++) {
            printf("Field %d: %s\n", i, fields[i]);
        }
    }

    fclose(file);
    return 0;
}