//FormAI DATASET v1.0 Category: Poker Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 6
#define MAX_CARDS 52
#define HAND_SIZE 5

// Definition of a card structure
typedef struct {
    int rank;
    int suit;
} Card;

// Definition of a player structure
typedef struct {
    char name[20];
    Card hand[HAND_SIZE];
    int score;
} Player;

// Function to print a card
void print_card(Card c) {
    char ranks[] = {'0', 'A', '2', '3', '4', '5',
                    '6', '7', '8', '9', 'T', 'J',
                    'Q', 'K'};
    char suits[] = {'C', 'D', 'H', 'S'};
    printf("%c%c ", ranks[c.rank], suits[c.suit]);
}

// Function to print a player's hand
void print_hand(Player p) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        print_card(p.hand[i]);
    }
    printf("(%d)\n", p.score);
}

// Function to compare two cards by rank
int compare_ranks(const void *a, const void *b) {
    int rank_a = ((Card *)a)->rank;
    int rank_b = ((Card *)b)->rank;
    if (rank_a == 1) {
        rank_a = 14;
    }
    if (rank_b == 1) {
        rank_b = 14;
    }
    return rank_b - rank_a;
}

// Function to compare two cards by suit
int compare_suits(const void *a, const void *b) {
    int suit_a = ((Card *)a)->suit;
    int suit_b = ((Card *)b)->suit;
    return suit_a - suit_b;
}

// Function to evaluate a hand and return its score
int evaluate_hand(Card *hand) {
    int i, j;
    int pair_count = 0;
    int straight_count = 0;
    int flush_count = 0;
    int three_count = 0;
    int four_count = 0;
    int score = 0;
    qsort(hand, HAND_SIZE, sizeof(Card), compare_ranks);
    for (i = 0; i < HAND_SIZE - 1; i++) {
        if (hand[i].rank == hand[i+1].rank) {
            pair_count++;
        }
        if (hand[i].rank == hand[i+1].rank - 1) {
            straight_count++;
        }
    }
    if (hand[0].rank == 1 && hand[1].rank == 10 &&
        hand[2].rank == 11 && hand[3].rank == 12 &&
        hand[4].rank == 13) {
        straight_count++;
    }
    if (pair_count == 1) {
        score += 1;
    }
    if (pair_count == 2) {
        score += 3;
    }
    if (straight_count == 4) {
        score += 2;
    }
    qsort(hand, HAND_SIZE, sizeof(Card), compare_suits);
    for (i = 0; i < HAND_SIZE - 1; i++) {
        if (hand[i].suit == hand[i+1].suit) {
            flush_count++;
        }
    }
    if (flush_count == 4) {
        score += 4;
    }
    for (i = 0; i < HAND_SIZE; i++) {
        three_count = 0;
        for (j = 0; j < HAND_SIZE; j++) {
            if (hand[i].rank == hand[j].rank) {
                three_count++;
            }
        }
        if (three_count == 3) {
            score += 8;
        }
    }
    for (i = 0; i < HAND_SIZE; i++) {
        four_count = 0;
        for (j = 0; j < HAND_SIZE; j++) {
            if (hand[i].rank == hand[j].rank) {
                four_count++;
            }
        }
        if (four_count == 4) {
            score += 16;
        }
    }
    return score;
}

// Main function
int main() {
    int i, j, k;
    int num_players;
    Card deck[MAX_CARDS];
    Player players[MAX_PLAYERS];
    // Initialize the deck
    k = 0;
    for (i = 1; i <= 13; i++) {
        for (j = 0; j < 4; j++) {
            deck[k].rank = i;
            deck[k].suit = j;
            k++;
        }
    }
    // Get the number of players
    printf("How many players? ");
    scanf("%d", &num_players);
    if (num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }
    // Initialize each player's hand and score
    for (i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        for (j = 0; j < HAND_SIZE; j++) {
            int card_index = rand() % (MAX_CARDS - j);
            players[i].hand[j] = deck[card_index];
            deck[card_index] = deck[MAX_CARDS - j - 1];
        }
        players[i].score = evaluate_hand(players[i].hand);
    }
    // Print each player's hand and score
    for (i = 0; i < num_players; i++) {
        printf("%s's hand: ", players[i].name);
        print_hand(players[i]);
    }
    // Determine the winner
    int max_score = 0;
    int winner_count = 0;
    for (i = 0; i < num_players; i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
            winner_count = 1;
        } else if (players[i].score == max_score) {
            winner_count++;
        }
    }
    if (winner_count == 1) {
        for (i = 0; i < num_players; i++) {
            if (players[i].score == max_score) {
                printf("%s wins!\n", players[i].name);
                break;
            }
        }
    } else {
        printf("Tie between:");
        for (i = 0; i < num_players; i++) {
            if (players[i].score == max_score) {
                printf(" %s", players[i].name);
            }
        }
        printf("\n");
    }
    return 0;
}