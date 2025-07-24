//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 256
#define MAX_FIELDS 10

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *fields[MAX_FIELDS];
    int field_count = 0;

    if (argc < 2) {
        printf("Usage: %s filename.csv\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_SIZE, fp)) {
        char *field = strtok(line, ",");

        while (field != NULL && field_count < MAX_FIELDS) {
            fields[field_count] = strdup(field);
            field_count++;
            field = strtok(NULL, ",");
        }

        for (int i = 0; i < field_count; i++) {
            printf("%s ", fields[i]);
            free(fields[i]);
        }

        printf("\n");
        field_count = 0;
    }

    fclose(fp);

    return 0;
}