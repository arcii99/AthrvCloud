//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

float getTemperature();

int main()
{
    float temp, threshold = 10.0; // Threshold for temperature deviation
    int i;

    printf("Welcome to the Sherlock Holmes Temperature Monitor!\n");
    printf("Please keep calm and take a sip of your tea while I analyze your surroundings...\n");

    // Simulating temperature changes
    for(i=0; i<5; i++)
    {
        temp = getTemperature();
        printf("Temperature reading: %.2f\n", temp);
        if(temp > threshold)
        {
            printf("Aha! There seems to be a significant temperature deviation!\n");
        }
    }

    printf("Thank you for using the Sherlock Holmes Temperature Monitor. Enjoy your tea, sir/madam!\n");
    return 0;
}

// Function to simulate temperature readings
float getTemperature()
{
    float temp;
    temp = (float)rand()/(float)(RAND_MAX/20.0) + 15.0; // Temperature range: 15.0 to 35.0
    return temp;
}