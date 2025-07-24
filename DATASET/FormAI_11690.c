//FormAI DATASET v1.0 Category: Poker Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_FACES 10

typedef enum {CLUBS, DIAMONDS, HEARTS, SPADES} suit_t;
typedef enum {TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE} rank_t;

// Card structure
typedef struct {
    rank_t rank;
    suit_t suit;
} Card;

// Deck of cards
typedef struct {
    Card cards[DECK_SIZE];
    int top_card_index;
} Deck;

// Hand of cards
typedef struct {
    Card cards[5];
    int hand_rank;
} Hand;

// Initialize deck of cards
void init_deck(Deck *deck) {
    int i, j;
    deck->top_card_index = 0;
    for (i = 0; i < NUM_RANKS; i++) {
        for (j = 0; j < NUM_SUITS; j++) {
            deck->cards[i*NUM_SUITS+j].rank = i + 2;
            deck->cards[i*NUM_SUITS+j].suit = j;
        }
    }
}

// Shuffle deck of cards
void shuffle_deck(Deck *deck) {
    int i, random_index;
    Card temp_card;
    srand(time(NULL));
    for (i = 0; i < DECK_SIZE; i++) {
        random_index = rand() % DECK_SIZE;
        temp_card = deck->cards[i];
        deck->cards[i] = deck->cards[random_index];
        deck->cards[random_index] = temp_card;
    }
}

// Deal a card from the top of the deck
Card deal_card(Deck *deck) {
    Card dealt_card = deck->cards[deck->top_card_index];
    deck->top_card_index++;
    return dealt_card;
}

// Initialize hand of cards
void init_hand(Hand *hand) {
    int i;
    for (i = 0; i < 5; i++) {
        hand->cards[i].rank = 0;
        hand->cards[i].suit = 0;
    }
    hand->hand_rank = 0;
}

// Print a card
void print_card(Card card) {
    char *rank_string[] = {"", "", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    char *suit_string[] = {"C", "D", "H", "S"};
    printf("%s%s ", rank_string[card.rank], suit_string[card.suit]);
}

// Print a hand
void print_hand(Hand hand) {
    int i;
    for (i = 0; i < 5; i++) {
        print_card(hand.cards[i]);
    }
    printf("\n");
}

// Sort a hand by rank
void sort_hand(Hand *hand) {
    int i, j;
    Card temp_card;
    for (i = 0; i < 5; i++) {
        for (j = i+1; j < 5; j++) {
            if (hand->cards[j].rank < hand->cards[i].rank) {
                temp_card = hand->cards[i];
                hand->cards[i] = hand->cards[j];
                hand->cards[j] = temp_card;
            }
        }
    }
}

// Determine the rank of a hand
void rank_hand(Hand *hand) {
    int i, j;
    int found_pair = 0;
    int found_two_pair = 0;
    int found_three_of_a_kind = 0;
    int found_straight = 0;
    int found_flush = 0;
    int found_full_house = 0;
    int found_four_of_a_kind = 0;
    int found_straight_flush = 0;
    
    // Check for pairs, three of a kind, four of a kind, and full house
    for (i = 0; i < 5; i++) {
        for (j = i+1; j < 5; j++) {
            if (hand->cards[j].rank == hand->cards[i].rank) {
                // Found a pair
                if (found_pair) {
                    // Found two pairs
                    found_two_pair = 1;
                } else if (found_three_of_a_kind) {
                    // Found a full house
                    found_full_house = 1;
                } else if (found_four_of_a_kind) {
                    // Found a four of a kind
                    hand->hand_rank = 7;
                    return;
                } else {
                    // Found a pair
                    found_pair = 1;
                }
            }
        }
    }
    
    // Check for three of a kind and full house
    for (i = 0; i < 5; i++) {
        for (j = i+1; j < 5; j++) {
            if (hand->cards[j].rank == hand->cards[i].rank) {
                for (int k = j+1; k < 5; k++) {
                    if (hand->cards[k].rank == hand->cards[i].rank) {
                        // Found three of a kind
                        found_three_of_a_kind = 1;
                        if (found_pair) {
                            // Found a full house
                            found_full_house = 1;
                        }
                    }
                }
            }
        }
    }
    
    // Check for four of a kind
    for (i = 0; i < 5; i++) {
        for (j = i+1; j < 5; j++) {
            if (hand->cards[j].rank == hand->cards[i].rank) {
                for (int k = j+1; k < 5; k++) {
                    if (hand->cards[k].rank == hand->cards[i].rank) {
                        for (int l = k+1; l < 5; l++) {
                            if (hand->cards[l].rank == hand->cards[i].rank) {
                                // Found four of a kind
                                found_four_of_a_kind = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    
    // Check for straight
    for (i = 0; i < NUM_RANKS-4; i++) {
        if (hand->cards[i+4].rank == i+2 && hand->cards[i+3].rank == i+3 &&
            hand->cards[i+2].rank == i+4 && hand->cards[i+1].rank == i+5 &&
            hand->cards[i].rank == i+6) {
            // Found a straight
            found_straight = 1;
        }
    }
    
    // Check for flush
    for (i = 0; i < NUM_SUITS; i++) {
        if (hand->cards[0].suit == i && hand->cards[1].suit == i &&
            hand->cards[2].suit == i && hand->cards[3].suit == i &&
            hand->cards[4].suit == i) {
            // Found a flush
            found_flush = 1;
        }
    }
    
    // Check for straight flush
    if (found_straight && found_flush) {
        // Found a straight flush
        found_straight_flush = 1;
    }
    
    // Assign hand rank
    if (found_straight_flush) {
        hand->hand_rank = 8;
    } else if (found_four_of_a_kind) {
        hand->hand_rank = 7;
    } else if (found_full_house) {
        hand->hand_rank = 6;
    } else if (found_flush) {
        hand->hand_rank = 5;
    } else if (found_straight) {
        hand->hand_rank = 4;
    } else if (found_three_of_a_kind) {
        hand->hand_rank = 3;
    } else if (found_two_pair) {
        hand->hand_rank = 2;
    } else if (found_pair) {
        hand->hand_rank = 1;
    } else {
        hand->hand_rank = 0;
    }
}

int main() {
    int i, j;
    Deck deck;
    init_deck(&deck);
    shuffle_deck(&deck);
    Hand player_hand;
    init_hand(&player_hand);
    
    // Deal hand of cards
    for (i = 0; i < 5; i++) {
        player_hand.cards[i] = deal_card(&deck);
    }
    
    // Print hand of cards
    print_hand(player_hand);
    
    // Sort hand of cards by rank
    sort_hand(&player_hand);
    
    // Print sorted hand of cards
    print_hand(player_hand);
    
    // Rank hand of cards
    rank_hand(&player_hand);
    
    // Print hand rank
    char *hand_rank_string[] = {"High card", "Pair", "Two pair", "Three of a kind", "Straight",
                                "Flush", "Full house", "Four of a kind", "Straight flush"};
    printf("Hand rank: %s\n", hand_rank_string[player_hand.hand_rank]);
    
    return 0;
}