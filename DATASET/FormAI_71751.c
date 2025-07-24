//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELD_LENGTH 50
#define MAX_NUM_FIELDS 20

int main(int argc, char **argv) {
    char filename[MAX_FIELD_LENGTH];
    char line[MAX_LINE_LENGTH];
    char *fields[MAX_NUM_FIELDS];
    char *field;
    int num_fields;
    int i;

    printf("Enter CSV filename: ");
    scanf("%s", filename);

    FILE *csv_file = fopen(filename, "r");
    if (csv_file == NULL) {
        printf("Error: unable to open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, csv_file) != NULL) {
        num_fields = 0;
        field = strtok(line, ",");
        while (field != NULL && num_fields < MAX_NUM_FIELDS) {
            fields[num_fields++] = field;
            field = strtok(NULL, ",");
        }

        for (i = 0; i < num_fields; i++) {
            printf("%s\t", fields[i]);
        }
        printf("\n");
    }

    fclose(csv_file);
    return 0;
}