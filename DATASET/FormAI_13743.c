//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You find yourself standing in front of a haunted house.\n");
    printf("Do you dare to step inside?\n");
    printf("(Enter 1 for yes, 0 for no): ");

    int choice;
    scanf("%d", &choice);

    if (choice != 1) {
        printf("Too scared? Come back when you're ready.\n");
    } else {
        srand(time(NULL));
        int ghostChance = rand() % 10 + 1;

        printf("\nYou step inside the haunted house...\n");

        if (ghostChance >= 5) {
            printf("There's a chill in the air and you hear strange whispers...\n");
            printf("Suddenly, a ghost appears and scares you half to death!\n");
        } else {
            printf("You cautiously explore the house but it seems empty...\n");
            printf("Or is it?\n");
            printf("You hear creaking sounds and footsteps in the distance...\n");
            printf("You turn a corner and come face to face with a...bat!\n");
        }
    }

    printf("\nThanks for playing! Would you like to play again?\n");
    printf("(Enter 1 for yes, 0 for no): ");

    int playAgain;
    scanf("%d", &playAgain);

    if (playAgain == 1) {
        main();
    } else {
        printf("Goodbye!");
    }

    return 0;
}