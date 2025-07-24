//FormAI DATASET v1.0 Category: Poker Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_SUITS 4
#define NUM_RANKS 13

enum {CLUBS, DIAMONDS, HEARTS, SPADES};
enum {ACE, KING, QUEEN, JACK, TEN, NINE, EIGHT, SEVEN, SIX, FIVE, FOUR, THREE, TWO};

struct card {
    int suit;
    int rank;
};

struct player {
    char name[10];
    struct card hand[5];
};

void initialize_deck(struct card *deck);
void shuffle_deck(struct card *deck);
void deal_cards(struct card *deck, struct player *players, int num_players);
void print_hand(struct player player);
int evaluate_hand(struct player player);
int is_flush(struct player player);
int is_straight(struct player player);
int is_pair(struct player player);

int main(void) {
    int num_players;
    printf("How many players are playing? ");
    scanf("%d", &num_players);
    struct player players[num_players];
    struct card deck[NUM_CARDS];
    initialize_deck(deck);
    shuffle_deck(deck);
    deal_cards(deck, players, num_players);
    for (int i = 0; i < num_players; i++) {
        printf("%s's hand: ", players[i].name);
        print_hand(players[i]);
        printf("\n");
        printf("%s's score: %d\n", players[i].name, evaluate_hand(players[i]));
    }
    return 0;
}

void initialize_deck(struct card *deck) {
    int i = 0;
    for (int suit = CLUBS; suit <= SPADES; suit++) {
        for (int rank = ACE; rank <= TWO; rank++) {
            deck[i].suit = suit;
            deck[i].rank = rank;
            i++;
        }
    }
}

void shuffle_deck(struct card *deck) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        struct card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards(struct card *deck, struct player *players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i+1);
        scanf("%9s", players[i].name);
        for (int j = 0; j < 5; j++) {
            players[i].hand[j] = deck[(5 * i) + j];
        }
    }
}

void print_hand(struct player player) {
    for (int i = 0; i < 5; i++) {
        char suit;
        switch (player.hand[i].suit) {
            case CLUBS:
                suit = 'C';
                break;
            case DIAMONDS:
                suit = 'D';
                break;
            case HEARTS:
                suit = 'H';
                break;
            case SPADES:
                suit = 'S';
                break;
        }
        int rank = player.hand[i].rank;
        if (rank == ACE) {
            printf("A%c ", suit);
        } else if (rank == KING) {
            printf("K%c ", suit);
        } else if (rank == QUEEN) {
            printf("Q%c ", suit);
        } else if (rank == JACK) {
            printf("J%c ", suit);
        } else {
            printf("%d%c ", rank, suit);
        }
    }
}

int evaluate_hand(struct player player) {
    if (is_flush(player) && is_straight(player)) {
        return 100;
    } else if (is_flush(player)) {
        return 50;
    } else if (is_straight(player)) {
        return 25;
    } else if (is_pair(player)) {
        return 10;
    } else {
        return 0;
    }
}

int is_flush(struct player player) {
    int suit = player.hand[0].suit;
    for (int i = 1; i < 5; i++) {
        if (player.hand[i].suit != suit) {
            return 0;
        }
    }
    return 1;
}

int is_straight(struct player player) {
    int ranks[5];
    for (int i = 0; i < 5; i++) {
        ranks[i] = player.hand[i].rank;
    }
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += ranks[i];
    }
    if (sum == 28) { // special case for A,2,3,4,5 straight
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        int count = 0;
        for (int j = 0; j < 5; j++) {
            if (ranks[i] == ranks[j] + 1 || (ranks[i] == ACE && ranks[j] == KING)) {
                count++;
            }
        }
        if (count == 4) {
            return 1;
        }
    }
    return 0;
}

int is_pair(struct player player) {
    int ranks[5];
    for (int i = 0; i < 5; i++) {
        ranks[i] = player.hand[i].rank;
    }
    for (int i = 0; i < 5; i++) {
        int count = 0;
        for (int j = 0; j < 5; j++) {
            if (ranks[i] == ranks[j]) {
                count++;
            }
        }
        if (count == 2) {
            return 1;
        }
    }
    return 0;
}