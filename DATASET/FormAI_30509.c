//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024
#define MAXFIELD 64
#define DELIMITER ","

struct csv {
    char *fields[MAXFIELD];
    int nfields;
};

void freecsv(struct csv *p)
{
    for (int i = 0; i < p->nfields; i++)
        free(p->fields[i]);
}

int readcsv(FILE *f, struct csv *p)
{
    char line[MAXLINE];
    char *field;
    int i;

    if (!fgets(line, MAXLINE, f))
        return -1;

    p->nfields = 0;

    field = strtok(line, DELIMITER);
    while (field != NULL) {
        if (p->nfields >= MAXFIELD) {
            freecsv(p);
            return -1;
        }
        p->fields[p->nfields++] = strdup(field);
        field = strtok(NULL, DELIMITER);
    }
    return p->nfields;
}

int main()
{
    FILE *f = fopen("example.csv", "r");
    if (f == NULL) {
        printf("Failed to open file example.csv");
        return -1;
    }

    struct csv row;
    int nfields;

    while ((nfields = readcsv(f, &row)) >= 0) {
        for (int i = 0; i < nfields; i++)
            printf("%s ", row.fields[i]);
        printf("\n");
        freecsv(&row);
    }

    fclose(f);
    return 0;
}