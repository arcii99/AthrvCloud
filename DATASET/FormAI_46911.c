//FormAI DATASET v1.0 Category: Poker Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define MAX_PLAYERS 4
#define MAX_HAND_SIZE 5
#define NUM_RANKS 13
#define NUM_SUITS 4

// Enumerations for card ranks and suits
enum Ranks {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum Suits {CLUBS, DIAMONDS, HEARTS, SPADES};

// Structs for a playing card and a player's hand
struct card {
    enum Ranks rank;
    enum Suits suit;
};
typedef struct card Card;

struct hand {
    Card cards[MAX_HAND_SIZE];
    int size;
};
typedef struct hand Hand;

// Function prototypes
void initialize_deck(Card *deck);
void shuffle_deck(Card *deck);
void print_card(Card card);
void print_hand(Hand hand);
void deal_cards(Card *deck, Hand *hands, int num_hands, int cards_per_hand);
void swap_cards(Card *card1, Card *card2);
void sort_hand(Hand *hand);
int evaluate_hand(Hand hand);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the deck and shuffle it
    Card deck[DECK_SIZE];
    initialize_deck(deck);
    shuffle_deck(deck);

    // Initialize the hands for all players
    Hand hands[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        hands[i].size = 0;
    }

    // Deal cards to the players
    deal_cards(deck, hands, MAX_PLAYERS, MAX_HAND_SIZE);

    // Print each player's hand
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d's hand:\n", i+1);
        print_hand(hands[i]);
        printf("\n");
    }

    printf("Evaluating each player's hand...\n");

    // Evaluate each player's hand
    int scores[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        scores[i] = evaluate_hand(hands[i]);
        printf("Player %d's score: %d\n", i+1, scores[i]);
    }

    printf("\n");

    // Determine the winner(s)
    int max_score = scores[0];
    for (int i = 1; i < MAX_PLAYERS; i++) {
        if (scores[i] > max_score) {
            max_score = scores[i];
        }
    }

    printf("The winner(s) is/are:\n");

    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (scores[i] == max_score) {
            printf("Player %d\n", i+1);
        }
    }

    return 0;
}

// Initializes a standard playing card deck with 52 cards
void initialize_deck(Card *deck) {
    int index = 0;

    for (int suit = CLUBS; suit <= SPADES; suit++) {
        for (int rank = ACE; rank <= KING; rank++) {
            deck[index].rank = rank;
            deck[index].suit = suit;
            index++;
        }
    }
}

// Shuffles the given playing card deck using the Fisher-Yates shuffle algorithm
void shuffle_deck(Card *deck) {
    for (int i = DECK_SIZE-1; i > 0; i--) {
        int j = rand() % (i+1);
        swap_cards(&deck[i], &deck[j]);
    }
}

// Swaps the positions of two playing cards
void swap_cards(Card *card1, Card *card2) {
    Card temp = *card1;
    *card1 = *card2;
    *card2 = temp;
}

// Prints out a playing card in a human-readable format
void print_card(Card card) {
    char *rank_string;
    char *suit_string;

    switch (card.rank) {
        case ACE:
            rank_string = "Ace";
            break;
        case TWO:
            rank_string = "Two";
            break;
        case THREE:
            rank_string = "Three";
            break;
        case FOUR:
            rank_string = "Four";
            break;
        case FIVE:
            rank_string = "Five";
            break;
        case SIX:
            rank_string = "Six";
            break;
        case SEVEN:
            rank_string = "Seven";
            break;
        case EIGHT:
            rank_string = "Eight";
            break;
        case NINE:
            rank_string = "Nine";
            break;
        case TEN:
            rank_string = "Ten";
            break;
        case JACK:
            rank_string = "Jack";
            break;
        case QUEEN:
            rank_string = "Queen";
            break;
        case KING:
            rank_string = "King";
            break;
    }

    switch (card.suit) {
        case CLUBS:
            suit_string = "Clubs";
            break;
        case DIAMONDS:
            suit_string = "Diamonds";
            break;
        case HEARTS:
            suit_string = "Hearts";
            break;
        case SPADES:
            suit_string = "Spades";
            break;
    }

    printf("%s of %s", rank_string, suit_string);
}

// Prints out all the playing cards in a player's hand
void print_hand(Hand hand) {
    for (int i = 0; i < hand.size; i++) {
        print_card(hand.cards[i]);
        if (i < hand.size - 1) {
            printf(", ");
        }
    }
}

