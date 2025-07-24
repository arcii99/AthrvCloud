//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define constants
#define MAX_CSV_LINE_LENGTH 100
#define MAX_CSV_FIELD_LENGTH 20
#define MAX_CSV_FIELD_NUMBER 10

/**
 * struct csvRow - represents a row in CSV file
 * @fields: an array of fields in this row
 * @fieldCount: number of fields in this row
 */
typedef struct {
    char fields[MAX_CSV_FIELD_NUMBER][MAX_CSV_FIELD_LENGTH];
    int fieldCount;
} csvRow;

/**
 * readRow - read a row from CSV file
 * @file: pointer to the file structure
 * @outRow: the row read from file
 * @return: 0 for success, -1 for end of file, -2 for invalid row
 */
int readRow(FILE *file, csvRow *outRow) {
    char line[MAX_CSV_LINE_LENGTH];
    if (fgets(line, MAX_CSV_LINE_LENGTH, file) == NULL) {
        return -1;  //end of file
    }
    outRow->fieldCount = 0;
    char *ptr = strtok(line, ",");
    while (ptr != NULL) {
        if (strlen(ptr) >= MAX_CSV_FIELD_LENGTH) {
            return -2;  //invalid row
        }
        strcpy(outRow->fields[outRow->fieldCount], ptr);
        outRow->fieldCount++;
        ptr = strtok(NULL, ",");
    }
    return 0;  //success
}

/**
 * printRow - print a row to stdout
 * @row: pointer to the row to print
 */
void printRow(csvRow *row) {
    for (int i = 0; i < row->fieldCount; i++) {
        printf("%s", row->fields[i]);
        if (i < row->fieldCount - 1) {
            printf(",");
        }
    }
    printf("\n");
}

int main() {
    //open the file for reading
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Failed to open example.csv\n");
        return -1;
    }

    //read the rows from the file and print them to stdout
    csvRow row;
    int readStatus;
    do {
        readStatus = readRow(file, &row);
        if (readStatus == 0) {
            printRow(&row);
        } else if (readStatus == -2) {
            printf("Encountered an invalid row!\n");
        }
    } while (readStatus != -1);

    //clean up and exit
    fclose(file);
    return 0;
}