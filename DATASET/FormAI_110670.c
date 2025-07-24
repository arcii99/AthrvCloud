//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10
#define MAX_FIELD_LENGTH 50
#define MAX_RECORD_LENGTH (MAX_FIELDS * MAX_FIELD_LENGTH)

void parse_csv_record(char *record, char *fields[]) {
    char *field;
    int field_count = 0;

    field = strtok(record, ",");
    while (field != NULL) {
        fields[field_count++] = field;
        field = strtok(NULL, ",");
    }
}

int main() {
    char record[MAX_RECORD_LENGTH];
    char *fields[MAX_FIELDS];
    int field_count;

    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(record, MAX_RECORD_LENGTH, fp) != NULL) {
        field_count = 0;
        parse_csv_record(record, fields);
        while (fields[field_count] != NULL) {
            printf("%s ", fields[field_count]);
            field_count++;
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}