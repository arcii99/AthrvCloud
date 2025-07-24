//FormAI DATASET v1.0 Category: Poker Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define card suits
#define HEARTS   0
#define DIAMONDS 1
#define CLUBS    2
#define SPADES   3

// Define card values
#define ACE   1
#define TWO   2
#define THREE 3
#define FOUR  4
#define FIVE  5
#define SIX   6
#define SEVEN 7
#define EIGHT 8
#define NINE  9
#define TEN   10
#define JACK  11
#define QUEEN 12
#define KING  13

// Define hand types
#define HIGH_CARD    0
#define ONE_PAIR     1
#define TWO_PAIR     2
#define THREE_OF_KIND  3
#define STRAIGHT     4
#define FLUSH        5
#define FULL_HOUSE   6
#define FOUR_OF_KIND 7
#define STRAIGHT_FLUSH 8

// Define the deck structure
struct deck {
    int cards[52];
    int num_cards;
};

// Shuffles the deck using Fisher-Yates shuffle
void shuffle(struct deck *d) {
    int i, j, tmp;
    for (i = 51; i > 0; i--) {
        j = rand() % (i+1);
        tmp = d->cards[i];
        d->cards[i] = d->cards[j];
        d->cards[j] = tmp;
    }
}

// Initializes the deck to have all cards in order
void init_deck(struct deck *d) {
    int i, j;
    d->num_cards = 52;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            d->cards[13*i + j] = 13*i + j + 1;
        }
    }
}

// Prints a card to the console
void print_card(int card) {
    int val = card % 13;
    int suit = card / 13;
    char val_char[3];
    switch(val) {
        case ACE:
            sprintf(val_char, "A ");
            break;
        case 10:
            sprintf(val_char, "T ");
            break;
        case JACK:
            sprintf(val_char, "J ");
            break;
        case QUEEN:
            sprintf(val_char, "Q ");
            break;
        case KING:
            sprintf(val_char, "K ");
            break;
        default:
            sprintf(val_char, "%d ", val+1);
            break;
    }

    switch(suit) {
        case HEARTS:
            printf("%s♥ ", val_char);
            break;
        case DIAMONDS:
            printf("%s♦ ", val_char);
            break;
        case CLUBS:
            printf("%s♣ ", val_char);
            break;
        case SPADES:
            printf("%s♠ ", val_char);
            break;
    }
}

// Prints the hand to the console
void print_hand(int *hand, int size) {
    int i;
    for (i = 0; i < size; i++) {
        print_card(hand[i]);
    }
    printf("\n");
}

// Returns the number of points for a hand
int hand_points(int *hand, int size) {
    int i, j, k;
    int freq[13] = {0};
    int suit_freq[4] = {0};
    int max_freq = 0;
    int max_suit_freq = 0;
    int max_suit = 0;
    int has_pair = 0;
    int has_three_of_kind = 0;
    int has_four_of_kind = 0;
    int has_flush = 0;
    int has_straight = 0;
    int straight_start = 0;

    // Calculate frequency of values and suits
    for (i = 0; i < size; i++) {
        freq[(hand[i] - 1) % 13]++;
        suit_freq[(hand[i] - 1) / 13]++;
    }

    // Check for flush
    for (i = 0; i < 4; i++) {
        if (suit_freq[i] >= 5) {
            has_flush = 1;
            max_suit = i;
            break;
        }
    }

    // Check for straight
    for (i = 0; i < 10; i++) {
        if (freq[i] > 0 && freq[i+1] > 0 && freq[i+2] > 0 && freq[i+3] > 0 && freq[i+4] > 0) {
            has_straight = 1;
            straight_start = i+1;
            break;
        }
    }
    if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0 && freq[3] > 0 && freq[12] > 0) {
        has_straight = 1;
        straight_start = 1;
    }

    // Check for pairs, three of a kind, and four of a kind
    for (i = 0; i < 13; i++) {
        if (freq[i] == 2) has_pair = 1;
        if (freq[i] == 3) has_three_of_kind = 1;
        if (freq[i] == 4) has_four_of_kind = 1;
    }

    // Check for full house
    if (has_pair && has_three_of_kind) {
        return FULL_HOUSE;
    }

    // Check for four of a kind
    if (has_four_of_kind) {
        return FOUR_OF_KIND;
    }

    // Check for three of a kind
    if (has_three_of_kind) {
        return THREE_OF_KIND;
    }

    // Check for flush
    if (has_flush) {
        // Calculate points for flush
        int points = 0;
        for (i = 0; i < size; i++) {
            if ((hand[i] - 1) / 13 == max_suit) {
                points += ((hand[i] - 1) % 13) + 1;
            }
        }
        return FLUSH + points;
    }

    // Check for straight
    if (has_straight) {
        // Calculate points for straight
        int points = straight_start + 10;
        for (i = 0; i < size; i++) {
            if ((hand[i] - 1) % 13 == 0) {
                points += 1;
            }
        }
        return STRAIGHT + points;
    }

    // Check for two pair
    int num_pairs = 0;
    for (i = 0; i < 13; i++) {
        if (freq[i] == 2) {
            num_pairs++;
        }
    }
    if (num_pairs == 2) {
        return TWO_PAIR;
    }

    // Check for pair
    if (has_pair) {
        // Calculate points for pair
        int points = 0;
        for (i = 0; i < 13; i++) {
            if (freq[i] == 2) {
                points += i+1;
                break;
            }
        }
        return ONE_PAIR + points;
    }

    // Calculate points for high card
    int points = 0;
    for (i = 12; i >= 0; i--) {
        for (j = 0; j < size; j++) {
            if ((hand[j] - 1) % 13 == i) {
                points += i+1;
                break;
            }
        }
        if (j < size) break; // found the highest card
    }
    return HIGH_CARD + points;
}

int main() {
    int i, j;

    struct deck d;
    init_deck(&d);
    printf("Initial Deck:\n");
    for (i = 0; i < d.num_cards; i++) {
        print_card(d.cards[i]);
    }
    printf("\n");

    // Shuffle the deck
    srand(time(NULL));
    shuffle(&d);
    printf("Shuffled Deck:\n");
    for (i = 0; i < d.num_cards; i++) {
        print_card(d.cards[i]);
    }
    printf("\n");

    // Deal 5 cards and print the hand and its points
    int hand[5];
    for (i = 0; i < 5; i++) {
        hand[i] = d.cards[i];
    }
    printf("Hand:\n");
    print_hand(hand, 5);
    printf("Points: %d\n", hand_points(hand, 5));

    return 0;
}