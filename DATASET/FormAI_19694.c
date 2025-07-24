//FormAI DATASET v1.0 Category: Poker Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define card suits
#define HEARTS   "Hearts"
#define DIAMONDS "Diamonds"
#define CLUBS    "Clubs"
#define SPADES   "Spades"

// Define card values
#define ACE   "Ace"
#define KING  "King"
#define QUEEN "Queen"
#define JACK  "Jack"
#define TEN   "10"
#define NINE  "9"
#define EIGHT "8"
#define SEVEN "7"
#define SIX   "6"
#define FIVE  "5"
#define FOUR  "4"
#define THREE "3"
#define TWO   "2"

// Define array of card suits and values
const char *suits[] = {HEARTS, DIAMONDS, CLUBS, SPADES};
const char *values[] = {ACE, KING, QUEEN, JACK, TEN, NINE, EIGHT, SEVEN, SIX, FIVE, FOUR, THREE, TWO};

// Function prototypes
void shuffle(int *deck, int n);
void print_card(int card);
void print_hand(int *hand, int n);
int get_value(int *hand, int n);
void clear_buffer();

int main()
{
    int deck[52];
    int player_hand[5];
    int dealer_hand[5];
    int player_value;
    int dealer_value;
    char play_again = 'y';
    srand(time(NULL));

    while (play_again == 'y') {
        printf("\nLet's play some poker!");
        printf("\nShuffling deck...");
        shuffle(deck, 52);

        printf("\nDealing cards to player...");
        for (int i = 0; i < 5; i++) {
            player_hand[i] = deck[i];
        }
        printf("\nYour hand: ");
        print_hand(player_hand, 5);
        printf("\n");

        printf("\nDealing cards to dealer...");
        for (int i = 0; i < 5; i++) {
            dealer_hand[i] = deck[i + 5];
        }
        printf("\nDealer's hand: ");
        print_hand(dealer_hand, 5);
        printf("\n");

        player_value = get_value(player_hand, 5);
        dealer_value = get_value(dealer_hand, 5);

        if (player_value > dealer_value) {
            printf("\nCongratulations, you won!\n");
        } else {
            printf("\nSorry, you lost.\n");
        }

        printf("\nWould you like to play again? (y/n): ");
        scanf("%c", &play_again);
        clear_buffer();
    }

    printf("\nThanks for playing!\n");

    return 0;
}

// Shuffle the deck using Fisher-Yates shuffle algorithm
void shuffle(int *deck, int n)
{
    int temp;

    // Initialize deck
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }

    // Shuffle deck
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Print a card with the corresponding suit and value
void print_card(int card)
{
    int value = card % 13;
    int suit = card / 13;
    printf("%s of %s", values[value], suits[suit]);
}

// Print a hand of cards
void print_hand(int *hand, int n)
{
    for (int i = 0; i < n; i++) {
        print_card(hand[i]);
        printf(" ");
    }
}

// Get the value of a hand of cards
int get_value(int *hand, int n)
{
    int value = 0;
    for (int i = 0; i < n; i++) {
        int card = hand[i];
        int card_value = card % 13 + 1;
        if (card_value > 10) {
            card_value = 10;
        }
        value += card_value;
    }
    return value;
}

// Clear input buffer
void clear_buffer()
{
    while (getchar() != '\n');
}