//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_FIELD_SIZE 100

int main() {
    char file_name[MAX_FILE_NAME];
    char line[MAX_FIELD_SIZE];
    char *field;
    int field_count = 0;
    int line_count = 0;

    printf("Enter the CSV file name: ");
    scanf("%s", file_name);

    FILE *fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Error opening file. Exiting program.");
        return 1;
    }

    printf("\nReading CSV file...\n");

    while (fgets(line, MAX_FIELD_SIZE, fp)) {
        line_count++;

        printf("\nLine %d:\n", line_count);

        field_count = 0;
        field = strtok(line, ",");

        while (field != NULL) {
            field_count++;
            printf("Field %d: %s\n", field_count, field);
            field = strtok(NULL, ",");
        }
    }

    fclose(fp);

    printf("\nTotal number of lines: %d\n", line_count);

    return 0;
}