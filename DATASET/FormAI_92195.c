//FormAI DATASET v1.0 Category: Poker Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define MAX_HAND_SIZE 5
#define NUM_CARDS 52

int deck[NUM_CARDS];

typedef struct player {
    int hand[MAX_HAND_SIZE];
    int score;
    char name[20];
} Player;

void shuffle_deck() {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i] = i;
        int j = rand() % NUM_CARDS;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards(Player players[]) {
    int current_card = 0;
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < MAX_HAND_SIZE; j++) {
            players[i].hand[j] = deck[current_card];
            current_card++;
        }
    }
}

void display_hand(int hand[], int size) {
    for (int i = 0; i < size; i++) {
        int card = hand[i];
        int suit = card / 13;
        int rank = card % 13;
        char suits[4][10] = {"Spades", "Hearts", "Diamonds", "Clubs"};
        char ranks[13][10] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
        printf("%s of %s\n", ranks[rank], suits[suit]);
    }
}

void display_table(Player players[]) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%s's hand:\n", players[i].name);
        display_hand(players[i].hand, MAX_HAND_SIZE);
        printf("\n");
    }
}

void get_player_names(Player players[]) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
    }
}

void get_scores(Player players[]) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        int score = 0;
        for (int j = 0; j < MAX_HAND_SIZE; j++) {
            int card = players[i].hand[j];
            int rank = card % 13;
            score += rank + 1;
        }
        players[i].score = score;
        printf("%s got a total score of %d\n", players[i].name, score);
    }
}

void find_winner(Player players[]) {
    int max_score = -1;
    int max_index = -1;
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
            max_index = i;
        }
    }
    printf("%s wins with a score of %d!\n", players[max_index].name, max_score);
}

int main() {
    printf("Shuffling deck...\n");
    shuffle_deck();

    Player players[NUM_PLAYERS];
    get_player_names(players);

    printf("\nDealing cards...\n");
    deal_cards(players);

    printf("\nDisplaying hands...\n");
    display_table(players);

    printf("\nCalculating scores...\n");
    get_scores(players);

    printf("\nFinding winner...\n");
    find_winner(players);

    return 0;
}