//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 50
#define MAX_ROWS 1000
#define MAX_FIELD_SIZE 100

typedef struct record
{
    char fields[MAX_COLUMNS][MAX_FIELD_SIZE];
    int num_fields;
} Record;

int read_csv(char* filename, Record* records, int max_rows, int max_columns);
void print_records(Record* records, int num_rows);

int main()
{
    Record records[MAX_ROWS];
    int num_rows = read_csv("data.csv", records, MAX_ROWS, MAX_COLUMNS);

    if(num_rows == -1)
    {
        printf("Error opening CSV file.\n");
        exit(1);
    }

    print_records(records, num_rows);

    return 0;
}

int read_csv(char* filename, Record* records, int max_rows, int max_columns)
{
    FILE* fp;
    char line[MAX_FIELD_SIZE * MAX_COLUMNS];
    char* field;
    int i, j;

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        return -1;
    }

    i = 0;

    while(fgets(line, sizeof line, fp) && i < max_rows)
    {
        j = 0;

        field = strtok(line, ",");

        while(field != NULL && j < max_columns)
        {
            strcpy(records[i].fields[j], field);
            records[i].num_fields = j + 1;

            field = strtok(NULL, ",");
            j++;
        }

        i++;
    }

    fclose(fp);

    return i;
}

void print_records(Record* records, int num_rows)
{
    int i, j;

    for(i = 0; i < num_rows; i++)
    {
        for(j = 0; j < records[i].num_fields; j++)
        {
            printf("%s ", records[i].fields[j]);
        }

        printf("\n");
    }
}