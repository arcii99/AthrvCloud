//FormAI DATASET v1.0 Category: Poker Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 2
#define NUM_PLAYERS 4

typedef struct {
    int value;
    char suit;
} Card;

typedef struct {
    Card cards[HAND_SIZE];
    int total_value;
} Hand;

void initialize_deck(Card deck[]) {
    int index = 0;
    for (int i = 0; i < 4; i++) {
        char suit;
        switch (i) {
            case 0:
                suit = 'C'; // clubs
                break;
            case 1:
                suit = 'D'; // diamonds
                break;
            case 2:
                suit = 'H'; // hearts
                break;
            case 3:
                suit = 'S'; // spades
                break;
        }
        for (int j = 1; j <= 13; j++) {
            Card card;
            card.value = j;
            card.suit = suit;
            deck[index++] = card;
        }
    }
}

void shuffle_deck(Card deck[]) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int random_index = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[random_index];
        deck[random_index] = temp;
    }
}

void deal_cards(Card deck[], Hand hands[], int num_players) {
    int hand_index = 0;
    for (int card_index = 0; card_index < HAND_SIZE * num_players; card_index++) {
        hands[hand_index].cards[card_index % HAND_SIZE] = deck[card_index];
        if (card_index % HAND_SIZE == HAND_SIZE - 1) {
            hand_index++;
        }
    }
}

void print_hand(Hand hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        printf("%d%c ", hand.cards[i].value, hand.cards[i].suit);
    }
    printf("(%d)\n", hand.total_value);
}

void calculate_hand_value(Hand *hand) {
    int total_value = 0;
    int num_aces = 0;
    for (int i = 0; i < HAND_SIZE; i++) {
        if (hand->cards[i].value == 1) {
            num_aces++;
            total_value += 11;
        } else if (hand->cards[i].value >= 10) {
            total_value += 10;
        } else {
            total_value += hand->cards[i].value;
        }
    }
    while (total_value > 21 && num_aces > 0) {
        total_value -= 10;
        num_aces--;
    }
    hand->total_value = total_value;
}

int compare_hand(const void *a, const void *b) {
    Hand *hand_a = (Hand *)a;
    Hand *hand_b = (Hand *)b;
    return hand_b->total_value - hand_a->total_value;
}

int main() {
    Card deck[DECK_SIZE];
    initialize_deck(deck);
    shuffle_deck(deck);
    Hand hands[NUM_PLAYERS];
    deal_cards(deck, hands, NUM_PLAYERS);
    for (int i = 0; i < NUM_PLAYERS; i++) {
        calculate_hand_value(&hands[i]);
        printf("Player %d: ", i+1);
        print_hand(hands[i]);
    }
    qsort(hands, NUM_PLAYERS, sizeof(Hand), compare_hand);
    printf("Player %d wins!\n", hands[0].total_value);
    return 0;
}