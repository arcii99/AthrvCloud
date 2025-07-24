//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 20
 
int main()
{
    char filename[50], line[MAX_LINE_SIZE], *field, *record[MAX_FIELDS];
    int i, j, num_fields;
 
    printf("Enter filename to parse: ");
    scanf("%s", filename);
 
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
 
    while(fgets(line, MAX_LINE_SIZE, fp))
    {
        i = 0;
        field = strtok(line, ",");
        while(field)
        {
            record[i++] = field;
            field = strtok(NULL, ",");
        }
 
        num_fields = i;
        printf("Record with %d fields:\n", num_fields);
 
        for(j = 0; j < num_fields; j++)
        {
            printf("%s ", record[j]);
        }
        printf("\n");
    }
 
    fclose(fp);
    return 0;
}