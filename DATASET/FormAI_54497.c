//FormAI DATASET v1.0 Category: Temperature monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temp[10], sum = 0, avg;
    int i, n;

    printf("Enter the number of temperature values you want to enter (max 10): ");
    scanf("%d", &n);

    // Inputting temperature values
    for(i=0; i<n; i++)
    {
        printf("Enter temperature %d: ", i+1);
        scanf("%f", &temp[i]);
    }

    // Calculating sum of temperature values
    for(i=0; i<n; i++)
    {
        sum += temp[i];
    }

    // Calculating average of temperature values
    avg = sum/n;

    printf("The average temperature is: %.2f\n", avg);

    // Checking temperature values against average and categorizing
    for(i=0; i<n; i++)
    {
        if(temp[i] < avg)
        {
            printf("Temperature %d is below average.\n", i+1);
        }
        else if(temp[i] == avg)
        {
            printf("Temperature %d is at average.\n", i+1);
        }
        else
        {
            printf("Temperature %d is above average.\n", i+1);
        }
    }

    return 0;
}