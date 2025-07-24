//FormAI DATASET v1.0 Category: Poker Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct Card {
    char suit[10];
    char value[5];
    int card_rank;
} Card;

void shuffle_deck(Card deck[]);
void print_hand(Card hand[]);
int check_pair(Card hand[]);
int check_two_pair(Card hand[]);
int check_three_of_a_kind(Card hand[]);
int check_four_of_a_kind(Card hand[]);
int check_full_house(Card hand[]);
int check_flush(Card hand[]);
int check_straight(Card hand[]);
void draw_cards(Card deck[], Card hand[], int num_cards, int start_pos);
void swap_cards(Card *card1, Card *card2, Card *temp);

int main() {
    Card deck[DECK_SIZE];
    Card hand[HAND_SIZE];
    char play_again = 'y';
    int num_draws = 0;
    int i, j;
    
    // initialize deck of cards
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int card_rank = 2;
    for (i = 0; i < DECK_SIZE; i++) {
        Card new_card;
        sprintf(new_card.suit, "%s", suits[i/13]);
        sprintf(new_card.value, "%s", values[i%13]);
        new_card.card_rank = card_rank;
        deck[i] = new_card;
        card_rank++;
    }
    
    // play poker
    while (play_again == 'y') {
        shuffle_deck(deck);
        num_draws = 0;
        for (i = 0; i < HAND_SIZE; i++) {
            hand[i] = deck[i];
        }
        printf("\nYour starting hand:\n");
        print_hand(hand);
        
        // discard and draw new cards
        while (num_draws < 3) {
            char discard[10];
            int discard_pos;
            printf("Enter card position you want to discard (1-5): ");
            scanf("%d", &discard_pos);
            discard_pos--;
            Card temp = hand[discard_pos];
            
            for (j = discard_pos; j < HAND_SIZE-1; j++) {
                hand[j] = hand[j+1];
            }
            hand[4] = temp;
            
            printf("\nYour new hand after discarding card in position %d:\n", discard_pos+1);
            print_hand(hand);
            num_draws++;
        }
        
        // evaluate hand
        int hand_rank = -1;
        if (check_pair(hand)) {
            hand_rank = 1;
        }
        if (check_two_pair(hand)) {
            hand_rank = 2;
        }
        if (check_three_of_a_kind(hand)) {
            hand_rank = 3;
        }
        if (check_straight(hand)) {
            hand_rank = 4;
        }
        if (check_flush(hand)) {
            hand_rank = 5;
        }
        if (check_full_house(hand)) {
            hand_rank = 6;
        }
        if (check_four_of_a_kind(hand)) {
            hand_rank = 7;
        }
        if (hand_rank == -1) {
            printf("\nSorry, you don't have any poker hand.\n");
        } else {
            printf("\nCongratulations! You have a %s.\n", hand_rank == 1 ? "pair" : hand_rank == 2 ? "two pair" : hand_rank == 3 ? "three of a kind" : hand_rank == 4 ? "straight" : hand_rank == 5 ? "flush" : hand_rank == 6 ? "full house" : hand_rank == 7 ? "four of a kind" : "");
        }
        
        // play again?
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    }
    
    return 0;
}

// shuffle deck of cards in random order
void shuffle_deck(Card deck[]) {
    srand(time(NULL));
    int i;
    for (i = 0; i < DECK_SIZE; i++) {
        int index = rand() % DECK_SIZE;
        swap_cards(&deck[i], &deck[index], &(Card){});
    }
}

// swap two cards
void swap_cards(Card *card1, Card *card2, Card *temp) {
    *temp = *card1;
    *card1 = *card2;
    *card2 = *temp;
}

// print player's hand
void print_hand(Card hand[]) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        printf("Card %d: %s of %s\n", i+1, hand[i].value, hand[i].suit);
    }
}

// check if player has a pair
int check_pair(Card hand[]) {
    int i, j;
    for (i = 0; i < HAND_SIZE-1; i++) {
        for (j = i+1; j < HAND_SIZE; j++) {
            if (hand[i].card_rank == hand[j].card_rank) {
                return 1;
            }
        }
    }
    return 0;
}

// check if player has two pairs
int check_two_pair(Card hand[]) {
    int i, j;
    int pairs = 0;
    for (i = 0; i < HAND_SIZE-1; i++) {
        for (j = i+1; j < HAND_SIZE; j++) {
            if (hand[i].card_rank == hand[j].card_rank) {
                pairs++;
                if (pairs == 2) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// check if player has three of a kind
int check_three_of_a_kind(Card hand[]) {
    int i, j, k;
    for (i = 0; i < HAND_SIZE-2; i++) {
        for (j = i+1; j < HAND_SIZE-1; j++) {
            for (k = j+1; k < HAND_SIZE; k++) {
                if (hand[i].card_rank == hand[j].card_rank && hand[j].card_rank == hand[k].card_rank) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// check if player has four of a kind
int check_four_of_a_kind(Card hand[]) {
    int i, j, k, l;
    for (i = 0; i < HAND_SIZE-3; i++) {
        for (j = i+1; j < HAND_SIZE-2; j++) {
            for (k = j+1; k < HAND_SIZE-1; k++) {
                for (l = k+1; l < HAND_SIZE; l++) {
                    if (hand[i].card_rank == hand[j].card_rank && hand[j].card_rank == hand[k].card_rank && hand[k].card_rank == hand[l].card_rank) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

// check if player has a full house
int check_full_house(Card hand[]) {
    int i, j, k, pair_rank = -1, trio_rank = -1;
    for (i = 0; i < HAND_SIZE-2; i++) {
        for (j = i+1; j < HAND_SIZE-1; j++) {
            for (k = j+1; k < HAND_SIZE; k++) {
                if (hand[i].card_rank == hand[j].card_rank && hand[j].card_rank == hand[k].card_rank) {
                    trio_rank = hand[i].card_rank;
                }
                if (hand[i].card_rank == hand[j].card_rank || hand[i].card_rank == hand[k].card_rank || hand[j].card_rank == hand[k].card_rank) {
                    pair_rank = hand[i].card_rank + hand[j].card_rank + hand[k].card_rank - 3*trio_rank;
                }
            }
        }
    }
    if (pair_rank != -1 && trio_rank != -1) {
        return 1;
    }
    return 0;
}

// check if player has a flush
int check_flush(Card hand[]) {
    int i;
    for (i = 0; i < HAND_SIZE-1; i++) {
        if (strcmp(hand[i].suit, hand[i+1].suit)) {
            return 0;
        }
    }
    return 1;
}

// check if player has a straight
int check_straight(Card hand[]) {
    int i, j;
    for (i = 0; i < HAND_SIZE-1; i++) {
        for (j = i+1; j < HAND_SIZE; j++) {
            if (hand[i].card_rank > hand[j].card_rank) {
                swap_cards(&hand[i], &hand[j], &(Card){});
            }
        }
    }
    for (i = 0; i < HAND_SIZE-1; i++) {
        if (hand[i].card_rank + 1 != hand[i+1].card_rank) {
            return 0;
        }
    }
    return 1;
}