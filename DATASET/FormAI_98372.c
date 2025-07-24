//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELD_LENGTH 100

int main() {
    FILE *csv_file;
    char line[MAX_LINE_LENGTH];
    char *field;
    char fields[MAX_FIELD_LENGTH][MAX_FIELD_LENGTH];
    int i = 0;

    csv_file = fopen("data.csv", "r");

    if (csv_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, csv_file)) {
        field = strtok(line, ",");

        while (field != NULL) {
            strcpy(fields[i], field);
            i++;
            field = strtok(NULL, ",");
        }
    }

    for (int j = 0; j < i; j++) {
        printf("%s\n", fields[j]);
    }

    fclose(csv_file);
    return 0;
}