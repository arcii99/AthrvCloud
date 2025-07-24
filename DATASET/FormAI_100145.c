//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct to hold data for each row
typedef struct Row {
    char* data;
    struct Row* next;
} Row;

int main() {
    // open CSV file for reading
    FILE* file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open CSV file\n");
        return 1;
    }

    // read the header row
    char header[256];
    fgets(header, 256, file);

    // create a linked list to hold the rows
    Row* rows = NULL;

    // read each row and add it to the linked list
    while (!feof(file)) {
        // allocate memory for the row
        Row* row = (Row*)malloc(sizeof(Row));
        row->data = (char*)malloc(256);

        // read the row data
        fgets(row->data, 256, file);

        // add the row to the linked list
        row->next = rows;
        rows = row;
    }

    // close the CSV file
    fclose(file);

    // iterate through the rows and print the data for each row
    Row* currentRow = rows;
    while (currentRow != NULL) {
        printf("%s", currentRow->data);
        currentRow = currentRow->next;
    }

    // free memory for the rows
    currentRow = rows;
    while (currentRow != NULL) {
        Row* nextRow = currentRow->next;
        free(currentRow->data);
        free(currentRow);
        currentRow = nextRow;
    }

    return 0;
}