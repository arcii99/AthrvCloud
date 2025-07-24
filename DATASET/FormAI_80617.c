//FormAI DATASET v1.0 Category: Poker Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct deck {
    int card[52];
    int top_card;

} Deck;

int deal_card(Deck *deck) {
    return deck->card[deck->top_card--];
}

void shuffle_deck(Deck *deck) {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Shuffle the deck
    for(int i = 0; i < 52; i++) {
        int j = rand() % 52;
        int temp = deck->card[i];
        deck->card[i] = deck->card[j];
        deck->card[j] = temp;
    }

    deck->top_card = 51; // Reset the top_card index
}

void print_hand(int hand[], int num_cards) {
    char suits[] = {'S', 'H', 'C', 'D'};
    char faces[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

    for(int i = 0; i < num_cards; i++) {
        int suit = hand[i] / 13;
        int face = hand[i] % 13;

        printf("%c%c ", faces[face], suits[suit]);
    }

    printf("\n");
}

int main() {
    // Initialize the deck
    Deck deck;
    for(int i = 0; i < 52; i++) {
        deck.card[i] = i;
    }

    shuffle_deck(&deck);

    // Deal the cards
    int player_hand[2];
    int dealer_hand[2];

    player_hand[0] = deal_card(&deck);
    dealer_hand[0] = deal_card(&deck);
    player_hand[1] = deal_card(&deck);
    dealer_hand[1] = deal_card(&deck);

    // Print the hands
    printf("Player hand: ");
    print_hand(player_hand, 2);

    printf("Dealer hand: ");
    print_hand(dealer_hand, 2);

    return 0;
}