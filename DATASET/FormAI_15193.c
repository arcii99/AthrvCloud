//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h> // For standard I/O operations
#include <stdlib.h> // For dynamic memory allocation
#include <string.h> // For string operations

#define MAX_RECORD_SIZE 100 // Maximum record size
#define MAX_FIELD_SIZE 25 // Maximum field size in characters
#define MAX_FIELDS 10 // Maximum number of fields in a record

int main() {
    char filename[50];
    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r"); // Open file in read mode 
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char record[MAX_RECORD_SIZE];
    char *field[MAX_FIELDS];
    int current_field_index = 0;

    while (fgets(record, MAX_RECORD_SIZE, file) != NULL) { // Read line by line
        current_field_index = 0;

        field[current_field_index] = strtok(record, ","); // Split string by delimiter

        while (field[current_field_index] != NULL) {
            current_field_index++;
            if (current_field_index == MAX_FIELDS) {
                printf("Maximum number of fields per record exceeded.\n");
                exit(1);
            }
            field[current_field_index] = strtok(NULL, ",");
        }

        printf("Record: ");
        for (int i = 0; i < current_field_index; i++) {
            printf("%s ", field[i]);
        }
        printf("\n");
    }

    fclose(file); // Close file

    return 0;
}