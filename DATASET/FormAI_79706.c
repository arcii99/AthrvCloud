//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int ships = rand() % 100 + 1;
    int planets = rand() % 100 + 1;
    double probability = ((double) ships / (double) planets) * 100.0;
    
    printf("ALERT! ALIEN INVASION PROBABILITY CALCULATOR INITIATED\n");
    printf("Scanning the galaxy...found %d alien ships\n", ships);
    printf("Scanning the galaxy...found %d habitable planets\n", planets);
    printf("Calculating the probability of an alien invasion...\n");
    printf("Drumroll please...\n");
    
    for(int i = 0; i < 3; i++) {
        printf(". ");
        fflush(stdout);
        sleep(1);
    }
    
    printf("\nALERT! ALERT! ALERT! The probability of an alien invasion is %.2f%%\n", probability);
    printf("You have been warned.\n");
    
    return 0;
}