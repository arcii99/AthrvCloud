//FormAI DATASET v1.0 Category: Memory Game ; Style: light-weight
// C Memory Game Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int cards[20] = {0}; // array to hold the cards
    int chosen[2] = {0}; // array to hold the two chosen cards
    int pairs_found = 0; // counter for the number of pairs found
    int tries = 0; // counter for the number of tries made

    // populate the cards array with pairs of numbers from 1 to 10
    for (int i = 1; i <= 10; i++) {
        int card1, card2; // variables to hold the two cards
        do {
            card1 = rand() % 20;
        } while (cards[card1] != 0);
        do {
            card2 = rand() % 20;
        } while (cards[card2] != 0 || card2 == card1);
        cards[card1] = i;
        cards[card2] = i;
    }

    // shuffle the cards array
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        int temp = cards[i];
        int j = rand() % 20;
        cards[i] = cards[j];
        cards[j] = temp;
    }

    // main game loop
    while (pairs_found < 10) {
        // print the current state of the game board
        printf("---------------------\n");
        for (int i = 0; i < 20; i++) {
            if (chosen[0] == i || chosen[1] == i) {
                printf("%2d* ", cards[i]);
            } else if (cards[i] == 0) {
                printf("    ");
            } else {
                printf("%2d  ", cards[i]);
            }
            if (i % 5 == 4) {
                printf("\n");
            }
        }
        printf("---------------------\n");

        // get input from the player
        int input;
        do {
            printf("Choose a card to reveal (1-20): ");
            scanf("%d", &input);
        } while (input < 1 || input > 20 || cards[input - 1] == 0 || chosen[0] == input - 1 || chosen[1] == input - 1);

        // reveal the chosen card
        printf("You chose card %d, which is a %d.\n", input, cards[input - 1]);
        chosen[tries % 2] = input - 1;
        tries++;

        // check if the two chosen cards match
        if (tries % 2 == 0 && cards[chosen[0]] == cards[chosen[1]]) {
            printf("You found a pair!\n");
            cards[chosen[0]] = 0;
            cards[chosen[1]] = 0;
            pairs_found++;
        } else if (tries % 2 == 0) {
            printf("Those cards don't match. Try again.\n");
        }
    }

    // print the final state of the game board
    printf("Congratulations, you found all the pairs!\n");
    printf("---------------------\n");
    for (int i = 0; i < 20; i++) {
        printf("%2d  ", cards[i]);
        if (i % 5 == 4) {
            printf("\n");
        }
    }
    printf("---------------------\n");

    return 0;
}