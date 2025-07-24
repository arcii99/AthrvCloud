//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("-----------ALIEN INVASION PROBABILITY CALCULATOR-----------\n\n");

    int num_attempts;
    printf("Enter number of invasion attempts to simulate: ");
    scanf("%d", &num_attempts);
    printf("\n");

    srand(time(0)); // seed the random number generator

    int invasion_success_count = 0;

    for(int i = 0; i < num_attempts; i++)
    {
        int invasion_probability = rand() % 101; // generate a random number between 0 and 100 to represent invasion probability
        printf("Invasion probability for attempt %d: %d%%\n", i+1, invasion_probability);

        if(invasion_probability >= 75) // if invasion probability is 75% or higher, invasion is considered a success
        {
            printf("ALIEN INVASION SUCCESSFUL!\n");
            invasion_success_count++;
        }
        else
        {
            printf("ALIEN INVASION FAILED\n");
        }

        printf("\n");
    }

    float invasion_success_rate = (float)invasion_success_count / num_attempts * 100; // calculate the invasion success rate

    printf("Out of %d attempts, there were %d successful invasions and %d failed invasions. \n\n", num_attempts, invasion_success_count, num_attempts - invasion_success_count);
    printf("The probability of a successful alien invasion is: %.2f%%\n\n", invasion_success_rate);

    printf("PROGRAM EXITING...\n");
    return 0;
}