//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20   // Maximum number of columns in the CSV file
#define MAX_FIELD_LEN 100 // Maximum length of each field in the CSV file
#define MAX_FILE_LEN 1000 // Maximum length of the CSV file

// Split the CSV input line by comma and return the number of fields
int split_line(char line[], char *fields[]) {
    int count = 0;
    char *token = strtok(line, ",");
    while (token != NULL) {
        fields[count++] = token;
        token = strtok(NULL, ",");
    }
    return count;
}

// Read the CSV file and store the data in a 2D array
int read_csv(FILE *fp, char *data[][MAX_COLS]) {
    char line[MAX_FIELD_LEN];
    int row = 0;
    while (fgets(line, MAX_FILE_LEN, fp) != NULL) {
        char *fields[MAX_COLS];
        int num_fields = split_line(line, fields);
        for (int col = 0; col < num_fields; col++) {
            data[row][col] = fields[col];
        }
        row++;
    }
    return row;
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: Unable to open the file\n");
        return 1;
    }

    char *data[MAX_FILE_LEN][MAX_COLS];
    int num_rows = read_csv(fp, data);

    // Print the data stored in the 2D array
    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            if (data[row][col] != NULL) {
                printf("%s\t", data[row][col]);
            }
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}