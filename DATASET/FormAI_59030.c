//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FIELDS 10

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: %s filename.csv\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if(!file) {
        printf("Failed to open file %s\n", argv[1]);
        return 1;
    }

    char line_buffer[MAX_LINE_SIZE];
    char *fields[MAX_FIELDS];
    int field_count = 0;

    while(fgets(line_buffer, MAX_LINE_SIZE, file)) {
        // Remove newline character
        strtok(line_buffer, "\n");

        // Split line into fields
        char *field = strtok(line_buffer, ",");
        field_count = 0;
        while(field != NULL && field_count < MAX_FIELDS) {
            fields[field_count++] = field;
            field = strtok(NULL, ",");
        }

        // Process fields
        for(int i = 0; i < field_count; i++) {
            printf("Field %d: %s\n", i, fields[i]);
        }
    }

    fclose(file);
    return 0;
}