//FormAI DATASET v1.0 Category: Poker Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define card suits and ranks
typedef enum Suit {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
} Suit;

typedef enum Rank {
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
} Rank;

// Define a card structure
typedef struct Card {
    Suit suit;
    Rank rank;
} Card;

// Generate a card deck of 52 cards
void generate_deck(Card deck[]) {
    int i, j, index = 0;
    for (i = CLUBS; i <= SPADES; i++) {
        for (j = TWO; j <= ACE; j++) {
            deck[index++] = (Card) {i, j};
        }
    }
}

// Shuffle the card deck using Fisher-Yates algorithm
void shuffle_deck(Card deck[]) {
    srand(time(NULL));
    int i, j;
    Card temp;
    for (i = 51; i > 0; i--) {
        j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Display a card
void display_card(Card card) {
    char suit[10];
    char rank[10];
    switch (card.suit) {
        case CLUBS:
            strcpy(suit, "Clubs");
            break;
        case DIAMONDS:
            strcpy(suit, "Diamonds");
            break;
        case HEARTS:
            strcpy(suit, "Hearts");
            break;
        case SPADES:
            strcpy(suit, "Spades");
            break;
    }
    switch (card.rank) {
        case TWO:
            strcpy(rank, "2");
            break;
        case THREE:
            strcpy(rank, "3");
            break;
        case FOUR:
            strcpy(rank, "4");
            break;
        case FIVE:
            strcpy(rank, "5");
            break;
        case SIX:
            strcpy(rank, "6");
            break;
        case SEVEN:
            strcpy(rank, "7");
            break;
        case EIGHT:
            strcpy(rank, "8");
            break;
        case NINE:
            strcpy(rank, "9");
            break;
        case TEN:
            strcpy(rank, "10");
            break;
        case JACK:
            strcpy(rank, "Jack");
            break;
        case QUEEN:
            strcpy(rank, "Queen");
            break;
        case KING:
            strcpy(rank, "King");
            break;
        case ACE:
            strcpy(rank, "Ace");
            break;
    }
    printf("%s of %s\n", rank, suit);
}

// Deal a hand of cards to each player
void deal_cards(Card deck[], Card player1[], Card player2[], int num_cards) {
    int i;
    for (i = 0; i < num_cards; i++) {
        player1[i] = deck[i];
        player2[i] = deck[i + num_cards];
    }
}

// Evaluate a hand of cards and return its score
int evaluate_hand(Card hand[]) {
    int i, score = 0;
    for (i = 0; i < 5; i++) {
        switch (hand[i].rank) {
            case TWO:
                score += 2;
                break;
            case THREE:
                score += 3;
                break;
            case FOUR:
                score += 4;
                break;
            case FIVE:
                score += 5;
                break;
            case SIX:
                score += 6;
                break;
            case SEVEN:
                score += 7;
                break;
            case EIGHT:
                score += 8;
                break;
            case NINE:
                score += 9;
                break;
            case TEN:
            case JACK:
            case QUEEN:
            case KING:
                score += 10;
                break;
            case ACE:
                if (score + 11 > 21) {
                    score += 1;
                } else {
                    score += 11;
                }
                break;
        }
    }
    return score;
}

int main() {
    // Initialize variables
    Card deck[52];
    Card player1[5];
    Card player2[5];

    // Generate and shuffle the deck of cards
    generate_deck(deck);
    shuffle_deck(deck);

    // Deal the cards and display them to the players
    deal_cards(deck, player1, player2, 5);
    printf("Player 1 hand:\n");
    int i;
    for (i = 0; i < 5; i++) {
        display_card(player1[i]);
    }
    printf("Player 2 hand:\n");
    for (i = 0; i < 5; i++) {
        display_card(player2[i]);
    }

    // Evaluate the hands and determine the winner
    int score1 = evaluate_hand(player1);
    int score2 = evaluate_hand(player2);
    printf("Player 1 score: %d\n", score1);
    printf("Player 2 score: %d\n", score2);
    if (score1 > 21 && score2 > 21) {
        printf("Both players bust! It's a tie!\n");
    } else if (score1 > 21) {
        printf("Player 1 busts! Player 2 wins!\n");
    } else if (score2 > 21) {
        printf("Player 2 busts! Player 1 wins!\n");
    } else if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score2 > score1) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}