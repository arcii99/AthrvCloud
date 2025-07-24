//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int random_num = rand() % 100 + 1; // generate random number from 1 to 100
    int danger_level = 0; // initialize danger level to 0

    // print introduction
    printf("Greetings, noble citizen! I am the Alien Invasion Probability Calculator, here to determine the likelihood of an alien invasion in your kingdom.\n");
    printf("Please answer the following questions truthfully...\n\n");

    // get user input
    printf("Question 1: Have you seen any strange lights in the sky?\n");
    printf("0 = No, 1 = Yes\n");
    int answer1;
    scanf("%d", &answer1);

    printf("Question 2: Have you heard any unusual noises in the night?\n");
    printf("0 = No, 1 = Yes\n");
    int answer2;
    scanf("%d", &answer2);

    printf("Question 3: Have you noticed any unusual activity or sightings in the nearby forests or mountains?\n");
    printf("0 = No, 1 = Yes\n");
    int answer3;
    scanf("%d", &answer3);

    // calculate danger level based on user input
    danger_level += answer1;
    danger_level += answer2 * 2;
    danger_level += answer3 * 3;

    // calculate final probability of alien invasion
    int probability = random_num + danger_level;
    printf("\n\nHmm...my calculations show that there is a %d%% chance of an alien invasion in your kingdom.\n", probability);

    // print conclusion
    if (probability < 50) {
        printf("Fear not, noble citizen! The likelihood of an alien invasion is low. Enjoy your day!\n");
    } else {
        printf("I must warn you, noble citizen, that the likelihood of an alien invasion is high. You may want to prepare your army for battle.\n");
    }
    
    return 0;
}