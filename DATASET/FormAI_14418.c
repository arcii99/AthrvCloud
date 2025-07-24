//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum length of each field in the csv file
#define MAX_FIELD_LENGTH 50

// define the maximum number of fields in the csv file
#define MAX_FIELDS 10

// define the maximum length of a line in the csv file
#define MAX_LINE_LENGTH (MAX_FIELDS * MAX_FIELD_LENGTH)

// function to read a csv file
void read_csv(char *filename) {
    // open the file in read mode
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }
    
    // buffer to hold a line from the csv file
    char line[MAX_LINE_LENGTH];
    
    // read the first line to get the field names
    if (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // remove the newline character at the end of the line
        char *newline = strchr(line, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }
        
        // split the line into fields
        char *field;
        int field_count = 0;
        char *fields[MAX_FIELDS];
        field = strtok(line, ",");
        while (field != NULL && field_count < MAX_FIELDS) {
            fields[field_count] = field;
            field = strtok(NULL, ",");
            field_count++;
        }
        
        // print the field names
        printf("Field Names:\n");
        for (int i = 0; i < field_count; i++) {
            printf("%s\n", fields[i]);
        }
    }
    
    // read the rest of the lines
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // remove the newline character at the end of the line
        char *newline = strchr(line, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }
        
        // split the line into fields
        char *field;
        int field_count = 0;
        char *fields[MAX_FIELDS];
        field = strtok(line, ",");
        while (field != NULL && field_count < MAX_FIELDS) {
            fields[field_count] = field;
            field = strtok(NULL, ",");
            field_count++;
        }
        
        // print the fields
        printf("\n");
        for (int i = 0; i < field_count; i++) {
            printf("%s: %s\n", fields[i], fields[i + 1]);
            i++;
        }
    }
    
    // close the file
    fclose(fp);
}

int main() {
    // read the csv file
    read_csv("example.csv");
    
    return 0;
}