//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100    // Maximum length of a field in the CSV file
#define MAX_FIELD_NUM 10   // Maximum number of fields in a row in the CSV file
#define MAX_ROW_NUM 1000   // Maximum number of rows in the CSV file

// Structure definition for a row in the CSV file
struct csv_row {
    char fields[MAX_FIELD_NUM][MAX_STR_LEN];
    int num_fields;
};

// Function to parse a line of CSV file
struct csv_row parse_csv_line(char *line, char *delim) {
    struct csv_row row;
    char *token = strtok(line, delim);
    row.num_fields = 0;
    while (token != NULL && row.num_fields < MAX_FIELD_NUM) {
        strcpy(row.fields[row.num_fields], token);
        row.num_fields++;
        token = strtok(NULL, delim);
    }
    return row;
}

// Function to read CSV file and fill the data into an array of rows
int read_csv_file(char *filename, char *delim, struct csv_row *rows) {
    FILE *fptr;
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening file!");
        return -1;
    }
    char line[MAX_STR_LEN * MAX_FIELD_NUM];
    int row_num = 0;
    while (fgets(line, sizeof(line), fptr) != NULL && row_num < MAX_ROW_NUM) {
        row_num++;
        rows[row_num - 1] = parse_csv_line(line, delim);
    }
    fclose(fptr);
    return row_num;
}

int main() {
    char filename[] = "data.csv";
    char delim[] = ",";
    struct csv_row rows[MAX_ROW_NUM];
    int num_rows = read_csv_file(filename, delim, rows);
    if (num_rows == -1) {
        return -1;
    }
    printf("Number of rows read from the CSV file: %d\n", num_rows);
    for (int i = 0; i < num_rows; i++) {
        printf("\nRow %d:\n", i+1);
        for (int j = 0; j < rows[i].num_fields; j++) {
            printf("%s, ", rows[i].fields[j]);
        }
    }
    return 0;
}