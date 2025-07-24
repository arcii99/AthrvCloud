//FormAI DATASET v1.0 Category: Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 5

struct player { 
    char name[20];
    int score;
} players[MAX_PLAYERS];

int round_scores[MAX_ROUNDS][MAX_PLAYERS];

void play_round(int round_num) {
    printf("Round %d\n", round_num);
    for (int i=0; i<MAX_PLAYERS; i++) {
        printf("%s, enter your score: ", players[i].name);
        scanf("%d", &round_scores[round_num][i]);
    }
}

void calculate_scores() {
    for (int i=0; i<MAX_PLAYERS; i++) {
        players[i].score = 0;
        for (int j=0; j<MAX_ROUNDS; j++) {
            players[i].score += round_scores[j][i];
        }
    }
}

void print_scores() {
    for (int i=0; i<MAX_PLAYERS; i++) {
        printf("%s's total score: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    for (int i=0; i<MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
    }
    for (int i=0; i<MAX_ROUNDS; i++) {
        play_round(i);
    }
    calculate_scores();
    print_scores();
    return 0;
}