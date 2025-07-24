//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 256
#define MAX_FIELDS 10

int main()
{
    char filename[MAX_FIELD_SIZE], line[MAX_LINE_SIZE];
    char delim[] = ",";
    char *field;

    printf("Enter the filename: ");
    fgets(filename, MAX_FIELD_SIZE, stdin);
    filename[strcspn(filename, "\n")] = 0; //remove newline character from the end of the string

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    int field_count = 0, line_count = 0;

    while (fgets(line, MAX_LINE_SIZE, fp) != NULL)
    {
        line[strcspn(line, "\n")] = 0; //remove newline character from the end of the string

        printf("Line %d: ", line_count+1);

        field = strtok(line, delim); //tokenize line by comma
        while (field != NULL && field_count < MAX_FIELDS)
        {
            printf("%s, ", field); //print each field
            field_count++;
            field = strtok(NULL, delim);
        }

        printf("\n");

        field_count = 0;
        line_count++;
    }

    fclose(fp);

    return 0;
}