//FormAI DATASET v1.0 Category: Poker Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* The following constants are used to represent the cards */

#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define TEN 10
#define JACK 11
#define QUEEN 12
#define KING 13
#define ACE 14

/* The following constants are used to represent the suits */

#define CLUBS 1
#define DIAMONDS 2
#define HEARTS 3
#define SPADES 4

/* The following constants are used to represent the game */

#define HAND_SIZE 5
#define NUM_PLAYERS 3
#define NUM_ROUNDS 3

/* The following structures are used to represent the cards and the players */

struct card {
    int rank;
    int suit;
};

struct player {
    char name[20];
    struct card hand[HAND_SIZE];
    int score;
};

/* The following function prototypes are used to define the functions used in the program */

void create_deck(struct card deck[]);
void shuffle_deck(struct card deck[]);
void deal_cards(struct player players[], struct card deck[]);
void print_player_hand(struct player player);
int get_high_card(struct player player);
int get_pair(struct player player);
int get_two_pair(struct player player);
int get_three_of_a_kind(struct player player);
int get_straight(struct player player);
int get_flush(struct player player);
int get_full_house(struct player player);
int get_four_of_a_kind(struct player player);
int get_straight_flush(struct player player);
void play_round(struct player players[], struct card deck[]);
void print_winner(struct player players[]);

/* The main function of the program */

int main(void) {
    struct player players[NUM_PLAYERS] = {
        {"Player 1", {}, 0},
        {"Player 2", {}, 0},
        {"Player 3", {}, 0}
    };

    struct card deck[52];

    srand(time(NULL));

    create_deck(deck);

    shuffle_deck(deck);

    for (int i = 0; i < NUM_ROUNDS; i++) {
        deal_cards(players, deck);

        for (int j = 0; j < NUM_PLAYERS; j++) {
            printf("%s's hand:\n", players[j].name);
            print_player_hand(players[j]);
            printf("\n");
        }

        play_round(players, deck);

        printf("\n");
        print_winner(players);

        for (int k = 0; k < NUM_PLAYERS; k++) {
            players[k].score = 0;
        }
    }

    return 0;
}

/* The following function is used to create a deck of cards */

void create_deck(struct card deck[]) {
    int index = 0;

    for (int rank = TWO; rank <= ACE; rank++) {
        for (int suit = CLUBS; suit <= SPADES; suit++) {
            deck[index].rank = rank;
            deck[index].suit = suit;
            index++;
        }
    }
}

/* The following function is used to shuffle a deck of cards */

void shuffle_deck(struct card deck[]) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        struct card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

/* The following function is used to deal a hand of cards to each player */

void deal_cards(struct player players[], struct card deck[]) {
    int index = 0;

    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < HAND_SIZE; j++) {
            players[i].hand[j] = deck[index];
            index++;
        }
    }
}

/* The following function is used to print a player's hand of cards */

void print_player_hand(struct player player) {
    for (int i = 0; i < HAND_SIZE; i++) {
        printf("%d of ", player.hand[i].rank);
        switch (player.hand[i].suit) {
            case CLUBS:
                printf("Clubs\n");
                break;

            case DIAMONDS:
                printf("Diamonds\n");
                break;

            case HEARTS:
                printf("Hearts\n");
                break;

            case SPADES:
                printf("Spades\n");
                break;
        }
    }
}

/* The following functions are used to evaluate a player's hand */

int get_high_card(struct player player) {
    int high_card = player.hand[0].rank;

    for (int i = 1; i < HAND_SIZE; i++) {
        if (player.hand[i].rank > high_card) {
            high_card = player.hand[i].rank;
        }
    }

    return high_card;
}

int get_pair(struct player player) {
    int rank_counts[15] = {0};

    for (int i = 0; i < HAND_SIZE; i++) {
        rank_counts[player.hand[i].rank]++;
    }

    for (int j = ACE; j >= TWO; j--) {
        if (rank_counts[j] == 2) {
            return j;
        }
    }

    return 0;
}

