//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 128
#define MAX_FIELDS 16

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <csv file>\n", argv[0]);
        exit(1);
    }
    
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Could not open file %s\n", argv[1]);
        exit(1);
    }
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp)) {
        char *field_values[MAX_FIELDS];
        int field_count = 0;

        // Parse the line
        char *value = strtok(line, ",");
        while (value != NULL && field_count < MAX_FIELDS) {
            char *field_value = (char*)malloc(sizeof(char) * MAX_FIELD_LENGTH);
            strncpy(field_value, value, MAX_FIELD_LENGTH);
            field_values[field_count++] = field_value;
            value = strtok(NULL, ",");
        }

        // Print the fields
        int i;
        for (i = 0; i < field_count; i++) {
            printf("Field %d: %s\n", i+1, field_values[i]);
            free(field_values[i]);
        }
        printf("\n");
    }
    
    fclose(fp);
    return 0;
}