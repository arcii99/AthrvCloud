//FormAI DATASET v1.0 Category: Poker Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_PLAYERS 4
#define CARDS_PER_PLAYER 5
#define DECK_SIZE 52

// Structs
typedef struct Card {
    int rank;
    int suit;
} Card;

typedef struct Player {
    int id;
    Card hand[CARDS_PER_PLAYER];
    int score;
    int has_folded;
} Player;

// Function prototypes
void shuffle_deck(Card *deck);
void deal_cards(Card *deck, Player *players);
void print_card(Card card);
void print_hand(Player *player);
int calculate_score(Player *player);
int compare_hands(Player *a, Player *b);
void play_game(Player *players);

int main() {
    srand(time(NULL)); // Seed random number generator

    Player players[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].id = i+1;
        players[i].score = 0;
        players[i].has_folded = 0;
    }

    // Play game
    play_game(players);

    return 0;
}

void shuffle_deck(Card *deck) {
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards(Card *deck, Player *players) {
    for (int i = 0; i < CARDS_PER_PLAYER; i++) {
        for (int j = 0; j < MAX_PLAYERS; j++) {
            players[j].hand[i] = deck[i + j*CARDS_PER_PLAYER];
        }
    }
}

void print_card(Card card) {
    char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    printf("%s of %s\n", ranks[card.rank], suits[card.suit]);
}

void print_hand(Player *player) {
    printf("Player %d's Hand:\n", player->id);
    for (int i = 0; i < CARDS_PER_PLAYER; i++) {
        print_card(player->hand[i]);
    }
}

int calculate_score(Player *player) {
    int score = 0;

    // Face cards are worth 10 points
    for (int i = 0; i < CARDS_PER_PLAYER; i++) {
        if (player->hand[i].rank >= 10) {
            score += 10;
        }
    }

    // Ace can be worth 1 or 11 points
    int num_aces = 0;
    for (int i = 0; i < CARDS_PER_PLAYER; i++) {
        if (player->hand[i].rank == 0) {
            num_aces++;
        }
    }

    if (num_aces == 1) {
        if (score + 11 <= 21) {
            score += 11;
        } else {
            score += 1;
        }
    } else if (num_aces > 1) {
        for (int i = 0; i < num_aces; i++) {
            if (score + 11 <= 21) {
                score += 11;
            } else {
                score += 1;
            }
        }
    }

    // Add up value of non-face cards
    for (int i = 0; i < CARDS_PER_PLAYER; i++) {
        if (player->hand[i].rank < 10) {
            score += player->hand[i].rank + 1;
        }
    }

    player->score = score;
    return score;
}

int compare_hands(Player *a, Player *b) {
    if (a->score > b->score) {
        return 1;
    } else if (a->score < b->score) {
        return -1;
    } else {
        return 0;
    }
}

void play_game(Player *players) {
    // Initialize deck
    Card deck[DECK_SIZE];
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i].rank = i % 13;
        deck[i].suit = i / 13;
    }

    int round = 1;
    while (1) {
        printf("BEGIN ROUND %d\n", round);

        // Shuffle deck and deal cards
        shuffle_deck(deck);
        deal_cards(deck, players);

        // Print hands
        for (int i = 0; i < MAX_PLAYERS; i++) {
            print_hand(&players[i]);
            calculate_score(&players[i]);
            printf("Player %d's score: %d\n", players[i].id, players[i].score);
        }

        // Determine winner of round
        int winning_player = 0;
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (!players[i].has_folded) {
                winning_player = i;
                break;
            }
        }

        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (!players[i].has_folded && compare_hands(&players[i], &players[winning_player]) == 1) {
                winning_player = i;
            }
        }

        printf("Player %d wins the round!\n", players[winning_player].id);
        players[winning_player].score++;

        // Check for game over
        int game_over = 0;
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (players[i].score >= 5) { // Player wins if they reach 5 points
                printf("GAME OVER\n");
                printf("Player %d wins!\n", players[i].id);
                game_over = 1;
                break;
            }
        }

        if (game_over) {
            break;
        }

        // Prompt for next round
        char next_round_input[10];
        printf("Press enter to start next round.\n");
        fgets(next_round_input, 10, stdin);
        round++;
    }
}