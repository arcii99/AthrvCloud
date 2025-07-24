//FormAI DATASET v1.0 Category: Poker Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 6
#define MIN_BET 1
#define MAX_BET 100

typedef struct {
    char suit[9];
    int value;
} card;

typedef struct {
    card hand[5];
    int rank;
} player;

card deck[52];
int cards_drawn = 0;

player players[MAX_PLAYERS];
int num_players;
int pot = 0;

void shuffle_deck() {
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(card c) {
    printf("%d of %s\n", c.value, c.suit);
}

void print_hand(card *hand, int size) {
    for (int i = 0; i < size; i++) {
        print_card(hand[i]);
    }
}

void draw_card(card *hand) {
    hand[cards_drawn++] = deck[cards_drawn];
}

int get_value(card c) {
    if (c.value == 1) {
        return 14;
    } else {
        return c.value;
    }
}

int is_flush(card *hand) {
    for (int i = 1; i < 5; i++) {
        if (strcmp(hand[i].suit, hand[0].suit) != 0) {
            return 0;
        }
    }
    return 1;
}

int is_straight(card *hand) {
    for (int i = 0; i < 4; i++) {
        if (get_value(hand[i]) != get_value(hand[i+1]) - 1) {
            return 0;
        }
    }
    return 1;
}

int get_rank(card *hand) {
    int flush = is_flush(hand);
    int straight = is_straight(hand);
    if (flush && straight) {
        return 9;
    } else if (flush) {
        return 6;
    } else if (straight) {
        return 5;
    } else {
        return 0;
    }
}

void deal() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < num_players; j++) {
            draw_card(&(players[j].hand[i]));
        }
    }
    cards_drawn = 0;
    for (int i = 0; i < num_players; i++) {
        players[i].rank = get_rank(players[i].hand);
    }
}

int get_winner() {
    int winner = 0;
    for (int i = 1; i < num_players; i++) {
        if (players[i].rank > players[winner].rank) {
            winner = i;
        } else if (players[i].rank == players[winner].rank) {
            int winner_high = get_value(players[winner].hand[4]);
            int i_high = get_value(players[i].hand[4]);
            if (i_high > winner_high) {
                winner = i;
            }
        }
    }
    return winner;
}

void collect_bets() {
    for (int i = 0; i < num_players; i++) {
        int bet;
        printf("Player %d, place your bet: ", i+1);
        scanf("%d", &bet);
        while (bet < MIN_BET || bet > MAX_BET) {
            printf("Invalid bet. Please enter a bet between %d and %d: ", MIN_BET, MAX_BET);
            scanf("%d", &bet);
        }
        pot += bet;
    }
}

int main() {
    // Initialize deck
    int index = 0;
    for (int i = 1; i <= 13; i++) {
        deck[index].value = i;
        strcpy(deck[index].suit, "Hearts");
        index++;
        deck[index].value = i;
        strcpy(deck[index].suit, "Diamonds");
        index++;
        deck[index].value = i;
        strcpy(deck[index].suit, "Clubs");
        index++;
        deck[index].value = i;
        strcpy(deck[index].suit, "Spades");
        index++;
    }

    // Shuffle deck
    shuffle_deck();

    // Get number of players
    printf("Enter the number of players (2-%d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    while (num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Please enter a number between 2 and %d: ", MAX_PLAYERS);
        scanf("%d", &num_players);
    }

    // Initialize players
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < 5; j++) {
            players[i].hand[j].value = 0;
            strcpy(players[i].hand[j].suit, "");
        }
    }

    // Collect bets
    collect_bets();

    // Deal cards
    deal();

    // Show hands
    for (int i = 0; i < num_players; i++) {
        printf("Player %d's hand:\n", i+1);
        print_hand(players[i].hand, 5);
    }

    // Determine winner
    int winner = get_winner();
    printf("Player %d wins the pot of %d!\n", winner+1, pot);

    return 0;
}