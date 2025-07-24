//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_COLUMNS 20
#define MAX_COLUMN_LENGTH 100

int main()
{
    char filename[100];
    printf("Enter the CSV file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Failed to open file %s\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    int num_columns = 0;
    char columns[MAX_NUM_COLUMNS][MAX_COLUMN_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp))
    {
        // Remove the newline character at the end of the line
        line[strlen(line) - 1] = '\0';

        // Split the line into individual columns
        char *column = strtok(line, ",");
        int col_count = 0;
        while (column != NULL)
        {
            strncpy(columns[col_count], column, MAX_COLUMN_LENGTH);
            col_count++;
            column = strtok(NULL, ",");
        }

        // If this is the first line, save the number of columns
        if (line_count == 0)
        {
            num_columns = col_count;
            printf("Number of columns: %d\n", num_columns);
        }
        else if (num_columns != col_count)
        {
            printf("Error: Line %d has %d columns instead of %d\n", line_count, col_count, num_columns);
            return 1;
        }

        // Print the columns for this line
        printf("Line %d:\n", line_count);
        for (int i = 0; i < num_columns; i++)
        {
            printf("%s\n", columns[i]);
        }

        line_count++;
    }

    fclose(fp);

    return 0;
}