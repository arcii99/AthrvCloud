//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[50];
    char line[1024];
    char *field;
    int field_num = 0;

    printf("Enter the CSV filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Unable to open file.");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        field_num = 0;

        printf("%s\n", line);

        field = strtok(line, ",");

        while (field) {
            field_num++;
            printf("Field %d: %s\n", field_num, field);
            field = strtok(NULL, ",");
        }
    }

    printf("CSV file read successfully.");

    fclose(file);

    return 0;
}