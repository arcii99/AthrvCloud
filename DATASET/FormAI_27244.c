//FormAI DATASET v1.0 Category: Data mining ; Style: lively
#include <stdio.h>
#include <stdlib.h>

//function prototypes
void load_data(FILE *fp, float data[][5], int rows);
void print_data(float data[][5], int rows);
float *calc_averages(float data[][5], int rows);
float *calc_standard_deviations(float data[][5], float *averages, int rows);

int main()
{
    //open file to read data
    FILE *data_file;
    data_file = fopen("data.csv", "r");
    
    //check if file exists
    if (data_file == NULL)
    {
        printf("Error: File not found\n");
        exit(1);
    }
    
    //set number of rows in data set
    int rows = 10;
    
    //declare 2D array for data
    float data[rows][5];
    
    //load data from file into array
    load_data(data_file, data, rows);
    
    //print data to console
    printf("Data set:\n");
    print_data(data, rows);
    
    //calculate averages for each column
    float *averages = calc_averages(data, rows);
    
    //calculate standard deviations for each column
    float *std_devs = calc_standard_deviations(data, averages, rows);
    
    //print results to console
    printf("Averages: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%.2f ", averages[i]);
    }
    printf("\n");
    
    printf("Standard deviations: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%.2f ", std_devs[i]);
    }
    printf("\n");
    
    //free memory used by arrays
    free(averages);
    free(std_devs);
    
    //close file
    fclose(data_file);
    
    return 0;
}

//function to load data from file into array
void load_data(FILE *fp, float data[][5], int rows)
{
    char buffer[1024];
    int row = 0;
    int col = 0;
    
    while (fgets(buffer, 1024, fp))
    {
        char *field = strtok(buffer, ",");
        
        while (field)
        {
            data[row][col++] = atof(field);
            field = strtok(NULL, ",");
        }
        
        col = 0;
        row++;
    }
}

//function to print data to console
void print_data(float data[][5], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%.2f ", data[i][j]);
        }
        printf("\n");
    }
}

//function to calculate average for each column
float *calc_averages(float data[][5], int rows)
{
    float *averages = malloc(sizeof(float) * 5);
    
    for (int i = 0; i < 5; i++)
    {
        float sum = 0;
        
        for (int j = 0; j < rows; j++)
        {
            sum += data[j][i];
        }
        
        averages[i] = sum / rows;
    }
    
    return averages;
}

//function to calculate standard deviation for each column
float *calc_standard_deviations(float data[][5], float *averages, int rows)
{
    float *std_devs = malloc(sizeof(float) * 5);
    
    for (int i = 0; i < 5; i++)
    {
        float sum = 0;
        
        for (int j = 0; j < rows; j++)
        {
            sum += (data[j][i] - averages[i]) * (data[j][i] - averages[i]);
        }
        
        std_devs[i] = sqrt(sum / rows);
    }
    
    return std_devs;
}