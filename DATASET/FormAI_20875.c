//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float asteroid_threat(float alien_tech_factor, int earth_defences, int alien_fleet_size, int human_population);

int main()
{
    int earth_defences, alien_fleet_size, human_population;
    float alien_tech_factor;

    // get user input
    printf("Enter Earth defence technology level (0-100): ");
    scanf("%d", &earth_defences);
    printf("Enter Alien technology factor (0.0-1.0): ");
    scanf("%f", &alien_tech_factor);
    printf("Enter Alien fleet size (number of ships): ");
    scanf("%d", &alien_fleet_size);
    printf("Enter Human population (in millions): ");
    scanf("%d", &human_population);

    // calculate probability of invasion
    float invasion_prob = asteroid_threat(alien_tech_factor, earth_defences, alien_fleet_size, human_population);

    // print result
    printf("\n\nThe probability of an alien invasion is: %.2f%%\n", invasion_prob*100);

    return 0;
}

float asteroid_threat(float alien_tech_factor, int earth_defences, int alien_fleet_size, int human_population)
{
    // calculate random asteroid threat factor
    srand(time(NULL));
    float asteroid_factor = (float)(rand()%101)/100;

    // calculate probability of invasion
    float prob = ((100 - earth_defences)*0.5 + alien_tech_factor*0.3 + asteroid_factor*0.2)*(1 - 0.2*alien_fleet_size/human_population);

    return prob;
}