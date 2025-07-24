//FormAI DATASET v1.0 Category: Poker Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to deal the cards
void deal_cards(int deck[], int num_cards, int num_players, int player_cards[][5]) {
    int i, j, n, temp;
    for (i = 0; i < num_cards; i++) {
        n = rand() % (num_cards - i) + i;
        temp = deck[i];
        deck[i] = deck[n];
        deck[n] = temp;
    }
    for (i = 0; i < num_players; i++) {
        for (j = 0; j < 5; j++) {
            player_cards[i][j] = deck[i*5+j];
        }
    }
}

// Function to print the cards
void print_cards(int num_players, int player_cards[][5]) {
    int i, j;
    char suits[4] = {'C', 'D', 'H', 'S'};
    for (i = 0; i < num_players; i++) {
        printf("Player %d's cards:\n", i+1);
        for (j = 0; j < 5; j++) {
            printf("%c%d ", suits[player_cards[i][j]/13], player_cards[i][j]%13+1);
        }
        printf("\n");
    }
}

int main() {
    int num_players = 2;
    int num_cards = 52;
    int deck[52];
    int player_cards[2][5];
    int i, j;

    // Initialize the deck
    for (i = 0; i < num_cards; i++) {
        deck[i] = i;
    }

    // Set the seed for rand()
    srand(time(NULL));

    // Deal the cards
    deal_cards(deck, num_cards, num_players, player_cards);

    // Print the cards
    print_cards(num_players, player_cards);

    return 0;
}