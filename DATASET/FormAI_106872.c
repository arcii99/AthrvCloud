//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    printf("\n***Welcome to the Alien Invasion Probability Calculator***\n");
    printf("\nWe will calculate the probability of an alien invasion based on a few parameters.\n");

    int num_ufos, num_aliens, num_days;
    float planet_distance;
    srand(time(0));

    printf("\nEnter the number of UFOs seen in the last month: ");
    scanf("%d", &num_ufos);
    printf("\nEnter the estimated number of aliens in the UFOs: ");
    scanf("%d", &num_aliens);
    printf("\nEnter the estimated distance of your planet from the aliens' planet (in light years): ");
    scanf("%f", &planet_distance);
    printf("\nEnter the number of days since the last UFO sighting: ");
    scanf("%d", &num_days);

    if(num_ufos< 0 || num_aliens < 0 || planet_distance <=0 || num_days <= 0) {
        printf("\nInvalid parameters entered. Exiting program...");
        exit(1);
    }

    int random_value = rand() % 100;
    float probability = (((float)(num_ufos*num_aliens)) / ((planet_distance * planet_distance) * num_days)) + random_value;

    printf("\nCalculating probability....\n");
    printf("\nProbability of an alien invasion: %.2f%%\n", probability);

    if(probability >= 50) {
        printf("\nALERT! The probability of an alien invasion is high. Take necessary precautions.\n");
    }

    printf("\nThank you for using the Alien Invasion Probability Calculator!\n");
    
    return 0;
}