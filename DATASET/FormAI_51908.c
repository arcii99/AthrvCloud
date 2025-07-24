//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main()
{
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char *field;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        printf("Line: %s", line);

        field = strtok(line, ",");

        while (field != NULL) {
            printf("Field: %s\n", field);
            field = strtok(NULL, ",");
        }
    }

    fclose(file);

    return 0;
}