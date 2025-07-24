//FormAI DATASET v1.0 Category: Poker Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define MAX_HAND_SIZE 5

// structure for a card
typedef struct {
    int rank;
    int suit;
} Card;

// structure for a player
typedef struct {
    Card hand[MAX_HAND_SIZE];
    int score;
} Player;

// global variables
Player players[NUM_PLAYERS];
int num_cards_drawn = 0;

// function to generate a random card
Card generate_card() {
    Card card;
    card.rank = rand() % 13 + 1;
    card.suit = rand() % 4 + 1;
    return card;
}

// function to compare two cards
int compare_cards(Card card1, Card card2) {
    if (card1.rank > card2.rank)
        return 1;
    else if (card1.rank < card2.rank)
        return -1;
    else {
        if (card1.suit > card2.suit)
            return 1;
        else if (card1.suit < card2.suit)
            return -1;
        else
            return 0;
    }
}

// function to draw a card for each player
void draw_cards() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].hand[num_cards_drawn] = generate_card();
    }
    num_cards_drawn++;
}

// function to print a card
void print_card(Card card) {
    switch (card.rank) {
        case 1:
            printf("A");
            break;
        case 11:
            printf("J");
            break;
        case 12:
            printf("Q");
            break;
        case 13:
            printf("K");
            break;
        default:
            printf("%d", card.rank);
            break;
    }
    switch (card.suit) {
        case 1:
            printf("C ");
            break;
        case 2:
            printf("D ");
            break;
        case 3:
            printf("H ");
            break;
        case 4:
            printf("S ");
            break;
    }
}

// function to print a player's hand
void print_hand(Player player) {
    for (int i = 0; i < MAX_HAND_SIZE; i++) {
        print_card(player.hand[i]);
    }
    printf("\n");
}

// function to find a winner
int find_winner() {
    int winner = 0;
    for (int i = 1; i < NUM_PLAYERS; i++) {
        if (compare_cards(players[i].hand[num_cards_drawn-1], players[winner].hand[num_cards_drawn-1]) > 0) {
            winner = i;
        }
    }
    return winner;
}

int main() {
    srand(time(NULL));

    // initialize players' hands and scores
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < MAX_HAND_SIZE; j++) {
            players[i].hand[j] = generate_card();
        }
        players[i].score = 0;
    }

    // game loop
    while (num_cards_drawn < MAX_HAND_SIZE) {
        draw_cards();
        printf("Cards drawn:\n");
        for (int i = 0; i < NUM_PLAYERS; i++) {
            printf("Player %d: ", i+1);
            print_card(players[i].hand[num_cards_drawn-1]);
            printf("\n");
        }
        int winner = find_winner();
        players[winner].score++;
        printf("Winner: Player %d\n\n", winner+1);
    }

    // print final scores
    printf("Final scores:\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: %d\n", i+1, players[i].score);
    }

    return 0;
}