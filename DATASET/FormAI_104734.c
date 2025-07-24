//FormAI DATASET v1.0 Category: Data mining ; Style: invasive
#include<stdio.h>

int main()
{
    // Declare and initialize variables
    int numData, maxData, minData, sumData = 0;
    float avgData;
    
    // Get number of data from user
    printf("Enter number of data: ");
    scanf("%d", &numData);
    
    // Initialize maxData and minData with first data
    printf("Enter data 1: ");
    scanf("%d", &maxData);
    minData = maxData;
    
    // Loop through remaining data to find max, min and sum
    for(int i=2; i<=numData; i++)
    {
        int data;
        printf("Enter data %d: ", i);
        scanf("%d", &data);
        
        if(data > maxData)
        {
            maxData = data; // Update maxData
        }
        
        if(data < minData)
        {
            minData = data; // Update minData
        }
        
        sumData += data; // Update sumData
    }
    
    // Calculate average
    avgData = (float)sumData / numData;
    
    // Print results
    printf("\n");
    printf("Maximum data: %d\n", maxData);
    printf("Minimum data: %d\n", minData);
    printf("Sum of data: %d\n", sumData);
    printf("Average of data: %.2f\n", avgData);
    
    return 0;
}