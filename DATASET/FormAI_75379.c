//FormAI DATASET v1.0 Category: Poker Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52

typedef struct {
    char *face;
    char *suit;
} Card;

void shuffle_deck(Card *deck) {
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_hand(Card *deck, Card *hand, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        hand[i] = deck[i];
    }
}

void print_hand(Card *hand, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        printf("%s of %s\n", hand[i].face, hand[i].suit);
    }
}

int main() {
    Card deck[NUM_CARDS] = {
        {"Ace", "Hearts"}, {"2", "Hearts"}, {"3", "Hearts"}, {"4", "Hearts"}, {"5", "Hearts"},
        {"6", "Hearts"}, {"7", "Hearts"}, {"8", "Hearts"}, {"9", "Hearts"}, {"10", "Hearts"},
        {"Jack", "Hearts"}, {"Queen", "Hearts"}, {"King", "Hearts"}, {"Ace", "Diamonds"}, {"2", "Diamonds"},
        {"3", "Diamonds"}, {"4", "Diamonds"}, {"5", "Diamonds"}, {"6", "Diamonds"}, {"7", "Diamonds"},
        {"8", "Diamonds"}, {"9", "Diamonds"}, {"10", "Diamonds"}, {"Jack", "Diamonds"}, {"Queen", "Diamonds"},
        {"King", "Diamonds"}, {"Ace", "Clubs"}, {"2", "Clubs"}, {"3", "Clubs"}, {"4", "Clubs"}, {"5", "Clubs"},
        {"6", "Clubs"}, {"7", "Clubs"}, {"8", "Clubs"}, {"9", "Clubs"}, {"10", "Clubs"}, {"Jack", "Clubs"},
        {"Queen", "Clubs"}, {"King", "Clubs"}, {"Ace", "Spades"}, {"2", "Spades"}, {"3", "Spades"},
        {"4", "Spades"}, {"5", "Spades"}, {"6", "Spades"}, {"7", "Spades"}, {"8", "Spades"}, {"9", "Spades"},
        {"10", "Spades"}, {"Jack", "Spades"},{"Queen", "Spades"}, {"King", "Spades"}
    };

    Card player_hand[5];
    Card computer_hand[5];

    srand(time(NULL));
    shuffle_deck(deck);
    deal_hand(deck, player_hand, 5);
    deal_hand(deck + 5, computer_hand, 5);

    printf("Your hand:\n");
    print_hand(player_hand, 5);
    printf("\nComputer's hand:\n");
    print_hand(computer_hand, 5);

    return 0;
}