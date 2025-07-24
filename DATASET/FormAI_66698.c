//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define the maximum length of each line in the csv file
#define MAX_LINE_LENGTH 100

//define the maximum number of columns in the csv file
#define MAX_COLUMNS 10

//define the maximum number of rows in the csv file
#define MAX_ROWS 100

int main()
{
    //open the csv file for reading
    FILE *csv_file = fopen("data.csv", "r");

    //check if the file was successfully opened
    if (csv_file == NULL)
    {
        printf("Error: Could not open file!");
        return -1;
    }

    //define variables to store the data from the csv file
    char line[MAX_LINE_LENGTH];
    char *tokens[MAX_COLUMNS];
    int rows = 0;
    int columns = 0;
    float data[MAX_ROWS][MAX_COLUMNS];

    //loop through each line in the csv file
    while (fgets(line, MAX_LINE_LENGTH, csv_file) != NULL)
    {
        //split the line into tokens based on the comma delimiter
        char *token = strtok(line, ",");
        while (token != NULL)
        {
            //store the token in the tokens array
            tokens[columns] = token;

            //convert the token to a float and store it in the data array
            data[rows][columns] = atof(token);

            //increment the number of columns
            columns++;

            //get the next token
            token = strtok(NULL, ",");
        }

        //increment the number of rows
        rows++;

        //reset the number of columns for the next row
        columns = 0;
    }

    //close the csv file
    fclose(csv_file);

    //print out the data from the csv file
    printf("Data from the csv file:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%.2f ", data[i][j]);
        }
        printf("\n");
    }

    return 0;
}