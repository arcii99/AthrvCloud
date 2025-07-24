//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random probability value
int generateProbability() {
    srand(time(NULL)); // seed for random number
    int probability = rand() % 101; // generate random number between 0 to 100
    return probability;
}

int main() {
    char name[100];
    printf("Welcome to Alien Invasion Probability Calculator!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello %s! Let's see if you're ready to defend Earth from aliens.\n", name);

    int probability = generateProbability(); // get random probability value

    printf("Calculating probability of alien invasion...\n\n");
    printf("Probability: %d%%\n\n", probability);

    printf("Wait, what?! There's a %d%% chance of an alien invasion?? That's not good!\n", probability);
    printf("We need to take some defensive action ASAP before it's too late...\n\n");

    // check probability value and suggest defensive action
    if (probability < 20) {
        printf("Phew, we're safe for now. Let's just keep a look out for any suspicious activity.\n");
    } else if (probability < 50) {
        printf("We need to start preparing for an alien invasion. Gather the troops and fortify our defenses!\n");
    } else if (probability < 80) {
        printf("Things are looking grim. We need to launch a pre-emptive strike on the aliens before they attack us.\n");
    } else {
        printf("It's official, we are doomed. Let's face it, there's no hope against advanced alien technology.\n");
        printf("In fact, I think it's time to start learning their language and offering ourselves as their pets...\n");
    }

    printf("\nThanks for using Alien Invasion Probability Calculator, %s. Good luck out there!\n", name);

    return 0;
}