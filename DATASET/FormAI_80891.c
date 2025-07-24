//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 10

void parse_line(char *line, char (*fields)[MAX_FIELD_LENGTH], int *num_fields) {
    int i = 0;
    char *token;

    token = strtok(line, ",");
    while (token != NULL && i < MAX_FIELDS) {
        strcpy(fields[i], token);
        i++;
        token = strtok(NULL, ",");
    }

    *num_fields = i;
}

void read_csv(FILE *csv_file) {
    char line[MAX_LINE_LENGTH];
    char fields[MAX_FIELDS][MAX_FIELD_LENGTH];
    int num_fields;

    while (fgets(line, MAX_LINE_LENGTH, csv_file)) {
        parse_line(line, fields, &num_fields);

        for (int i = 0; i < num_fields; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");
    }
}

int main() {
    FILE *csv_file = fopen("example.csv", "r");
    if (csv_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_csv(csv_file);

    fclose(csv_file);
    return 0;
}