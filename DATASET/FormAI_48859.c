//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int probability = 0;
    srand(time(0));
    
    // Let's start with some energy!
    printf("Welcome to the Alien Invasion Probability Calculator! \n");
    printf("Let's ignite some energy and calculate the probability of an imminent alien invasion! \n");

    // Ask for user input
    printf("Please enter the current world population: ");
    int population;
    scanf("%d", &population);

    printf("Please enter the number of reported UFO sightings in the last year: ");
    int ufo_sightings;
    scanf("%d", &ufo_sightings);

    printf("Please enter the number of alien movies released in the last year: ");
    int alien_movies;
    scanf("%d", &alien_movies);

    // Calculate probability
    probability = (ufo_sightings * alien_movies) / population * 100;

    // Generate a random factor
    int factor = rand() % 100;

    // Apply the factor to the probability
    probability = probability * factor;

    printf("Calculating probability with alien movie factor of %d... \n", factor);
    printf("Probability of an alien invasion is %d%%. \n", probability);

    // Let's have some fun!
    if (probability < 20) {
        printf("Don't worry, humans, the probability is very low! \n");
        printf("Let's have some tacos instead to celebrate. \n");
    }
    else if (probability >= 20 && probability < 50) {
        printf("Hmm, the probability is moderate. \n");
        printf("Maybe we should start learning alien language just in case. \n");
    }
    else if (probability >= 50 && probability < 80) {
        printf("The probability is high, humans! \n");
        printf("Quick, let's build a bunker and get ready for the invasion. \n");
    }
    else {
        printf("The probability is extremely high! \n");
        printf("It's time to pack our bags and start colonizing Mars. \n");
    }

    return 0;
}