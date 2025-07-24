//FormAI DATASET v1.0 Category: Poker Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

// Card struct to hold value and suit
struct Card {
    char value;
    char suit;
};

// Player struct to hold name, hand, and score
struct Player {
    char name[20];
    struct Card hand[5];
    int score;
};

// Function to get a random card from the deck
struct Card draw_card(struct Card deck[]) {
    int index = rand() % DECK_SIZE;
    while (deck[index].value == 0) {
        index = rand() % DECK_SIZE;
    }
    struct Card card = deck[index];
    deck[index].value = 0;
    deck[index].suit = 0;
    return card;
}

// Function to generate a deck of cards
void generate_deck(struct Card deck[]) {
    char suits[4] = {'H', 'D', 'C', 'S'};
    char values[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[index].suit = suits[i];
            deck[index].value = values[j];
            index++;
        }
    }
}

int main() {
    srand(time(NULL));
    struct Player player1;
    struct Player player2;
    struct Card deck[DECK_SIZE];
    generate_deck(deck);
    printf("Welcome to C Poker!\n\n");
    printf("Player 1, please enter your name: ");
    scanf("%s", player1.name);
    printf("Player 2, please enter your name: ");
    scanf("%s", player2.name);
    printf("\n");
    int gameover = 0;
    while (!gameover) {
        // Deal hands to players
        for (int i = 0; i < HAND_SIZE; i++) {
            player1.hand[i] = draw_card(deck);
            player2.hand[i] = draw_card(deck);
        }
        // Print hands to players
        printf("%s's hand: ", player1.name);
        for (int i = 0; i < HAND_SIZE; i++) {
            printf("%c%c ", player1.hand[i].value, player1.hand[i].suit);
        }
        printf("\n");
        printf("%s's hand: ", player2.name);
        for (int i = 0; i < HAND_SIZE; i++) {
            printf("%c%c ", player2.hand[i].value, player2.hand[i].suit);
        }
        printf("\n");
        // Compare hands to determine winner
        int player1_score = 0;
        int player2_score = 0;
        for (int i = 0; i < HAND_SIZE; i++) {
            if (player1.hand[i].value == 'A') {
                player1_score += 14;
            } else if (player1.hand[i].value == 'K') {
                player1_score += 13;
            } else if (player1.hand[i].value == 'Q') {
                player1_score += 12;
            } else if (player1.hand[i].value == 'J') {
                player1_score += 11;
            } else if (player1.hand[i].value == 'T') {
                player1_score += 10;
            } else {
                player1_score += player1.hand[i].value - '0';
            }
            
            if (player2.hand[i].value == 'A') {
                player2_score += 14;
            } else if (player2.hand[i].value == 'K') {
                player2_score += 13;
            } else if (player2.hand[i].value == 'Q') {
                player2_score += 12;
            } else if (player2.hand[i].value == 'J') {
                player2_score += 11;
            } else if (player2.hand[i].value == 'T') {
                player2_score += 10;
            } else {
                player2_score += player2.hand[i].value - '0';
            }
        }
        player1.score += player1_score;
        player2.score += player2_score;
        printf("%s's score is now %d\n", player1.name, player1.score);
        printf("%s's score is now %d\n", player2.name, player2.score);
        // Check if either player has won
        if (player1.score >= 100 || player2.score >= 100) {
            printf("%s has won the game!\n", player1.score >= 100 ? player1.name : player2.name);
            gameover = 1;
        }
    }
    return 0;
}