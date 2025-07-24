//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int chance;
    srand(time(NULL));
    chance = rand() % 101;

    printf("ALERT! ALERT! ALIEN INVASION PROBABILITY CALCULATOR ACTIVATED!\n");
    printf("Initializing probability calculation...\n\n");
    
    printf("Calculating probability...\n");
    printf("Probability of alien invasion: %d%%\n\n", chance);
    
    if (chance <= 25) {
        printf("Probability of an alien invasion is quite low, but still possible. Stay vigilant!\n");
    } else if (chance <= 50) {
        printf("Probability of an alien invasion is moderate. Please take necessary precautions.\n");
    } else if (chance <= 75) {
        printf("Probability of an alien invasion is quite high. Start preparing for the worst!\n");
    } else {
        printf("Probability of an alien invasion is extremely high. EVACUATE IMMEDIATELY!\n");
    }
    
    printf("\nRemember, this is only a probability calculator and results should not be taken as fact.\n");
    printf("Always be prepared for the unexpected. Good luck!\n");

    return 0;
}