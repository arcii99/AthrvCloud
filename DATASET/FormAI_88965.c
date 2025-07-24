//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Alan Touring
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL)); // seeding the random number generator

    float alien_prob, distance, tech_prob, prob; // declaring variables for probability calculation

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    // taking user input for distance from potential alien civilization
    printf("Please enter the distance (in light years) from the potential alien civilization: ");
    scanf("%f", &distance);

    // calculating probability of the aliens existing based on the distance from their civilization
    alien_prob = pow(1.0/(distance+1), 2);

    // taking user input for the level of technology of the potential alien civilization
    printf("\nPlease enter the level of technology (1-5, 5 being the most advanced) of the potential alien civilization: ");
    int tech_level;
    scanf("%d", &tech_level);

    // calculating probability of the aliens possessing advanced technology based on their tech level
    tech_prob = (float)tech_level/5;

    // calculating the overall probability of an alien invasion
    prob = alien_prob*tech_prob*(rand()%101)/100; // generating a random number for unpredictability

    // displaying the results
    printf("\n\n\nResults: \n\n");
    printf("Probability of the aliens existing: %f\n", alien_prob);
    printf("Probability of the aliens possessing advanced technology: %f\n", tech_prob);
    printf("Overall probability of an alien invasion: %f\n", prob);

    return 0; // end of program
}