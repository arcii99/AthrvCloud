//FormAI DATASET v1.0 Category: Poker Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

// struct to represent a card
typedef struct {
    int rank;
    char suit;
} Card;

// function to initialize the deck with all cards
void init_deck(Card *deck) {
    int i, j, count = 0;
    for (i = 0; i < 4; i++) {
        for (j = 1; j <= 13; j++) {
            deck[count].rank = j;
            switch (i) {
                case 0:
                    deck[count++].suit = 'C';
                    break;
                case 1:
                    deck[count++].suit = 'D';
                    break;
                case 2:
                    deck[count++].suit = 'H';
                    break;
                case 3:
                    deck[count++].suit = 'S';
                    break;
            }
        }
    }
}

// function to shuffle the deck
void shuffle_deck(Card *deck) {
    int i, j;
    Card temp;
    for (i = 0; i < DECK_SIZE; i++) {
        j = rand() % DECK_SIZE;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
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
    printf("%c ", card.suit);
}

// function to print a hand of cards
void print_hand(Card *hand, int size) {
    int i;
    for (i = 0; i < size; i++) {
        print_card(hand[i]);
    }
}

// function to determine if a hand contains a flush
int is_flush(Card *hand) {
    int i;
    char suit = hand[0].suit;
    for (i = 1; i < HAND_SIZE; i++) {
        if (hand[i].suit != suit) {
            return 0;
        }
    }
    return 1;
}

// function to determine if a hand contains a straight
int is_straight(Card *hand) {
    int i, j, temp, straight = 0;
    for (i = 0; i < HAND_SIZE - 1; i++) {
        for (j = i + 1; j < HAND_SIZE; j++) {
            if (hand[i].rank > hand[j].rank) {
                temp = hand[i].rank;
                hand[i].rank = hand[j].rank;
                hand[j].rank = temp;
            }
        }
    }
    if (hand[0].rank == 1 && hand[1].rank == 10 && hand[2].rank == 11 &&
        hand[3].rank == 12 && hand[4].rank == 13) {
        straight = 1;
    } else {
        straight = 1;
        for (i = 0; i < HAND_SIZE - 1; i++) {
            if (hand[i].rank != hand[i + 1].rank - 1) {
                straight = 0;
                break;
            }
        }
    }
    return straight;
}

// function to determine the rank of a hand
int rank_hand(Card *hand) {
    int rank = 0;
    if (is_straight(hand) && is_flush(hand)) {
        rank = 9;
    } else if (hand[0].rank == hand[3].rank || hand[1].rank == hand[4].rank) {
        rank = 8;
    } else if ((hand[0].rank == hand[2].rank && hand[3].rank == hand[4].rank) ||
               (hand[0].rank == hand[1].rank && hand[2].rank == hand[4].rank)) {
        rank = 7;
    } else if (is_flush(hand)) {
        rank = 6;
    } else if (is_straight(hand)) {
        rank = 5;
    } else if (hand[0].rank == hand[2].rank || hand[1].rank == hand[3].rank || hand[2].rank == hand[4].rank) {
        rank = 4;
    } else if ((hand[0].rank == hand[1].rank && hand[2].rank == hand[3].rank) ||
               (hand[0].rank == hand[1].rank && hand[3].rank == hand[4].rank) ||
               (hand[1].rank == hand[2].rank && hand[3].rank == hand[4].rank)) {
        rank = 3;
    } else if (hand[0].rank == hand[1].rank || hand[1].rank == hand[2].rank ||
               hand[2].rank == hand[3].rank || hand[3].rank == hand[4].rank) {
        rank = 2;
    }
    return rank;
}

int main() {
    srand(time(NULL));

    Card deck[DECK_SIZE], hand[HAND_SIZE];
    int i, j, rank, wins = 0, losses = 0, draws = 0;

    init_deck(deck);

    for (i = 0; i < 1000; i++) {
        shuffle_deck(deck);

        for (j = 0; j < HAND_SIZE; j++) {
            hand[j] = deck[j];
        }

        printf("\nHand: ");
        print_hand(hand, HAND_SIZE);

        rank = rank_hand(hand);

        switch (rank) {
            case 9:
                printf("is a straight flush!\n");
                wins++;
                break;
            case 8:
                printf("is four of a kind!\n");
                losses++;
                break;
            case 7:
                printf("is a full house!\n");
                draws++;
                break;
            case 6:
                printf("is a flush!\n");
                wins++;
                break;
            case 5:
                printf("is a straight!\n");
                wins++;
                break;
            case 4:
                printf("is three of a kind!\n");
                losses++;
                break;
            case 3:
                printf("is two pair!\n");
                losses++;
                break;
            case 2:
                printf("is a pair!\n");
                losses++;
                break;
            default:
                printf("is high card!\n");
                losses++;
                break;
        }
    }

    printf("\nResults:\nWins: %d\nLosses: %d\nDraws: %d\n", wins, losses, draws);

    return 0;
}