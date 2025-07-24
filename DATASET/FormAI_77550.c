//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 20
#define MAX_FIELD_LENGTH 50
#define MAX_LINE_LENGTH (MAX_FIELDS * MAX_FIELD_LENGTH + MAX_FIELDS + 1)

typedef struct {
    char names[MAX_FIELDS][MAX_FIELD_LENGTH];
    int count;
} field_names;

typedef struct {
    char *items[MAX_FIELDS];
    int count;
} record;

field_names field_names_from_line(char *line) {
    field_names names;
    char *token;
    int i = 0;
    token = strtok(line, ",");
    while (token != NULL && i < MAX_FIELDS) {
        strcpy(names.names[i], token);
        token = strtok(NULL, ",");
        i++;
    }
    names.count = i;
    return names;
}

record record_from_line(char *line) {
    record rec;
    char *token;
    int i = 0;
    token = strtok(line, ",");
    while (token != NULL && i < MAX_FIELDS) {
        rec.items[i] = (char *) malloc(sizeof(char) * MAX_FIELD_LENGTH);
        strcpy(rec.items[i], token);
        token = strtok(NULL, ",");
        i++;
    }
    rec.count = i;
    return rec;
}

void free_record(record rec) {
    int i;
    for (i = 0; i < rec.count; i++) {
        free(rec.items[i]);
    }
}

int read_csv_file(char *filename, field_names *names, record *records, int *count) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int i = 0, j;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        return -1;
    }
    if (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        *names = field_names_from_line(line);
    } else {
        printf("File is empty\n");
        return -1;
    }
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        records[i] = record_from_line(line);
        i++;
        if (i >= MAX_RECORDS) {
            printf("Max number of records reached!\n");
            break;
        }
    }
    fclose(fp);
    *count = i;
    return 0;
}

int main() {
    field_names names;
    record records[MAX_RECORDS];
    int count = 0, i, j;
    if (read_csv_file("data.csv", &names, records, &count) != 0) {
        return -1;
    }
    printf("Field names:\n");
    for (i = 0; i < names.count; i++) {
        printf("%s ", names.names[i]);
    }
    printf("\n");
    printf("Records:\n");
    for (i = 0; i < count; i++) {
        for (j = 0; j < records[i].count; j++) {
            printf("%s ", records[i].items[j]);
        }
        printf("\n");
        free_record(records[i]);
    }
    return 0;
}