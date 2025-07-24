//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10
#define MAX_FIELD_LENGTH 50
#define MAX_LINE_LENGTH 1024

struct CSVRow {
    char fields[MAX_FIELDS][MAX_FIELD_LENGTH];
    int num_fields;
};

typedef struct CSVRow CSVRow;

void parse_line(char* line, CSVRow* row) {
    char* field;
    int i = 0;

    row->num_fields = 0;
    field = strtok(line, ",");
    
    while(field != NULL && i < MAX_FIELDS) {
        strncpy(row->fields[i], field, MAX_FIELD_LENGTH);
        row->num_fields++;
        i++;
        field = strtok(NULL, ",");
    }
}

void print_row(CSVRow* row) {
    int i;

    for(i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }

    printf("\n");
}

int main(int argc, char** argv) {
    char line[MAX_LINE_LENGTH];
    FILE* file;
    CSVRow row;

    if(argc < 2) {
        printf("Usage: csvreader [filename]\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if(file == NULL) {
        printf("Unable to open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while(fgets(line, MAX_LINE_LENGTH, file)) {
        parse_line(line, &row);
        print_row(&row);

        // Shape Shift code:
        if(row.num_fields >= 5) {
            printf("This is a large row!\n");
        }
        else {
            printf("This is a small row.\n");
        }
    }

    fclose(file);

    return 0;
}