// Deals the specified number of cards to each player from the given deck
void deal_cards(Card *deck, Hand *hands, int num_hands, int cards_per_hand) {
    for (int i = 0; i < cards_per_hand; i++) {
        for (int j = 0; j < num_hands; j++) {
            hands[j].cards[i] = deck[i*num_hands + j];
            hands[j].size++;
        }
    }
}

// Computes a score for the given poker hand based on the standard poker rules
int evaluate_hand(Hand hand) {
    sort_hand(&hand);

    // Check for a straight flush
    int straight_flush = 0;
    for (int i = 0; i < hand.size-1; i++) {
        if (hand.cards[i].suit == hand.cards[i+1].suit && hand.cards[i].rank == hand.cards[i+1].rank - 1) {
            straight_flush = 1;
        } else {
            straight_flush = 0;
            break;
        }
    }
    if (straight_flush) {
        if (hand.cards[0].rank == TEN && hand.cards[hand.size-1].rank == ACE) {
            // Royal flush
            return 10;
        } else {
            // Straight flush
            return 9;
        }
    }

    // Check for four of a kind
    int four_of_a_kind = 0;
    for (int i = 0; i < hand.size-3; i++) {
        if (hand.cards[i].rank == hand.cards[i+1].rank && hand.cards[i].rank == hand.cards[i+2].rank
            && hand.cards[i].rank == hand.cards[i+3].rank) {
            four_of_a_kind = 1;
            break;
        }
    }
    if (four_of_a_kind) {
        return 8;
    }

    // Check for full house
    int full_house = 0;
    if (hand.cards[0].rank == hand.cards[1].rank && hand.cards[1].rank == hand.cards[2].rank
        && hand.cards[3].rank == hand.cards[4].rank) {
        full_house = 1;
    } else if (hand.cards[0].rank == hand.cards[1].rank && hand.cards[2].rank == hand.cards[3].rank
               && hand.cards[3].rank == hand.cards[4].rank) {
        full_house = 1;
    }
    if (full_house) {
        return 7;
    }

    // Check for flush
    int flush = 0;
    for (int i = 0; i < hand.size-1; i++) {
        if (hand.cards[i].suit != hand.cards[i+1].suit) {
            flush = 0;
            break;
        } else {
            flush = 1;
        }
    }
    if (flush) {
        return 6;
    }

    // Check for straight
    int straight = 0;
    for (int i = 0; i < hand.size-1; i++) {
        if (hand.cards[i].rank != hand.cards[i+1].rank - 1) {
            straight = 0;
            break;
        } else {
            straight = 1;
        }
    }
    if (straight) {
        return 5;
    }

    // Check for three of a kind
    int three_of_a_kind = 0;
    for (int i = 0; i < hand.size-2; i++) {
        if (hand.cards[i].rank == hand.cards[i+1].rank && hand.cards[i].rank == hand.cards[i+2].rank) {
            three_of_a_kind = 1;
            break;
        }
    }
    if (three_of_a_kind) {
        return 4;
    }

    // Check for two pairs
    int two_pairs = 0;
    if (hand.cards[0].rank == hand.cards[1].rank && hand.cards[2].rank == hand.cards[3].rank) {
        two_pairs = 1;
    } else if (hand.cards[0].rank == hand.cards[1].rank && hand.cards[3].rank == hand.cards[4].rank) {
        two_pairs = 1;
    } else if (hand.cards[1].rank == hand.cards[2].rank && hand.cards[3].rank == hand.cards[4].rank) {
        two_pairs = 1;
    }
    if (two_pairs) {
        return 3;
    }

    // Check for one pair
    int one_pair = 0;
    for (int i = 0; i < hand.size-1; i++) {
        if (hand.cards[i].rank == hand.cards[i+1].rank) {
            one_pair = 1;
            break;
        }
    }
    if (one_pair) {
        return 2;
    }

    // High card
    return 1;
}

// Sorts a player's hand by rank (ascending)
void sort_hand(Hand *hand) {
    for (int i = 0; i < hand->size-1; i++) {
        for (int j = i+1; j < hand->size; j++) {
            if (hand->cards[i].rank > hand->cards[j].rank) {
                swap_cards(&hand->cards[i], &hand->cards[j]);
            }
        }
    }
}