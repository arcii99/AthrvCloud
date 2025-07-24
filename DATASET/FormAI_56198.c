//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIELD_SIZE 25
#define MAX_ROWS 100

typedef struct {
    char *fields[FIELD_SIZE];
} Row;

int main() {
    FILE *fileptr;
    fileptr = fopen("example.csv", "r");

    char buffer[1024];
    Row rows[MAX_ROWS];

    int row_index = 0;
    while (fgets(buffer, 1024, fileptr)) {
        char *field = strtok(buffer, ",");
        int field_index = 0;
        while (field != NULL) {
            rows[row_index].fields[field_index] = field;
            field = strtok(NULL, ",");
            field_index++;
        }
        row_index++;
    }

    printf("CSV Reader - Reading Rows:\n");

    for (int i = 0; i < row_index; i++) {
        printf("Row %d: ", i);
        for (int j = 0; rows[i].fields[j] != NULL; j++) {
            printf("%s ", rows[i].fields[j]);
        }
        printf("\n");
    }

    fclose(fileptr);
    return 0;
}