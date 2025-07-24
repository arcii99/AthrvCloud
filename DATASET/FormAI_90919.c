//FormAI DATASET v1.0 Category: Poker Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

const char* suits[4] = {"Spades", "Hearts", "Clubs", "Diamonds"};
const char* ranks[13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

int deck[52];
int cards_drawn = 0;
int player_hand[5];
int dealer_hand[5];

void shuffle_deck() {
    srand(time(NULL));
    for(int i = 0; i < 52; i++) {
        deck[i] = i;
    }
    for(int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int deal_card() {
    int card = deck[cards_drawn];
    cards_drawn++;
    return card;
}

void deal_hands() {
    for(int i = 0; i < 5; i++) {
        player_hand[i] = deal_card();
        dealer_hand[i] = deal_card();
    }
}

void print_card(int card) {
    printf("%s of %s\n", ranks[card % 13], suits[card / 13]);
}

void print_hand(int* hand) {
    for(int i = 0; i < 5; i++) {
        print_card(hand[i]);
    }
}

int evaluate_hand_strength(int* hand) {
    int rank_count[13] = {};
    int suit_count[4] = {};
    for(int i = 0; i < 5; i++) {
        rank_count[hand[i] % 13]++;
        suit_count[hand[i] / 13]++;
    }
    int max_rank_count = 0;
    for(int i = 0; i < 13; i++) {
        if(rank_count[i] > max_rank_count) {
            max_rank_count = rank_count[i];
        }
    }
    int max_suit_count = 0;
    for(int i = 0; i < 4; i++) {
        if(suit_count[i] > max_suit_count) {
            max_suit_count = suit_count[i];
        }
    }
    if(max_rank_count == 4) {
        return 7; // four of a kind
    } else if(max_rank_count == 3) {
        if(rank_count[0] == 2 || rank_count[12] == 2) {
            return 6; // full house with 3 aces or 3 twos
        } else {
            return 3; // three of a kind
        }
    } else if(max_rank_count == 2) {
        int pairs = 0;
        for(int i = 0; i < 13; i++) {
            if(rank_count[i] == 2) {
                pairs++;
            }
        }
        if(pairs == 2) {
            return 2; // two pairs
        } else {
            return 1; // one pair
        }
    } else if(max_suit_count == 5 &&
              ((hand[0] / 13 == hand[1] / 13) &&
               (hand[0] / 13 == hand[2] / 13) &&
               (hand[0] / 13 == hand[3] / 13) &&
               (hand[0] / 13 == hand[4] / 13))) {
        if(hand[0] % 13 == 8 &&
           hand[1] % 13 == 9 &&
           hand[2] % 13 == 10 &&
           hand[3] % 13 == 11 &&
           hand[4] % 13 == 12) {
            return 9; // royal flush
        } else if(hand[0] % 13 == (hand[1] % 13) - 1 &&
                  hand[1] % 13 == (hand[2] % 13) - 1 &&
                  hand[2] % 13 == (hand[3] % 13) - 1 &&
                  hand[3] % 13 == (hand[4] % 13) - 1) {
            return 8; // straight flush
        } else {
            return 5; // flush
        }
    } else if(max_suit_count == 5) {
        return 5; // flush
    } else if(hand[0] % 13 == 8 &&
              hand[1] % 13 == 9 &&
              hand[2] % 13 == 10 &&
              hand[3] % 13 == 11 &&
              hand[4] % 13 == 12) {
        return 4; // straight with ace low
    } else if(hand[0] % 13 == (hand[1] % 13) - 1 &&
              hand[1] % 13 == (hand[2] % 13) - 1 &&
              hand[2] % 13 == (hand[3] % 13) - 1 &&
              hand[3] % 13 == (hand[4] % 13) - 1) {
        return 4; // straight
    } else {
        return 0; // nothing
    }
}

int main() {
    printf("Welcome to Poker!\n");
    shuffle_deck();
    deal_hands();
    printf("Your hand:\n");
    print_hand(player_hand);
    printf("Dealer's hand:\n");
    print_card(dealer_hand[0]);
    int hand_strength = evaluate_hand_strength(player_hand);
    printf("Your hand strength: %d\n", hand_strength);
    return 0;
}