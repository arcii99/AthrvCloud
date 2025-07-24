//FormAI DATASET v1.0 Category: Data mining ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FIELDS 1000

typedef struct {
    char fields[MAX_FIELDS][MAX_LINE_SIZE];
    int num_fields;
} Record;

typedef struct {
    Record* records;
    size_t num_records;
} Records;

void read_csv(FILE* fp, Records* records) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, sizeof(line), fp)) {
        char* token = strtok(line, ",");
        Record new_record;
        new_record.num_fields = 0;
        while (token) {
            strcpy(new_record.fields[new_record.num_fields], token);
            new_record.num_fields++;
            token = strtok(NULL, ",");
        }
        records->records[records->num_records++] = new_record;
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please enter CSV file path.\n");
        return -1;
    }
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Failed to open file.\n");
        return -1;
    }
    Records records;
    records.records = malloc(sizeof(Record) * MAX_FIELDS);
    records.num_records = 0;
    read_csv(fp, &records);
    fclose(fp);

    printf("Number of records: %lu\n", records.num_records);
    printf("Number of fields: %d\n", records.records[0].num_fields);

    return 0;
}