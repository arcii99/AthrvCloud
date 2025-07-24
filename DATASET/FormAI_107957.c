//FormAI DATASET v1.0 Category: Poker Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define card values
enum { ACE = 1, JACK = 11, QUEEN = 12, KING = 13 };

// Define suits
enum { SPADES, HEARTS, DIAMONDS, CLUBS };

// Define card structure
typedef struct {
    int value;
    int suit;
} Card;

// Function to display menu and get user input
int menu() {
    int choice;
    printf("\n1. Deal cards\n2. Exit\nEnter a choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to print a card
void print_card(Card c) {
    char suit;
    switch (c.suit) {
        case SPADES:
            suit = 'S';
            break;
        case HEARTS:
            suit = 'H';
            break;
        case DIAMONDS:
            suit = 'D';
            break;
        case CLUBS:
            suit = 'C';
            break;
    }
    switch (c.value) {
        case ACE:
            printf("A%c ", suit);
            break;
        case JACK:
            printf("J%c ", suit);
            break;
        case QUEEN:
            printf("Q%c ", suit);
            break;
        case KING:
            printf("K%c ", suit);
            break;
        default:
            printf("%d%c ", c.value, suit);
            break;
    }
}

// Function to shuffle the deck
void shuffle_deck(Card deck[], int n) {
    int i, j;
    Card temp;
    for (i = 0; i < n - 1; i++) {
        j = i + rand() % (n - i);
        temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

// Function to deal cards to players
void deal_cards(Card deck[], int n, int num_players) {
    int i, j, k = 0;
    Card players[num_players][5];
    for (i = 0; i < 5; i++) {        // Deal 5 cards to each player
        for (j = 0; j < num_players; j++) {
            players[j][i] = deck[k++];
        }
    }
    // Print the cards each player has been dealt
    for (i = 0; i < num_players; i++) {
        printf("\nPlayer %d\n", i + 1);
        for (j = 0; j < 5; j++) {
            print_card(players[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    srand(time(NULL));            // Seed random number generator
    int num_players;
    Card deck[52];                 // Initialize deck
    int i, j, k = 0;
    for (i = ACE; i <= KING; i++) {
        for (j = SPADES; j <= CLUBS; j++) {
            deck[k].value = i;
            deck[k++].suit = j;
        }
    }
    while (1) {
        switch (menu()) {
            case 1:
                printf("\nNumber of players (2-5): ");
                scanf("%d", &num_players);
                deal_cards(deck, 52, num_players);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}