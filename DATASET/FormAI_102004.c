//FormAI DATASET v1.0 Category: Weather simulation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0)); // seeding the random number generator with time

    // Declaring the variables
    float temperature;
    int i, j, random_num;

    // Initializing the temperature array with random values
    float temperature_arr[10][10];
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            random_num = rand() % 100; // generating random number between 0 to 99
            temperature = (float)random_num / 10; // converting the random number to float
            temperature_arr[i][j] = temperature; // storing the temperature value in the array
        }
    }

    // Displaying the temperature values
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            printf("%.1f ", temperature_arr[i][j]);
        }
        printf("\n");
    }

    // Finding the average temperature of each row
    float avg_temp_row[10];
    for(i=0; i<10; i++)
    {
        float sum = 0;
        for(j=0; j<10; j++)
        {
            sum += temperature_arr[i][j];
        }
        avg_temp_row[i] = sum / 10;
    }

    // Displaying the average temperature of each row
    printf("\n");
    for(i=0; i<10; i++)
    {
        printf("Average temperature of row %d: %.1f\n", i, avg_temp_row[i]);
    }

    // Finding the average temperature of each column
    float avg_temp_col[10];
    for(j=0; j<10; j++)
    {
        float sum = 0;
        for(i=0; i<10; i++)
        {
            sum += temperature_arr[i][j];
        }
        avg_temp_col[j] = sum / 10;
    }

    // Displaying the average temperature of each column
    printf("\n");
    for(j=0; j<10; j++)
    {
        printf("Average temperature of column %d: %.1f\n", j, avg_temp_col[j]);
    }

    return 0;
}