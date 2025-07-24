//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 50

int main(int argc, char *argv[]) {
    char line[MAX_LINE_SIZE];
    char *field;
    char *fields[MAX_FIELDS];
    int num_fields, i;

    if (argc != 2) {
        printf("usage: csvreader filename.csv\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("error: can't open file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        num_fields = 0;

        field = strtok(line, ",");

        while (field != NULL && num_fields < MAX_FIELDS) {
            fields[num_fields++] = field;
            field = strtok(NULL, ",");
        }

        for (i = 0; i < num_fields; i++) {
            printf("%s ", fields[i]);
        }

        printf("\n");
    }

    fclose(fp);
    return 0;
}