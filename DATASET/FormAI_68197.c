//FormAI DATASET v1.0 Category: Poker Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define NUM_CARDS 52
#define MAX_CARDS 5

void shuffle(int *deck);
void print_cards(int *cards, int num_cards);
int get_largest_index(int *values, int num_values);
void exchange_cards(int *cards, int *deck, int num_cards);
int evaluate_hand(int *cards, int num_cards);
void print_hand_rank(int rank);

int main() {
    srand(time(NULL));
    int deck[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i] = i;
    }
    shuffle(deck);
    int player_hands[NUM_PLAYERS][MAX_CARDS];
    for (int p = 0; p < NUM_PLAYERS; p++) {
        for (int c = 0; c < MAX_CARDS; c++) { 
            player_hands[p][c] = deck[p * MAX_CARDS + c];
        }
        printf("Player %d's hand: ", p+1);
        print_cards(player_hands[p], MAX_CARDS);
        printf("\n");
    }
    for (int p = 0; p < NUM_PLAYERS; p++) {
        int indices[MAX_CARDS];
        printf("Enter the indices of the cards you want to exchange, separated by spaces: ");
        for (int i = 0; i < MAX_CARDS; i++) {
            scanf("%d", &indices[i]);
        }
        for (int i = 0; i < MAX_CARDS; i++) {
            player_hands[p][indices[i]] = deck[MAX_CARDS * NUM_PLAYERS + i];
        }
        printf("Player %d's new hand: ", p+1);
        print_cards(player_hands[p], MAX_CARDS);
        printf("\n");
    }
    int player_ranks[NUM_PLAYERS];
    for (int p = 0; p < NUM_PLAYERS; p++) {
        player_ranks[p] = evaluate_hand(player_hands[p], MAX_CARDS);
    }
    int winner = get_largest_index(player_ranks, NUM_PLAYERS);
    printf("\n");
    printf("Player %d wins with a ", winner+1);
    print_hand_rank(player_ranks[winner]);
    printf("\n");
    return 0;
}

void shuffle(int *deck) {
    for (int i = NUM_CARDS-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_cards(int *cards, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        int rank = cards[i] % 13;
        int suit = cards[i] / 13;
        char rank_char;
        switch (rank) {
            case 0:
                rank_char = 'A';
                break;
            case 9:
                rank_char = 'T';
                break;
            case 10:
                rank_char = 'J';
                break;
            case 11:
                rank_char = 'Q';
                break;
            case 12:
                rank_char = 'K';
                break;
            default:
                rank_char = rank + '1';
        }
        printf("%c%c ", rank_char, "CDHS"[suit]);
    }
}

int get_largest_index(int *values, int num_values) {
    int largest_index = 0;
    for (int i = 1; i < num_values; i++) {
        if (values[i] > values[largest_index]) {
            largest_index = i;
        }
    }
    return largest_index;
}

void exchange_cards(int *cards, int *deck, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        cards[i] = deck[i];
    }
}

int evaluate_hand(int *cards, int num_cards) {
    int straight = 0, flush = 0, four = 0, three = 0, pair = 0;
    int values[num_cards];
    for (int i = 0; i < num_cards; i++) {
        values[i] = cards[i] % 13;
    }
    for (int i = 0; i < num_cards; i++) {
        int count = 0;
        for (int j = 0; j < num_cards; j++) {
            if (values[j] == values[i]) {
                count++;
            }
        }
        if (count == 4) {
            four = 1;
        } else if (count == 3) {
            three = 1;
        } else if (count == 2) {
            if (pair) {
                pair = 0;
                three = 1;
            } else {
                pair = 1;
            }
        }
    }
    int sorted_values[num_cards];
    for (int i = 0; i < num_cards; i++) {
        sorted_values[i] = values[i];
    }
    for (int i = 0; i < num_cards-1; i++) {
        int min_index = i;
        for (int j = i+1; j < num_cards; j++) {
            if (sorted_values[j] < sorted_values[min_index]) {
                min_index = j;
            }
        }
        int temp = sorted_values[i];
        sorted_values[i] = sorted_values[min_index];
        sorted_values[min_index] = temp;
    }
    for (int i = 0; i < num_cards-1; i++) {
        if (sorted_values[i]+1 != sorted_values[i+1]) {
            straight = 0;
            break;
        }
        straight = 1;
    }
    int suits[num_cards];
    for (int i = 0; i < num_cards; i++) {
        suits[i] = cards[i] / 13;
    }
    for (int i = 0; i < num_cards-1; i++) {
        if (suits[i] != suits[i+1]) {
            flush = 0;
            break;
        }
        flush = 1;
    }
    if (straight && flush) {
        return 9;
    } else if (four) {
        return 8;
    } else if (three && pair) {
        return 7;
    } else if (flush) {
        return 6;
    } else if (straight) {
        return 5;
    } else if (three) {
        return 4;
    } else if (pair) {
        return 3;
    } else {
        return sorted_values[num_cards-1];
    }
}

void print_hand_rank(int rank) {
    switch (rank) {
        case 9:
            printf("straight flush");
            break;
        case 8:
            printf("four of a kind");
            break;
        case 7:
            printf("full house");
            break;
        case 6:
            printf("flush");
            break;
        case 5:
            printf("straight");
            break;
        case 4:
            printf("three of a kind");
            break;
        case 3:
            printf("two pair");
            break;
        case 2:
            printf("one pair");
            break;
        case 1:
            printf("high card");
            break;
    }
}