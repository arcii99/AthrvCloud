//FormAI DATASET v1.0 Category: Poker Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

struct card {
    char suit[10];
    char rank[3];
};

void generate_deck(struct card *deck);
void shuffle_deck(struct card *deck);
void deal_cards(struct card *deck, struct card *hand, int num_cards);
void print_hand(struct card *hand, int num_cards);
int evaluate_hand(struct card *hand, int num_cards);

int main() {
    struct card deck[DECK_SIZE];
    struct card hand[HAND_SIZE];
    int score;
    
    srand((unsigned int)time(NULL)); // seed for shuffle
    
    generate_deck(deck);
    shuffle_deck(deck);
    deal_cards(deck, hand, HAND_SIZE);
    print_hand(hand, HAND_SIZE);
    score = evaluate_hand(hand, HAND_SIZE);
    printf("Your score is: %d\n", score);
    
    return 0;
}

void generate_deck(struct card *deck) {
    char ranks[13][3] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    char suits[4][10] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int i, j, k;
    
    k = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            strcpy(deck[k].rank, ranks[j]);
            strcpy(deck[k].suit, suits[i]);
            k++;
        }
    }
}

void shuffle_deck(struct card *deck) {
    int i, j;
    struct card temp_card;
    
    for (i = 0; i < DECK_SIZE; i++) {
        j = rand() % DECK_SIZE;
        temp_card = deck[i];
        deck[i] = deck[j];
        deck[j] = temp_card;
    }
}

void deal_cards(struct card *deck, struct card *hand, int num_cards) {
    int i;
    
    for (i = 0; i < num_cards; i++) {
        hand[i] = deck[i];
    }
}

void print_hand(struct card *hand, int num_cards) {
    int i;
    
    for (i = 0; i < num_cards; i++) {
        printf("%s of %s\n", hand[i].rank, hand[i].suit);
    }
}

int evaluate_hand(struct card *hand, int num_cards) {
    char ranks[13][3] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int score = 0;
    int i, j, pairs;
    int rank_count[13];
    int straight_flag = 0;
    int flush_flag = 0;
    
    // count the number of each rank in the hand
    for (i = 0; i < 13; i++) {
        rank_count[i] = 0;
        for (j = 0; j < num_cards; j++) {
            if (strcmp(hand[j].rank, ranks[i]) == 0) {
                rank_count[i]++;
            }
        }
    }
    
    // check for flush
    for (i = 0; i < num_cards - 1; i++) {
        if (strcmp(hand[i].suit, hand[i+1].suit) != 0) {
            flush_flag = 0;
            break;
        }
        else {
            flush_flag = 1;
        }
    }

    // check for straight
    for (i = 0; i < 10; i++) {
        if (rank_count[i] == 1 && rank_count[i+1] == 1 && rank_count[i+2] == 1
            && rank_count[i+3] == 1 && rank_count[i+4] == 1) {
            straight_flag = 1;
            break;
        }
    }
    if (rank_count[0] == 1 && rank_count[1] == 1 && rank_count[2] == 1 && rank_count[3] == 1
        && rank_count[12] == 1) {
        straight_flag = 1;
    }
    
    // check for pairs
    pairs = 0;
    for (i = 0; i < 13; i++) {
        if (rank_count[i] == 2) {
            pairs++;
        }
        else if (rank_count[i] == 3) {
            score += 3;
            break;
        }
        else if (rank_count[i] == 4) {
            score += 6;
            break;
        }
    }
    if (pairs == 1) {
        score += 1;
    }
    else if (pairs == 2) {
        score += 3;
    }
    else if (pairs >= 3) {
        score += 6;
    }
    
    // add score based on flush and straight flags
    if (flush_flag == 1 && straight_flag == 1) {
        score += 15;
    }
    else if (flush_flag == 1 && straight_flag == 0) {
        score += 7;
    }
    else if (flush_flag == 0 && straight_flag == 1) {
        score += 7;
    }

    return score;
}