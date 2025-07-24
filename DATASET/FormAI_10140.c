//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to clear terminal screen
void clear_screen() {
    system("clear");
}

// function to wait for user input
void wait_for_input() {
    getchar();
}

int main() {
    // set random seed
    srand(time(NULL));

    // welcome message
    printf("Welcome to Paranoid Mind!\n");
    printf("========================\n");

    // display instructions
    printf("Instructions:\n");
    printf("You are a paranoid person who thinks everyone is against you.\n");
    printf("You are walking on a street and you see people coming towards you.\n");
    printf("You need to decide whether you want to confront them or avoid them.\n");
    printf("If you confront them, they may be hostile and attack you.\n");
    printf("If you avoid them, they may think you are a coward and chase after you.\n");
    printf("You need to make quick decisions and survive as long as possible!\n\n");

    // initialize game variables
    int health = 100;
    int score = 0;
    int round = 1;

    // start game loop
    while (health > 0) {
        // clear screen and display round
        clear_screen();
        printf("Round %d\n", round);

        // generate random number to determine number of people
        int num_people = rand() % 10 + 1;
        printf("You see %d people coming towards you...\n", num_people);

        // prompt user to choose action
        printf("What do you want to do?\n");
        printf("1. Confront them\n");
        printf("2. Avoid them\n");
        int choice = getchar();
        getchar(); // discard newline character

        // handle user choice
        if (choice == '1') {
            // generate random number to determine outcome
            int outcome = rand() % 2;
            if (outcome == 0) {
                printf("The people are hostile and attack you!\n");
                printf("You lose 20 health.\n");
                health -= 20;
            } else {
                printf("The people are friendly and greet you!\n");
                printf("You gain 10 score.\n");
                score += 10;
            }
        } else {
            // generate random number to determine outcome
            int outcome = rand() % 2;
            if (outcome == 0) {
                printf("The people think you are a coward and chase after you!\n");
                printf("You lose 10 score.\n");
                score -= 10;
            } else {
                printf("You successfully avoid the people.\n");
            }
        }

        // display current health and score
        printf("Health: %d\n", health);
        printf("Score: %d\n", score);

        // wait for user input before continuing to next round
        printf("Press Enter to continue...\n");
        wait_for_input();

        // increment round
        round++;
    }

    // end game loop when health reaches 0
    printf("Game over!\n");
    printf("You survived for %d rounds and scored %d points.\n", round - 1, score);

    return 0;
}