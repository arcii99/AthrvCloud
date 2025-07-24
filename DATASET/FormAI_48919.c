//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_LINE_LEN 1000

/* Function to split the string 'line' based on delimiter ',' and return an array of tokens */
int split_line(char *line, char *delim, char *tokens[])
{
    int num_cols = 0;
    char *token = strtok(line, delim);
    while (token != NULL && num_cols < MAX_COLS)
    {
        tokens[num_cols++] = token;
        token = strtok(NULL, delim);
    }
    return num_cols;
}

/* Main function to read CSV file and print its contents */
int main(int argc, char *argv[])
{
    char *file_name = "example.csv";
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("Error opening file %s\n", file_name);
        return -1;
    }

    char line[MAX_LINE_LEN];
    char *tokens[MAX_COLS];
    int num_cols;

    /* Read and print header row */
    fgets(line, MAX_LINE_LEN, fp);
    num_cols = split_line(line, ",", tokens);
    printf("Header row:\n");
    for (int i = 0; i < num_cols; i++)
    {
        printf("%s ", tokens[i]);
    }
    printf("\n");

    /* Read and print data rows */
    printf("Data rows:\n");
    while (fgets(line, MAX_LINE_LEN, fp) != NULL)
    {
        num_cols = split_line(line, ",", tokens);
        for (int i = 0; i < num_cols; i++)
        {
            printf("%s ", tokens[i]);
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}