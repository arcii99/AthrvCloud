//FormAI DATASET v1.0 Category: Poker Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 52
#define MAX_HAND 5

void shuffle(int *deck, int size);
void deal(int *deck, int size, int **hand);
void print_cards(int *hand, int size);

int main() {
    int deck[MAX_CARDS], *hand;
    srand(time(NULL));

    // Initialize deck of cards
    for (int i = 0; i < MAX_CARDS; i++) {
        deck[i] = i;
    }
    
    shuffle(deck, MAX_CARDS);
    deal(deck, MAX_HAND, &hand);
    print_cards(hand, MAX_HAND);

    return 0;
}

void shuffle(int *deck, int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal(int *deck, int size, int **hand) {
    *hand = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        (*hand)[i] = deck[i];
    }
}

void print_cards(int *hand, int size) {
    printf("Your hand: ");
    for (int i = 0; i < size; i++) {
        int card = hand[i];
        int rank = card % 13;
        int suit = card / 13;
        char *ranks[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
        char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        printf("%s of %s", ranks[rank], suits[suit]);
        if (i < size - 1) {
            printf(", ");
        }
    }
}

/*
 * The code above generates a standard deck of 52 cards, shuffles them, 
 * deals the top 5 cards to the player, and prints out the cards in the
 * player's hand.
 *

 * Now, let's implement a function to find the best hand the player can 
 * make with their cards, following the rules of poker:

 * 1. Royal Flush: A, K, Q, J, 10 of the same suit
 * 2. Straight Flush: Any five cards of the same suit in sequence
 * 3. Four of a Kind: Four cards of the same rank
 * 4. Full House: Three of a kind and a pair
 * 5. Flush: Any five cards of the same suit
 * 6. Straight: Any five cards in sequence (but not the same suit)
 * 7. Three of a Kind: Three cards of the same rank
 * 8. Two Pair: Two pairs of cards with the same rank
 * 9. One Pair: One pair of cards with the same rank
 * 10. High Card: None of the above
 */

int check_hand(int *hand, int size) {
    int rank_count[13] = {0};
    int suit_count[4] = {0};
    int straight_count = 0;
    int straight_index = -1;

    // Count the ranks and suits of the cards in the hand
    for (int i = 0; i < size; i++) {
        int card = hand[i];
        int rank = card % 13;
        int suit = card / 13;
        rank_count[rank]++;
        suit_count[suit]++;

        // Check for straight
        if (i > 0 && rank == (hand[i - 1] % 13) + 1) {
            straight_count++;
            if (straight_count == 3 && rank == 3) {
                straight_count = 2;  // Ace can be low
            }
            if (straight_count == 4) {
                straight_index = i - 3;
            }
        } else {
            straight_count = 0;
        }
    }
    if (straight_count == 3 && rank_count[0] == 1) {
        straight_index = size - 3;  // Ace can be high
    }

    // Check for Royal Flush or Straight Flush
    for (int i = 0; i < 4; i++) {
        if (suit_count[i] >= 5) {
            for (int rank = 8; rank < 13; rank++) {
                if (rank_count[rank] > 0 && rank_count[rank - 1] > 0 && rank_count[rank - 2] > 0 && rank_count[rank - 3] > 0 && rank_count[rank - 4] > 0) {
                    if (rank == 12 && rank_count[0] > 0) {  // Royal Flush
                        return 1;
                    } else {  // Straight Flush
                        return 2;
                    }
                }
            }
        }
    }

    // Check for Four of a Kind
    for (int rank = 0; rank < 13; rank++) {
        if (rank_count[rank] == 4) {
            return 3;
        }
    }

    // Check for Full House
    int has_three = 0;
    int has_pair = 0;
    for (int rank = 0; rank < 13; rank++) {
        if (rank_count[rank] == 3) {
            has_three = 1;
        } else if (rank_count[rank] == 2) {
            has_pair = 1;
        }
    }
    if (has_three && has_pair) {
        return 4;
    }

    // Check for Flush
    for (int suit = 0; suit < 4; suit++) {
        if (suit_count[suit] >= 5) {
            return 5;
        }
    }

    // Check for Straight
    if (straight_index >= 0) {
        return 6;
    }

    // Check for Three of a Kind
    for (int rank = 0; rank < 13; rank++) {
        if (rank_count[rank] == 3) {
            return 7;
        }
    }

    // Check for Two Pair
    int pair_count = 0;
    for (int rank = 0; rank < 13; rank++) {
        if (rank_count[rank] == 2) {
            pair_count++;
        }
    }
    if (pair_count >= 2) {
        return 8;
    }

    // Check for One Pair
    for (int rank = 0; rank < 13; rank++) {
        if (rank_count[rank] == 2) {
            return 9;
        }
    }

    // High Card
    return 10;
}