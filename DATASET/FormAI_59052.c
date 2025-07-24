//FormAI DATASET v1.0 Category: Poker Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPADES   0
#define CLUBS    1
#define HEARTS   2
#define DIAMONDS 3
#define JACK     11
#define QUEEN    12
#define KING     13
#define ACE      14

#define HAND_SIZE 5

typedef struct card {
    int suit;
    int rank;
} Card;

typedef struct hand {
    Card cards[HAND_SIZE];
} Hand;

void shuffle_deck(Card *deck) {
    int i, j;
    Card temp;
    for (i = 0; i < 52; i++) {
        j = i + rand() % (52 - i);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(Card card) {
    switch (card.rank) {
        case JACK: printf("J"); break;
        case QUEEN: printf("Q"); break;
        case KING: printf("K"); break;
        case ACE: printf("A"); break;
        default: printf("%d", card.rank); break;
    }
    switch (card.suit) {
        case SPADES: printf("S "); break;
        case CLUBS: printf("C "); break;
        case HEARTS: printf("H "); break;
        case DIAMONDS: printf("D "); break;
    }
}

void print_hand(Hand hand) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        print_card(hand.cards[i]);
    }
    printf("\n");
}

int is_flush(Hand hand) {
    int i;
    for (i = 1; i < HAND_SIZE; i++) {
        if (hand.cards[i].suit != hand.cards[0].suit) {
            return 0;
        }
    }
    return 1;
}

int is_straight(Hand hand) {
    int i;
    for (i = 1; i < HAND_SIZE; i++) {
        if (hand.cards[i].rank != hand.cards[i-1].rank+1) {
            return 0;
        }
    }
    return 1;
}

int is_four_of_a_kind(Hand hand) {
    if (hand.cards[0].rank == hand.cards[1].rank
        && hand.cards[1].rank == hand.cards[2].rank
        && hand.cards[2].rank == hand.cards[3].rank) {
        return 1;
    }
    if (hand.cards[1].rank == hand.cards[2].rank
        && hand.cards[2].rank == hand.cards[3].rank
        && hand.cards[3].rank == hand.cards[4].rank) {
        return 1;
    }
    return 0;
}

int is_full_house(Hand hand) {
    if (hand.cards[0].rank == hand.cards[1].rank
        && hand.cards[1].rank == hand.cards[2].rank
        && hand.cards[3].rank == hand.cards[4].rank) {
        return 1;
    }
    if (hand.cards[0].rank == hand.cards[1].rank
        && hand.cards[2].rank == hand.cards[3].rank
        && hand.cards[3].rank == hand.cards[4].rank) {
        return 1;
    }
    return 0;
}

int is_three_of_a_kind(Hand hand) {
    if (hand.cards[0].rank == hand.cards[1].rank
        && hand.cards[1].rank == hand.cards[2].rank) {
        return 1;
    }
    if (hand.cards[1].rank == hand.cards[2].rank
        && hand.cards[2].rank == hand.cards[3].rank) {
        return 1;
    }
    if (hand.cards[2].rank == hand.cards[3].rank
        && hand.cards[3].rank == hand.cards[4].rank) {
        return 1;
    }
    return 0;
}

int is_two_pair(Hand hand) {
    if (hand.cards[0].rank == hand.cards[1].rank
        && hand.cards[2].rank == hand.cards[3].rank) {
        return 1;
    }
    if (hand.cards[0].rank == hand.cards[1].rank
        && hand.cards[3].rank == hand.cards[4].rank) {
        return 1;
    }
    if (hand.cards[1].rank == hand.cards[2].rank
        && hand.cards[3].rank == hand.cards[4].rank) {
        return 1;
    }
    return 0;
}

int is_one_pair(Hand hand) {
    int i, j;
    for (i = 0; i < HAND_SIZE; i++) {
        for (j = i+1; j < HAND_SIZE; j++) {
            if (hand.cards[i].rank == hand.cards[j].rank) {
                return 1;
            }
        }
    }
    return 0;
}

int evaluate_hand(Hand hand) {
    if (is_flush(hand) && is_straight(hand)) {
        if (hand.cards[0].rank == 10) {
            return 10;
        } else {
            return 9;
        }
    }
    if (is_four_of_a_kind(hand)) {
        return 8;
    }
    if (is_full_house(hand)) {
        return 7;
    }
    if (is_flush(hand)) {
        return 6;
    }
    if (is_straight(hand)) {
        return 5;
    }
    if (is_three_of_a_kind(hand)) {
        return 4;
    }
    if (is_two_pair(hand)) {
        return 3;
    }
    if (is_one_pair(hand)) {
        return 2;
    }
    return 1;
}

void poker_game() {
    Card deck[52];
    Hand player_hand;
    srand(time(NULL));
    int i, ranking;
    char input;

    for (i = 0; i < 52; i++) {
        deck[i].suit = i / 13;
        deck[i].rank = i % 13 + 2;
    }

    shuffle_deck(deck);

    printf("Welcome to the C Poker Game!\n");
    printf("Press 'd' to deal your hand or 'q' to quit.\n");
    do {
        input = getchar();
        if (input == 'q') {
            printf("Thanks for playing!\n");
            return;
        }
        if (input == 'd') {
            for (i = 0; i < HAND_SIZE; i++) {
                player_hand.cards[i] = deck[i];
            }
            shuffle_deck(deck);
            ranking = evaluate_hand(player_hand);
            printf("Your hand is:\n");
            print_hand(player_hand);
            printf("Your hand ranking is %d.\n", ranking);
            printf("Press 'd' to deal another hand or 'q' to quit.\n");
        }
    } while (input != 'q');
}

int main() {
    poker_game();
    return 0;
}