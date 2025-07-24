//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    int age, experience, intelligence, fear, probability;
    srand(time(0)); // seeding the random number generator

    printf("Welcome to the Alien Invasion Probability Calculator.\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! Please answer the following questions to calculate the probability of an alien invasion.\n\n", name);

    printf("What is your age? ");
    scanf("%d", &age);

    printf("How many years of experience do you have in your field? ");
    scanf("%d", &experience);

    printf("On a scale of 1-10, how intelligent would you say you are? ");
    scanf("%d", &intelligence);

    printf("On a scale of 1-10, how afraid are you of an alien invasion? ");
    scanf("%d", &fear);

    probability = (rand() % 90) + 10; // generating a random probability between 10-99
    probability -= (10 - intelligence) * 3; // subtracting points for low intelligence
    probability -= (fear * 2); // subtracting points for high fear
    probability += (experience * 2); // adding points for experience

    printf("\nCalculating probability...\n\n");
    printf("Based on your answers, the probability of an alien invasion is %d%%.\n", probability);

    if(probability >= 50) {
        printf("It seems that you are at risk! Take necessary precautions and be ready for any situation.\n");
    }
    else {
        printf("You are not at much of a risk, but it is always better to be prepared.\n");
    }

    return 0;
}