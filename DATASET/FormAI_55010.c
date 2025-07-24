//FormAI DATASET v1.0 Category: Poker Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

char *card_names[] = {
    "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
    "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};
char *suit_names[] = {
    "Clubs", "Diamonds", "Hearts", "Spades"
};

struct Card {
    int value; // 0-12 = Ace-King
    int suit;  // 0-3 = Clubs, Diamonds, Hearts, Spades
};
typedef struct Card Card;

int score_hand(Card *hand);
void print_hand(Card *hand);

int main() {
    Card deck[DECK_SIZE];
    int i, j, k, m;

    srand(time(NULL));

    // Initialize the deck
    k = 0;
    for (i=0; i<4; i++) {
        for (j=0; j<13; j++) {
            deck[k].value = j;
            deck[k].suit = i;
            k++;
        }
    }

    // Shuffle the deck
    for (i=0; i<DECK_SIZE; i++) {
        j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Deal the hands
    Card player_hand[HAND_SIZE], computer_hand[HAND_SIZE];
    for (i=0; i<HAND_SIZE; i++) {
        player_hand[i] = deck[i];
        computer_hand[i] = deck[i+HAND_SIZE];
    }

    // Print the hands
    printf("Your hand:\n");
    print_hand(player_hand);
    printf("\nComputer's hand:\n");
    print_hand(computer_hand);

    // Determine the winner
    int player_score = score_hand(player_hand);
    int computer_score = score_hand(computer_hand);
    if (player_score > computer_score) {
        printf("Congratulations, you win!\n");
    } else if (player_score < computer_score) {
        printf("Better luck next time, the computer wins.\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}

int score_hand(Card *hand) {
    // Calculate the score of a hand
    int score = 0;
    int has_ace = 0;
    int i;

    // Add up the values of all non-ace cards
    for (i=0; i<HAND_SIZE; i++) {
        if (hand[i].value == 0) {
            has_ace = 1;
        } else if (hand[i].value >= 10) {
            score += 10;
        } else {
            score += hand[i].value + 1;
        }
    }

    // Add up the value of the ace(s), if any
    if (has_ace) {
        if (score + 11 <= 21) {
            score += 11;
        } else {
            score += 1;
        }
    }

    return score;
}

void print_hand(Card *hand) {
    // Print a hand of cards
    int i;

    for (i=0; i<HAND_SIZE; i++) {
        printf("%s of %s\n", card_names[hand[i].value], suit_names[hand[i].suit]);
    }
}