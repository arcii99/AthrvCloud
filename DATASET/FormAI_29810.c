//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 1024
#define DELIMITER ","

struct CSVRow 
{
    char **fields;
    int numOfFields;
};

void freeCSVRow(struct CSVRow *row)
{
    int i;
    for (i = 0; i < row->numOfFields; i++)
        free(row->fields[i]);
    free(row->fields);
    free(row);
}

struct CSVRow *readCSVRow(FILE *file)
{
    struct CSVRow *row = NULL;
    char line[MAX_LENGTH];
    char *token = NULL;
    int numOfFields = 0;

    fgets(line, MAX_LENGTH, file);

    row = (struct CSVRow *)malloc(sizeof(struct CSVRow));
    row->fields = (char **)malloc(MAX_LENGTH*sizeof(char *));
    memset(row->fields, '\0', MAX_LENGTH);

    token = strtok(line, DELIMITER);
    while(token != NULL) 
    {
        row->fields[numOfFields] = strdup(token);
        numOfFields++;
        token = strtok(NULL, DELIMITER);
    }

    row->numOfFields = numOfFields;

    return row;
}

int main()
{
    FILE *file = NULL;
    char filename[MAX_LENGTH];
    struct CSVRow *row = NULL;

    printf("Enter csv file name:");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("Unable to open file!");
        return 1;
    }

    while(!feof(file)) 
    {
        row = readCSVRow(file);
        printf("CSVRow(%d Fields):\n", row->numOfFields);

        int i;
        for (i = 0; i < row->numOfFields; i++)
            printf("Field[%d] = %s\n", i, row->fields[i]);

        freeCSVRow(row);
    }

    fclose(file);
    return 0;
}