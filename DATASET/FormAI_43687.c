//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please choose a scenario:\n");
    printf("1) Alien invasion with advanced technology\n");
    printf("2) Alien invasion with limited resources\n");
    int choice;
    scanf("%d", &choice);

    srand(time(NULL));
    int probability;
    switch (choice) {
        case 1:
            probability = rand() % 100 + 1;
            if (probability > 75) {
                printf("\nAliens have a high probability of invading Earth with advanced technology.\n");
                printf("It's time to panic and start preparing for the worst.\n");
            } else {
                printf("\nAliens have a low probability of invading Earth with advanced technology.\n");
                printf("But it's better to be safe than sorry, so keep an eye out for signs of an upcoming invasion.\n");
            }
            break;
        case 2:
            probability = rand() % 100 + 1;
            if (probability > 50) {
                printf("\nAliens have a moderate probability of invading Earth with limited resources.\n");
                printf("It's important to prepare for the worst, but don't panic just yet.\n");
            } else {
                printf("\nAliens have a low probability of invading Earth with limited resources.\n");
                printf("There's probably nothing to worry about, but it never hurts to be prepared.\n");
            }
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }

    return 0;
}