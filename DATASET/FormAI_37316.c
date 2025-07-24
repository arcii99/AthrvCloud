//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_of_incidents;
    float total_distance_covered = 0.0f;
    float avg_distance_covered, probability_of_invasion;

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Enter the number of alien sighting incidents in the past year: ");
    scanf("%d", &num_of_incidents);

    float distances[num_of_incidents];

    // Generate distances randomly up to 1000 light years
    srand(time(NULL));
    for (int i = 0; i < num_of_incidents; i++)
    {
        float distance = rand() % 1000 + 1;
        distances[i] = distance;
        total_distance_covered += distance;
    }

    avg_distance_covered = total_distance_covered / (float)num_of_incidents;
    probability_of_invasion = (float)num_of_incidents / avg_distance_covered;

    printf("\nThe average distance covered by the aliens in the past year is: %.2f light years\n", avg_distance_covered);
    printf("The probability of an alien invasion is: %.2f%%\n", probability_of_invasion * 100);

    return 0;
}