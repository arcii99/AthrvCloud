//FormAI DATASET v1.0 Category: Weather simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
    int i, j, k;
    int temp[5][5];
    srand(time(NULL));

    // generate random temperatures
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            temp[i][j] = rand() % 51 - 10;
        }
    }

    // display temperature chart
    printf("Temperature Chart (Celsius):\n");
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("%d\t", temp[i][j]);
        }
        printf("\n");
    }

    // calculate highest temperature in each row
    int max_temp_row;
    for(i = 0; i < 5; i++)
    {
        max_temp_row = temp[i][0];
        for(j = 0; j < 5; j++)
        {
            if(temp[i][j] > max_temp_row)
            {
                max_temp_row = temp[i][j];
            }
        }
        printf("Highest Temperature in Row %d: %d C\n", i+1, max_temp_row);
    }

    // calculate average temperature in each column
    float avg_temp_col;
    for(j = 0; j < 5; j++)
    {
        avg_temp_col = 0;
        for(i = 0; i < 5; i++)
        {
            avg_temp_col += temp[i][j];
        }
        avg_temp_col /= 5.0;
        printf("Average Temperature in Column %d: %.1f C\n", j+1, avg_temp_col);
    }

    // determine if there is a temperature greater than 40 C
    int high_temp_flag = 0;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(temp[i][j] > 40)
            {
                high_temp_flag = 1;
                break;
            }
        }
    }
    if(high_temp_flag == 1)
    {
        printf("There is at least one temperature greater than 40 C.\n");
    }
    else
    {
        printf("There is no temperature greater than 40 C.\n");
    }

    return 0;
}