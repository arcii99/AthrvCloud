//FormAI DATASET v1.0 Category: Poker Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define CARD_FACE 13
#define HAND_SIZE 5

typedef enum { false, true } bool;

typedef struct card
{
    int face;
    int suit;
} Card;

typedef struct player
{
    int id;
    Card hand[HAND_SIZE];
    int score;
    bool fold;
} Player;

void init_deck(Card *deck) {
    int index = 0;
    for (int i = 0; i < CARD_FACE; i++) {
        for (int j = 0; j < 4; j++) {
            deck[index].face = i;
            deck[index].suit = j;
            index++;
        }
    }
}

void shuffle_deck(Card *deck) {
    time_t t;
    srand((unsigned)time(&t));
    for (int i = 0; i < DECK_SIZE; i++) {
        int random_index = rand() % DECK_SIZE;
        Card temp_card = deck[random_index];
        deck[random_index] = deck[i];
        deck[i] = temp_card;
    }
}

void deal_cards(Card *deck, Player *players, int num_of_players) {
    int deck_index = 0;
    for (int i = 0; i < HAND_SIZE; i++) {
        for (int j = 0; j < num_of_players; j++) {
            players[j].hand[i] = deck[deck_index];
            deck_index++;
        }
    }
}

void print_cards(Player player) {
    printf("Player %d's hand: ", player.id);
    for (int i = 0; i < HAND_SIZE; i++) {
        printf("[%d %d] ", player.hand[i].face, player.hand[i].suit);
    }
    printf("\n");
}

void print_scores(Player *players, int num_of_players) {
    for (int i = 0; i < num_of_players; i++) {
        printf("Player %d's score: %d\n", players[i].id, players[i].score);
    }
}

void update_scores(Player *players, int num_of_players) {
    for (int i = 0; i < num_of_players; i++) {
        players[i].score = 0;
        for (int j = 0; j < HAND_SIZE; j++) {
            players[i].score += players[i].hand[j].face + 1;
        }
    }
}

void evaluate_winning_hand(Player *players, int num_of_players) {
    int max_score = -1;
    int winning_player_index = -1;
    for (int i = 0; i < num_of_players; i++) {
        if (!players[i].fold && players[i].score > max_score) {
            max_score = players[i].score;
            winning_player_index = i;
        }
    }
    printf("Player %d wins!\n", players[winning_player_index].id);
}

int main() {
    int num_of_players = 3;
    Player players[num_of_players];
    Card deck[DECK_SIZE];
    for (int i = 0; i < num_of_players; i++) {
        players[i].id = i + 1;
        players[i].score = 0;
        players[i].fold = false;
    }

    init_deck(deck);
    shuffle_deck(deck);
    deal_cards(deck, players, num_of_players);

    for (int i = 0; i < num_of_players; i++) {
        print_cards(players[i]);
    }

    update_scores(players, num_of_players);
    print_scores(players, num_of_players);

    evaluate_winning_hand(players, num_of_players);


    return 0;
}