//FormAI DATASET v1.0 Category: Poker Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the player's cards
void printCards(int cards[]) {
    printf("Your Cards: ");
    for (int i = 0; i < 5; i++) {
        switch (cards[i]) {
            case 1:
                printf("A ");
                break;
            case 11:
                printf("J ");
                break;
            case 12:
                printf("Q ");
                break;
            case 13:
                printf("K ");
                break;
            default:
                printf("%d ", cards[i]);
        }
    }
    printf("\n\n");
}

// Function to check if the player has a pair of cards
int isPair(int cards[]) {
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (cards[i] == cards[j]) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if the player has three of a kind
int isThreeOfAKind(int cards[]) {
    for (int i = 0; i < 3; i++) {
        if (cards[i] == cards[i+1] && cards[i] == cards[i+2]) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the player has a straight
int isStraight(int cards[]) {
    for (int i = 0; i < 4; i++) {
        if (cards[i+1] - cards[i] != 1) {
            return 0;
        }
    }
    return 1;
}

// Function to check if the player has a flush
int isFlush(char suits[]) {
    for (int i = 1; i < 5; i++) {
        if (suits[i] != suits[0]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int deck[52] = {1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13,1,2,3,4,5,6,7,8,9,10,11,12,13};
    char suits[5] = {'H', 'D', 'S', 'C', 'H'};
    int cards[5];
    char input;

    srand(time(NULL));

    do {
        // Shuffle the deck
        for (int i = 0; i < 52; i++) {
            int j = rand() % 52;
            int temp = deck[i];
            deck[i] = deck[j];
            deck[j] = temp;
        }

        // Deal the cards to the player
        for (int i = 0; i < 5; i++) {
            cards[i] = deck[i];
        }

        // Sort the cards in ascending order
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (cards[i] > cards[j]) {
                    int temp = cards[i];
                    cards[i] = cards[j];
                    cards[j] = temp;
                }
            }
        }

        // Print the player's cards
        printCards(cards);

        // Check for winning hands
        if (isFlush(suits) && isStraight(cards)) {
            printf("You have a straight flush!\n");
        } else if (isThreeOfAKind(cards)) {
            printf("You have three of a kind!\n");
        } else if (isFlush(suits)) {
            printf("You have a flush!\n");
        } else if (isStraight(cards)) {
            printf("You have a straight!\n");
        } else if (isPair(cards)) {
            printf("You have a pair!\n");
        } else {
            printf("You have a high card.\n");
        }

        // Ask the player if they want to play again
        printf("Do you want to play again? (Y/N) ");
        scanf(" %c", &input);
        printf("\n");
    } while (input == 'Y' || input == 'y');

    return 0;
}