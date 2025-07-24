//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5

int scoreboard[MAX_PLAYERS] = {0};
int current_round = 1;

pthread_mutex_t mutex;

struct player {
    int id;
    int score;
};

void *play_game(void *player_id) {
    int pid = *(int*)player_id;
    printf("Player %d is ready to play.\n", pid);

    for (int i = 1; i <= MAX_ROUNDS; i++) {
        int points = rand() % 101;
        printf("Player %d scored %d points in round %d.\n", pid, points, i);

        pthread_mutex_lock(&mutex);
        scoreboard[pid] += points;
        pthread_mutex_unlock(&mutex);

        sleep(1); // Wait for other players to finish the round
    }

    printf("Player %d finished the game with a total score of %d.\n", pid, scoreboard[pid]);

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    pthread_t players[MAX_PLAYERS];
    int player_ids[MAX_PLAYERS];

    pthread_mutex_init(&mutex, NULL);

    printf("Welcome to the Multi-Player Scoreboard Game!\n");
    printf("There will be %d rounds of the game.\n", MAX_ROUNDS);
    printf("There are %d players in this game.\n", MAX_PLAYERS);

    for (int i = 0; i < MAX_PLAYERS; i++) {
        player_ids[i] = i;
        scoreboard[i] = 0;
        pthread_create(&players[i], NULL, play_game, (void*)&player_ids[i]);
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        pthread_join(players[i], NULL);
    }

    printf("All players have finished the game!\n");

    printf("Final scores after %d rounds of the game:\n", MAX_ROUNDS);
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d: %d\n", i, scoreboard[i]);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}