//FormAI DATASET v1.0 Category: Poker Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_PLAYERS 2
#define HAND_SIZE 5

typedef enum Suit { SPADES, HEARTS, DIAMONDS, CLUBS } Suit;
typedef enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING } Rank;
typedef struct Card { Suit suit; Rank rank; } Card;
typedef struct Hand { Card cards[HAND_SIZE]; } Hand;
typedef struct Player { Hand hand; int score; } Player;

Card deck[NUM_CARDS];
Player players[NUM_PLAYERS];

void shuffleDeck();
void dealCards();
void printCards(Hand hand);
void printCard(Card card);
void calculateScore(Player *player);

int main() {
    srand(time(NULL));
    shuffleDeck();
    dealCards();
    calculateScore(&players[0]);
    calculateScore(&players[1]);
    printf("Player 1 score: %d\n", players[0].score);
    printf("Player 2 score: %d\n", players[1].score);
    return 0;
}

void shuffleDeck() {
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i].suit = i / NUM_RANKS;
        deck[i].rank = i % NUM_RANKS;
    }

    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < HAND_SIZE; j++) {
            players[i].hand.cards[j] = deck[i * HAND_SIZE + j];
        }
        printf("Player %d's hand:\n", i + 1);
        printCards(players[i].hand);
    }
}

void printCards(Hand hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        printCard(hand.cards[i]);
        printf("\n");
    }
}

void printCard(Card card) {
    switch (card.rank) {
        case ACE: printf("A"); break;
        case TWO: printf("2"); break;
        case THREE: printf("3"); break;
        case FOUR: printf("4"); break;
        case FIVE: printf("5"); break;
        case SIX: printf("6"); break;
        case SEVEN: printf("7"); break;
        case EIGHT: printf("8"); break;
        case NINE: printf("9"); break;
        case TEN: printf("10"); break;
        case JACK: printf("J"); break;
        case QUEEN: printf("Q"); break;
        case KING: printf("K"); break;
    }

    switch (card.suit) {
        case SPADES: printf("S"); break;
        case HEARTS: printf("H"); break;
        case DIAMONDS: printf("D"); break;
        case CLUBS: printf("C"); break;
    }
}

void calculateScore(Player *player) {
    player->score = 0;
    for (int i = 0; i < HAND_SIZE; i++) {
        switch (player->hand.cards[i].rank) {
            case ACE: player->score += 11; break;
            case TWO: player->score += 2; break;
            case THREE: player->score += 3; break;
            case FOUR: player->score += 4; break;
            case FIVE: player->score += 5; break;
            case SIX: player->score += 6; break;
            case SEVEN: player->score += 7; break;
            case EIGHT: player->score += 8; break;
            case NINE: player->score += 9; break;
            case TEN:
            case JACK:
            case QUEEN:
            case KING: player->score += 10; break;
        }
    }
}