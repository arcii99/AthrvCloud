//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int probability = rand() % 101; // generates a random number between 0 and 100
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Calculating probability...\n");
    printf("Probability of an alien invasion today is: %d%%\n", probability);
    printf("\n");

    if (probability >= 75) { // high probability of invasion
        printf("Oh no! There is a high probability of an alien invasion today. What should we do?\n");
        printf("Do you want to:\n");
        printf("1. Evacuate the city\n");
        printf("2. Fight back\n");
        printf("3. Hide and hope for the best\n");
        printf("Please enter your choice (1, 2 or 3): ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Good choice! Evacuating the city is the safest option.\n");
                break;
            case 2:
                printf("Are you sure? Fighting back is risky, but brave. Good luck!\n");
                break;
            case 3:
                printf("Hiding might not be the best strategy, but it could work. Stay safe!\n");
                break;
            default:
                printf("Oops! That's not a valid choice.\n");
                break;
        }
    } else if (probability >= 50) { // medium probability of invasion
        printf("There is a medium probability of an alien invasion today. Be on the lookout!\n");
    } else { // low probability of invasion
        printf("Phew! There is a low probability of an alien invasion today. Enjoy your day!\n");
    }

    return 0;
}