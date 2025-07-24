//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELDS 100

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    char *field;
    int field_count = 0;
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        field_count = 0;

        /* Split line into fields */
        field = strtok(line, ",");
        while (field != NULL && field_count < MAX_FIELDS) {
            fields[field_count++] = field;
            field = strtok(NULL, ",");
        }

        /* Print fields */
        for (i = 0; i < field_count; i++) {
            printf("%s", fields[i]);
            if (i < field_count - 1) {
                printf(",");
            }
        }
        printf("\n");
    }

    fclose(fp);
    return 0;
}