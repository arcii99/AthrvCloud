//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

/**
 * Struct for a single record in the CSV file.
 */
typedef struct {
    char field1[MAX_LINE_LENGTH];
    char field2[MAX_LINE_LENGTH];
    char field3[MAX_LINE_LENGTH];
} Record;

/**
 * Parse a single line of the CSV file into a Record struct.
 */
void parseLine(char* line, Record* record) {
    char* field = strtok(line, ",");
    if (field) {
        strcpy(record->field1, field);
    }
    
    field = strtok(NULL, ",");
    if (field) {
        strcpy(record->field2, field);
    }
    
    field = strtok(NULL, ",");
    if (field) {
        strcpy(record->field3, field);
    }
}

int main() {
    FILE* file = fopen("data.csv", "r");
    if (!file) {
        printf("Failed to open file.\n");
        return 1;
    }
    
    // Read the header line and discard it.
    char header[MAX_LINE_LENGTH];
    fgets(header, MAX_LINE_LENGTH, file);
    
    // Read each line of the file and parse it into a record.
    Record record;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        parseLine(line, &record);
        printf("Field 1: %s, Field 2: %s, Field 3: %s\n", record.field1, record.field2, record.field3);
    }
    
    // Clean up.
    fclose(file);
    return 0;
}