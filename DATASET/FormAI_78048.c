//FormAI DATASET v1.0 Category: Poker Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HAND_SIZE 5
#define NUM_SUITS 4
#define NUM_RANKS 13

typedef enum { SPADES, HEARTS, DIAMONDS, CLUBS } suit_t;
typedef enum { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE } rank_t;

typedef struct {
    suit_t suit;
    rank_t rank;
} card_t;

typedef struct {
    card_t cards[MAX_HAND_SIZE];
    int size;
} hand_t;

void shuffle_deck(card_t* deck);
void print_hand(hand_t* hand);
void deal_hand(hand_t* hand, card_t* deck, int num_cards);
int evaluate_hand(hand_t* hand);
int is_flush(hand_t* hand);
int is_straight(hand_t* hand);
int is_four_of_a_kind(hand_t* hand);
int is_full_house(hand_t* hand);
int is_three_of_a_kind(hand_t* hand);
int is_two_pair(hand_t* hand);
int is_pair(hand_t* hand);
const char* get_suit_string(suit_t suit);
const char* get_rank_string(rank_t rank);

int main(int argc, char** argv) {
    srand(time(NULL)); // seed the random number generator with the current time
    card_t deck[NUM_SUITS * NUM_RANKS];
    hand_t hand;
    for (int suit = 0; suit < NUM_SUITS; suit++) {
        for (int rank = 0; rank < NUM_RANKS; rank++) {
            deck[suit * NUM_RANKS + rank].suit = suit;
            deck[suit * NUM_RANKS + rank].rank = rank;
        }
    }
    shuffle_deck(deck);
    deal_hand(&hand, deck, MAX_HAND_SIZE);
    printf("Your poker hand is:\n");
    print_hand(&hand);
    int hand_value = evaluate_hand(&hand);
    printf("The value of your hand is: %d\n", hand_value);
    if (hand_value >= 1) {
        printf("Congratulations, your hand is a winner!\n");
    } else {
        printf("Sorry, your hand is not a winner.\n");
    }
    return 0;
}

void shuffle_deck(card_t* deck) {
    for (int i = 0; i < NUM_SUITS * NUM_RANKS; i++) {
        int randomIndex = rand() % NUM_SUITS * NUM_RANKS;
        card_t temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

void deal_hand(hand_t* hand, card_t* deck, int num_cards) {
    hand->size = num_cards;
    for (int i = 0; i < num_cards; i++) {
        hand->cards[i] = deck[i];
    }
}

void print_hand(hand_t* hand) {
    for (int i = 0; i < hand->size; i++) {
        printf("%s of %s\n", get_rank_string(hand->cards[i].rank), get_suit_string(hand->cards[i].suit));
    }
}

int evaluate_hand(hand_t* hand) {
    if (is_flush(hand) && is_straight(hand)) {
        return 10; // Royal Flush
    } else if (is_flush(hand) && is_straight(hand)) {
        return 9; // Straight Flush
    } else if (is_four_of_a_kind(hand)) {
        return 8; // Four of a Kind
    } else if (is_full_house(hand)) {
        return 7; // Full House
    } else if (is_flush(hand)) {
        return 6; // Flush
    } else if (is_straight(hand)) {
        return 5; // Straight
    } else if (is_three_of_a_kind(hand)) {
        return 4; // Three of a Kind
    } else if (is_two_pair(hand)) {
        return 3; // Two Pair
    } else if (is_pair(hand)) {
        return 2; // Pair
    } else {
        return 1; // High Card
    }
}

int is_flush(hand_t* hand) {
    suit_t first_suit = hand->cards[0].suit;
    for (int i = 1; i < hand->size; i++) {
        if (hand->cards[i].suit != first_suit) {
            return 0;
        }
    }
    return 1;
}

int is_straight(hand_t* hand) {
    int min_rank = hand->cards[0].rank;
    int max_rank = hand->cards[hand->size - 1].rank;
    if (max_rank == ACE && min_rank == TWO) {
        // special case for Ace low straight
        min_rank = hand->cards[1].rank;
    }
    for (int i = 0; i < hand->size - 1; i++) {
        if (hand->cards[i + 1].rank != hand->cards[i].rank + 1) {
            return 0;
        }
    }
    return 1;
}

int is_four_of_a_kind(hand_t* hand) {
    for (int i = 0; i < hand->size - 3; i++) {
        if (hand->cards[i].rank == hand->cards[i + 1].rank && hand->cards[i].rank == hand->cards[i + 2].rank && hand->cards[i].rank == hand->cards[i + 3].rank) {
            return 1;
        }
    }
    return 0;
}

int is_full_house(hand_t* hand) {
    if (hand->cards[0].rank == hand->cards[1].rank && hand->cards[0].rank == hand->cards[2].rank && hand->cards[3].rank == hand->cards[4].rank) {
        return 1;
    } else if (hand->cards[2].rank == hand->cards[3].rank && hand->cards[2].rank == hand->cards[4].rank && hand->cards[0].rank == hand->cards[1].rank) {
        return 1;
    }
    return 0;
}

int is_three_of_a_kind(hand_t* hand) {
    for (int i = 0; i < hand->size - 2; i++) {
        if (hand->cards[i].rank == hand->cards[i + 1].rank && hand->cards[i].rank == hand->cards[i + 2].rank) {
            return 1;
        }
    }
    return 0;
}

int is_two_pair(hand_t* hand) {
    if (hand->cards[0].rank == hand->cards[1].rank && hand->cards[2].rank == hand->cards[3].rank) {
        return 1;
    } else if (hand->cards[0].rank == hand->cards[1].rank && hand->cards[3].rank == hand->cards[4].rank) {
        return 1;
    } else if (hand->cards[1].rank == hand->cards[2].rank && hand->cards[3].rank == hand->cards[4].rank) {
        return 1;
    }
    return 0;
}

int is_pair(hand_t* hand) {
    for (int i = 0; i < hand->size - 1; i++) {
        if (hand->cards[i].rank == hand->cards[i + 1].rank) {
            return 1;
        }
    }
    return 0;
}

const char* get_suit_string(suit_t suit) {
    switch (suit) {
        case SPADES:
            return "Spades";
        case HEARTS:
            return "Hearts";
        case DIAMONDS:
            return "Diamonds";
        case CLUBS:
            return "Clubs";
    }
}

const char* get_rank_string(rank_t rank) {
    switch (rank) {
        case TWO:
            return "Two";
        case THREE:
            return "Three";
        case FOUR:
            return "Four";
        case FIVE:
            return "Five";
        case SIX:
            return "Six";
        case SEVEN:
            return "Seven";
        case EIGHT:
            return "Eight";
        case NINE:
            return "Nine";
        case TEN:
            return "Ten";
        case JACK:
            return "Jack";
        case QUEEN:
            return "Queen";
        case KING:
            return "King";
        case ACE:
            return "Ace";
    }
}