//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between two given values
int generateRandomNumber(int lower, int upper)
{
    int num;
    num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    int probability[5] = {0, 0, 0, 0, 0}; // Initialize array to 0
    int years = 100; // Number of years for probability calculation
    
    // Seed for random number generation
    srand(time(0));
    
    // Loop through the number of years specified
    for(int i=0; i<years; i++)
    {
        // Generate a random number from 1 to 100
        int randNum = generateRandomNumber(1,100);
        
        // If the number is less than or equal to 20, the probability of an invasion is high
        if(randNum <= 20)
        {
            probability[0]++; // Increment index 0
        }
        // If the number is between 21 and 40, the probability of an invasion is medium high
        else if(randNum > 20 && randNum <= 40)
        {
            probability[1]++; // Increment index 1
        }
        // If the number is between 41 and 60, the probability of an invasion is medium
        else if(randNum > 40 && randNum <= 60)
        {
            probability[2]++; // Increment index 2
        }
        // If the number is between 61 and 80, the probability of an invasion is medium low
        else if(randNum > 60 && randNum <= 80)
        {
            probability[3]++; // Increment index 3
        }
        // If the number is greater than 80, the probability of an invasion is low
        else if(randNum > 80)
        {
            probability[4]++; // Increment index 4
        }
    }
    
    // Calculate the percentage likelihood for each probability range
    float highProb = ((float) probability[0] / years) * 100;
    float medHighProb = ((float) probability[1] / years) * 100;
    float medProb = ((float) probability[2] / years) * 100;
    float medLowProb = ((float) probability[3] / years) * 100;
    float lowProb = ((float) probability[4] / years) * 100;
    
    // Print the results
    printf("Probability of Alien Invasion Within the Next 100 Years:\n");
    printf("High: %.2f%%\n", highProb);
    printf("Medium High: %.2f%%\n", medHighProb);
    printf("Medium: %.2f%%\n", medProb);
    printf("Medium Low: %.2f%%\n", medLowProb);
    printf("Low: %.2f%%\n", lowProb);
    
    return 0;
}