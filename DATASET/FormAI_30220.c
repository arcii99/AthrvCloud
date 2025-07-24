//FormAI DATASET v1.0 Category: Temperature monitor ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random float number between given range
float generate(float min, float max)
{
    float num = (float)rand()/(float)(RAND_MAX/(max - min)) + min;
    return num;
}

int main()
{
    // Set seed for generating random numbers
    srand(time(NULL));
    
    float temp = generate(-10.0, 50.0);
    int count = 1;
    
    // Loop for generating temperature readings every 10 seconds
    while(count<=5)
    {
        printf("Temperature reading %d: %.2f degree C\n", count, temp);
        printf("\n");
        
        // Increase count and sleep for 10 seconds
        count++;
        sleep(10);
        
        // Generate new temperature reading for next iteration
        temp = generate(-10.0, 50.0);
    }
    
    return 0;
}