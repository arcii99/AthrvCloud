//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 20


int main(int argc, char* argv[])
{
    FILE* file;
    char line[MAX_LINE_LENGTH];
    char* field = NULL;
    char* fields[MAX_FIELDS];
    int i = 0, n = 0;

    if(argc < 2)
    {
        printf("Usage: %s filename.csv\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if(file == NULL)
    {
        printf("Cannot open file: %s\n", argv[1]);
        return 1;
    }

    while(fgets(line, MAX_LINE_LENGTH, file))
    {
        n = 0;

        field = strtok(line, ",");

        while(field && n < MAX_FIELDS)
        {
            fields[n++] = strdup(field);
            field = strtok(NULL, ",");
        }

        for(i = 0; i < n; i++)
        {
            printf("%s\t", fields[i]);
            free(fields[i]);
        }

        printf("\n");
    }

    fclose(file);

    return 0;
}