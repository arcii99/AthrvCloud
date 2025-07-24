//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float calculateProbability(float strength, float distance);
void invasionProbability(float probability);

int main()
{
    float strength, distance, probability;
    srand(time(NULL)); //Seed the random number generator with current time
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the strength of the alien fleet (1-10): ");
    scanf("%f", &strength);
    printf("Enter the distance from the alien fleet (in light years): ");
    scanf("%f", &distance);
    
    probability = calculateProbability(strength, distance);
    invasionProbability(probability);

    return 0;
}

float calculateProbability(float strength, float distance)
{
    float randomNumber, probability;
    
    randomNumber = rand() % 100 + 1; //Generate a random number between 1-100
    probability = (strength/distance) * randomNumber;
    
    return probability;
}

void invasionProbability(float probability)
{
    if(probability >= 70.0)
    {
        printf("\nThe probability of an alien invasion is very high (%.2f%%). Please take necessary precautions.", probability);
    }
    else if(probability >= 30.0)
    {
        printf("\nThe probability of an alien invasion is moderate (%.2f%%). Keep an eye on the skies and stay alert.", probability);
    }
    else
    {
        printf("\nThe probability of an alien invasion is low (%.2f%%). However, it is always better to be safe than sorry.", probability);
    }
}