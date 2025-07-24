//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int prob;
    srand(time(NULL)); // Setting seed value for random number generator
    
    printf("Alien Invasion Probability Calculation Program\n");
    printf("Enter the current year: ");
    int year;
    scanf("%d", &year);
    
    // Calculating the probability of alien invasion based on the current year
    if (year >= 2022 && year <= 2025)
    {
        prob = 80 + rand() % 21; // Probability range: 80-100%
    }
    else if (year >= 2026 && year <= 2030)
    {
        prob = 60 + rand() % 21; // Probability range: 60-80%
    }
    else if (year >= 2031 && year <= 2040)
    {
        prob = 30 + rand() % 31; // Probability range: 30-60%
    }
    else if (year >= 2041 && year <= 2050)
    {
        prob = 10 + rand() % 21; // Probability range: 10-30%
    }
    else
    {
        prob = rand() % 11; // Probability range: 0-10%
    }
    
    printf("\nBased on the current year, the probability of alien invasion is %d%%.\n", prob);
    printf("However, please note that this is a fictional program and should not be taken seriously.\n");
    
    return 0;
}