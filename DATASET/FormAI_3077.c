//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int human_population, alien_population, invasion_probability;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    printf("Please enter the current human population of Earth: ");
    scanf("%d", &human_population);

    //The following code will generate a random number between 1 and 100 for the alien population
    srand(time(NULL)); //This line ensures that the random number generated is truly random and not the same every time the program runs
    alien_population = rand() % 100 + 1;
    printf("Based on our analysis, the current alien population in the universe is approximately %d.\n", alien_population);

    //Calculate the invasion probability based on the human and alien populations
    invasion_probability = (alien_population * 1000000) / human_population; //Assuming that each alien invasion force consists of one million aliens

    printf("The current probability of an alien invasion of Earth is %d%%.\n", invasion_probability);

    if(invasion_probability > 50) { //If the probability of invasion is greater than 50%, there is a high chance of invasion
        printf("Unfortunately, based on our calculations, the probability of an alien invasion of Earth is very high.\n");
    } else {
        printf("Luckily, based on our calculations, the probability of an alien invasion of Earth is relatively low.\n");
    }

    return 0;
}