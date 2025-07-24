//FormAI DATASET v1.0 Category: Poker Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// defines the number of players and cards in a deck
#define NUM_PLAYERS 4
#define NUM_CARDS 52

// function to shuffle the deck of cards
void shuffle(int deck[]) {
    // initialize the random number generator
    srand(time(0));
    
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        
        // swap the ith and jth elements of the deck array
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// function to display the cards in a deck
void display_deck(int deck[]) {
    char suits[] = {'C', 'D', 'H', 'S'};
    char ranks[][2] = {
        {'A', ' '}, {'2', ' '}, {'3', ' '},
        {'4', ' '}, {'5', ' '}, {'6', ' '},
        {'7', ' '}, {'8', ' '}, {'9', ' '},
        {'T', ' '}, {'J', ' '}, {'Q', ' '},
        {'K', ' '}
    };
    
    for (int i = 0; i < NUM_CARDS; i++) {
        int suit = deck[i] / 13;
        int rank = deck[i] % 13;
        printf("%c%c ", ranks[rank], suits[suit]);
    }
    printf("\n");
}

// function to sort a player's hand
void sort_hand(int hand[]) {
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            if (hand[j] < hand[i]) {
                int temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
}

// function to display a player's hand
void display_hand(int hand[]) {
    char suits[] = {'C', 'D', 'H', 'S'};
    char ranks[][2] = {
        {'A', ' '}, {'2', ' '}, {'3', ' '},
        {'4', ' '}, {'5', ' '}, {'6', ' '},
        {'7', ' '}, {'8', ' '}, {'9', ' '},
        {'T', ' '}, {'J', ' '}, {'Q', ' '},
        {'K', ' '}
    };
    
    for (int i = 0; i < 5; i++) {
        int suit = hand[i] / 13;
        int rank = hand[i] % 13;
        printf("%c%c ", ranks[rank], suits[suit]);
    }
    printf("\n");
}

// function to determine the rank of a hand
int determine_hand_rank(int hand[]) {
    int num_ranks[13] = {0};
    int num_suits[4] = {0};
    int num_pairs = 0;
    int num_of_a_kind = 0;
    int is_flush = 0;
    int is_straight = 0;
    
    // count the number of each rank and suit in the hand
    for (int i = 0; i < 5; i++) {
        int rank = hand[i] % 13;
        int suit = hand[i] / 13;
        num_ranks[rank]++;
        num_suits[suit]++;
    }
    
    // check for a straight
    if (num_ranks[0] == 1 &&
        num_ranks[10] == 1 &&
        num_ranks[11] == 1 &&
        num_ranks[12] == 1 &&
        num_ranks[1] == 1) {
        is_straight = 1;
    } else {
        for (int i = 1; i <= 9; i++) {
            if (num_ranks[i] == 1 &&
                num_ranks[i+1] == 1 &&
                num_ranks[i+2] == 1 &&
                num_ranks[i+3] == 1 &&
                num_ranks[i+4] == 1) {
                is_straight = 1;
                break;
            }
        }
    }
    
    // check for a flush
    for (int i = 0; i < 4; i++) {
        if (num_suits[i] == 5) {
            is_flush = 1;
            break;
        }
    }
    
    // check for pairs, three of a kind, and four of a kind
    for (int i = 0; i < 13; i++) {
        if (num_ranks[i] == 2) {
            num_pairs++;
        } else if (num_ranks[i] == 3) {
            num_of_a_kind = 3;
        } else if (num_ranks[i] == 4) {
            num_of_a_kind = 4;
        }
    }
    
    // determine the rank of the hand
    if (num_of_a_kind == 4) {
        return 8;
    } else if (num_of_a_kind == 3 && num_pairs == 1) {
        return 7;
    } else if (is_flush && is_straight) {
        return 6;
    } else if (num_of_a_kind == 3) {
        return 3;
    } else if (num_pairs == 2) {
        return 2;
    } else if (num_pairs == 1) {
        return 1;
    } else if (is_flush) {
        return 5;
    } else if (is_straight) {
        return 4;
    } else {
        return 0;
    }
}

int main() {
    // initialize the deck of cards
    int deck[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i] = i;
    }
    
    // shuffle the deck
    shuffle(deck);
    
    // deal the cards to the players
    int hands[NUM_PLAYERS][5];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < 5; j++) {
            hands[i][j] = deck[i*5+j];
        }
    }
    
    // display the hands
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's hand: ", i+1);
        display_hand(hands[i]);
    }
    
    // determine the winner
    int winner = 0;
    int best_rank = determine_hand_rank(hands[0]);
    for (int i = 1; i < NUM_PLAYERS; i++) {
        int rank = determine_hand_rank(hands[i]);
        if (rank > best_rank) {
            best_rank = rank;
            winner = i;
        }
    }
    
    // display the winner
    printf("Player %d wins with a ", winner+1);
    switch (best_rank) {
        case 0:
            printf("high card\n");
            break;
        case 1:
            printf("pair\n");
            break;
        case 2:
            printf("two pairs\n");
            break;
        case 3:
            printf("three of a kind\n");
            break;
        case 4:
            printf("straight\n");
            break;
        case 5:
            printf("flush\n");
            break;
        case 6:
            printf("straight flush\n");
            break;
        case 7:
            printf("full house\n");
            break;
        case 8:
            printf("four of a kind\n");
            break;
    }
    
    return 0;
}