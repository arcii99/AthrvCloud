//FormAI DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_PLAYER 4
#define MAX_ROUNDS 10

typedef struct {
    int* player_score[MAX_PLAYER];
    int* player_choice[MAX_PLAYER];
    int round_score[MAX_ROUNDS];
    int num_rounds;
    int current_round;
} Game;

void init_game(Game* game, int num_players, int num_rounds) {
    game->num_rounds = num_rounds;
    game->current_round = 0;

    for(int i = 0; i < num_players; i++) {
        game->player_score[i] = malloc(sizeof(int) * num_rounds);
        game->player_choice[i] = malloc(sizeof(int) * num_rounds);
        for(int j = 0; j < num_rounds; j++) {
            game->player_score[i][j] = 0;
            game->player_choice[i][j] = -1;
        }
    }

    for(int i = 0; i < num_rounds; i++) {
        game->round_score[i] = 0;
    }
}

void cleanup_game(Game* game, int num_players) {
    for(int i = 0; i < num_players; i++) {
        free(game->player_score[i]);
        free(game->player_choice[i]);
    }
}

void play_round(Game* game, int num_players) {
    printf("Round %d\n", game->current_round+1);
    printf("----------------------\n");

    // Get player choices
    for(int i = 0; i < num_players; i++) {
        printf("Player %d, please choose a number between 1 and 10: ", i+1);
        int choice;
        scanf("%d", &choice);
        game->player_choice[i][game->current_round] = choice;
    }

    // Calculate scores
    for(int i = 0; i < num_players; i++) {
        int score = 0;
        for(int j = 0; j < num_players; j++) {
            if(i != j && game->player_choice[i][game->current_round] == game->player_choice[j][game->current_round]) {
                score += 10;
            }
        }
        game->player_score[i][game->current_round] = score;
        game->round_score[game->current_round] += score;
    }

    game->current_round++;
}

void print_scores(Game* game, int num_players) {
    printf("Total scores\n");
    for(int i = 0; i < num_players; i++) {
        int score = 0;
        for(int j = 0; j < game->num_rounds; j++) {
            score += game->player_score[i][j];
        }
        printf("Player %d: %d\n", i+1, score);
    }
}

int main() {
    int num_players = 4;
    int num_rounds = 10;

    printf("Welcome to Multiplayer Memory Game!\n");
    printf("-----------------------------------\n");
    printf("Number of players: %d\n", num_players);
    printf("Number of rounds: %d\n", num_rounds);

    Game game;
    init_game(&game, num_players, num_rounds);

    for(int i = 0; i < num_rounds; i++) {
        play_round(&game, num_players);
    }

    print_scores(&game, num_players);

    cleanup_game(&game, num_players);

    return 0;
}