//FormAI DATASET v1.0 Category: Data mining ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float data[5][3] = {{ 8.5, 12.3, 16.7 },
                        { 9.5, 11.5, 16.2 },
                        { 9.6, 10.1, 13.2 },
                        { 10.5, 14.2, 15.4 },
                        { 11.1, 12.8, 14.6 }};
    int i, j, k;
    float avg[3] = {0,0,0};
    float std_deviation[3] = {0,0,0};
    
    // calculate the average of each attribute
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            avg[j] += data[i][j];
        }
    }
    for(i=0;i<3;i++)
    {
        avg[i] /= 5;
    }
    
    // calculate the standard deviation of each attribute
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {   
            std_deviation[j] += (data[i][j] - avg[j]) * (data[i][j] - avg[j]);
        }
    }
    for(i=0;i<3;i++)
    {
        std_deviation[i] = sqrt(std_deviation[i]/5);
    }
    
    // print the results
    printf("The average attributes are:\n");
    for(i=0;i<3;i++)
    {
        printf("Attribute %d: %f\n", i+1, avg[i]);
    }
    printf("\nThe standard deviations of the attributes are:\n");
    for(i=0;i<3;i++)
    {
        printf("Attribute %d: %f\n", i+1, std_deviation[i]);
    }
    
    return 0;
}