int get_two_pair(struct player player) {
    int pair1 = 0, pair2 = 0;
    int rank_counts[15] = {0};

    for (int i = 0; i < HAND_SIZE; i++) {
        rank_counts[player.hand[i].rank]++;
    }

    for (int j = ACE; j >= TWO; j--) {
        if (rank_counts[j] == 2) {
            if (pair1 == 0) {
                pair1 = j;
            } else if (pair2 == 0) {
                pair2 = j;
                return pair1 + pair2;
            }
        }
    }

    return 0;
}

int get_three_of_a_kind(struct player player) {
    int rank_counts[15] = {0};

    for (int i = 0; i < HAND_SIZE; i++) {
        rank_counts[player.hand[i].rank]++;
    }

    for (int j = ACE; j >= TWO; j--) {
        if (rank_counts[j] == 3) {
            return j;
        }
    }

    return 0;
}

int get_straight(struct player player) {
    int rank_counts[15] = {0};

    for (int i = 0; i < HAND_SIZE; i++) {
        rank_counts[player.hand[i].rank]++;
    }

    int count = 0;

    for (int j = ACE; j >= TWO; j--) {
        if (rank_counts[j] == 1) {
            count++;
        } else if (count >= 5) {
            return j + 4;
        } else {
            count = 0;
        }
    }

    if (count >= 5) {
        return 5;
    }

    return 0;
}

int get_flush(struct player player) {
    int suit_counts[5] = {0};

    for (int i = 0; i < HAND_SIZE; i++) {
        suit_counts[player.hand[i].suit]++;
    }

    for (int j = CLUBS; j <= SPADES; j++) {
        if (suit_counts[j] == 5) {
            return 1;
        }
    }

    return 0;
}

int get_full_house(struct player player) {
    int rank_counts[15] = {0};
    int three_of_a_kind = 0, pair = 0;

    for (int i = 0; i < HAND_SIZE; i++) {
        rank_counts[player.hand[i].rank]++;
    }

    for (int j = ACE; j >= TWO; j--) {
        if (rank_counts[j] == 3) {
            three_of_a_kind = j;
            break;
        }
    }

    if (three_of_a_kind > 0) {
        for (int k = ACE; k >= TWO; k--) {
            if (rank_counts[k] == 2 && k != three_of_a_kind) {
                pair = k;
                break;
            }
        }
    }

    if (three_of_a_kind > 0 && pair > 0) {
        return three_of_a_kind + pair;
    }

    return 0;
}

int get_four_of_a_kind(struct player player) {
    int rank_counts[15] = {0};

    for (int i = 0; i < HAND_SIZE; i++) {
        rank_counts[player.hand[i].rank]++;
    }

    for (int j = ACE; j >= TWO; j--) {
        if (rank_counts[j] == 4) {
            return j;
        }
    }

    return 0;
}

int get_straight_flush(struct player player) {
    if (get_straight(player) > 0 && get_flush(player) > 0) {
        return get_straight(player);
    }

    return 0;
}

/* The following function is used to play a round of the game */

void play_round(struct player players[], struct card deck[]) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        int hand_value = 0;
        struct player player = players[i];

        if ((hand_value = get_straight_flush(player)) > 0) {
            players[i].score = hand_value * 1000;
        } else if ((hand_value = get_four_of_a_kind(player)) > 0) {
            players[i].score = hand_value * 100;
        } else if ((hand_value = get_full_house(player)) > 0) {
            players[i].score = hand_value * 10;
        } else if ((hand_value = get_flush(player)) > 0) {
            players[i].score = get_high_card(player);
        } else if ((hand_value = get_straight(player)) > 0) {
            players[i].score = hand_value;
        } else if ((hand_value = get_three_of_a_kind(player)) > 0) {
            players[i].score = hand_value;
        } else if ((hand_value = get_two_pair(player)) > 0) {
            players[i].score = hand_value;
        } else if ((hand_value = get_pair(player)) > 0) {
            players[i].score = hand_value;
        } else {
            players[i].score = get_high_card(player);
        }
    }
}

/* The following function is used to print the winner of the game */

void print_winner(struct player players[]) {
    int highest_score = 0;
    struct player winner = players[0];

    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (players[i].score > highest_score) {
            highest_score = players[i].score;
            winner = players[i];
        }
    }

    printf("%s wins with a hand value of %d!\n", winner.name, highest_score);
}