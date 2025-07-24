//FormAI DATASET v1.0 Category: Data mining ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_of_rows, num_of_cols, i, j;
    float **data_table;
    FILE *input_file;
    char filename[50];

    printf("Enter the filename with extension: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");

    if(input_file == NULL)
    {
        printf("File not found! Exiting.");
        exit(1);
    }

    // read the number of rows and columns
    fscanf(input_file, "%d %d", &num_of_rows, &num_of_cols);

    // allocate memory for the data table
    data_table = (float**) malloc(num_of_rows * sizeof(float*));
    for(i = 0; i < num_of_rows; i++)
        data_table[i] = (float*) malloc(num_of_cols * sizeof(float));

    // read the data from the file
    for(i = 0; i < num_of_rows; i++)
    {
        for(j = 0; j < num_of_cols; j++)
        {
            fscanf(input_file, "%f", &data_table[i][j]);
        }
    }

    // perform data mining operations here...

    // free the memory allocated for the data table
    for(i = 0; i < num_of_rows; i++)
        free(data_table[i]);
    free(data_table);

    fclose(input_file);

    return 0;
}