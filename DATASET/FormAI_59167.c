//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Define the temperature range
#define MIN_TEMP 0
#define MAX_TEMP 100

// Define the number of players
#define NUM_PLAYERS 4

// Define the structure for each player
typedef struct {
    int player_id;
    int current_temp;
} player_t;

// Define the structure for the game
typedef struct {
    player_t players[NUM_PLAYERS];
    int target_temp;
    int num_rounds;
    int current_round;
    int is_game_over;
    pthread_mutex_t lock;
} game_t;

// Function to generate a random temperature within the range
int generate_random_temp() {
    return rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
}

// Function to simulate the actions of a player
void* player_action(void* arg) {
    game_t* game = (game_t*)arg;
    player_t* player = &(game->players[game->current_round % NUM_PLAYERS]);

    // Each player sets a new temperature
    int new_temp = generate_random_temp();
    player->current_temp = new_temp;

    // Check if the target temperature has been reached
    if (new_temp == game->target_temp) {
        game->is_game_over = 1;
    }

    // Lock the mutex before printing
    pthread_mutex_lock(&game->lock);

    printf("Player %d set temperature to %d\n", player->player_id, new_temp);

    if (game->is_game_over) {
        printf("Player %d wins!\n", player->player_id);
    }

    // Unlock the mutex
    pthread_mutex_unlock(&game->lock);

    // Sleep for a short time to simulate processing
    usleep(1000);
}

int main() {
    srand(time(0));

    // Initialize the game
    game_t game;
    game.num_rounds = 10;
    game.target_temp = generate_random_temp();
    game.current_round = 0;
    game.is_game_over = 0;
    pthread_mutex_init(&game.lock, NULL);

    // Initialize the players
    for (int i = 0; i < NUM_PLAYERS; i++) {
        game.players[i].player_id = i;
        game.players[i].current_temp = MIN_TEMP;
    }

    // Loop through each round of the game
    while (!game.is_game_over && game.current_round < game.num_rounds) {
        printf("Round %d\n", game.current_round+1);

        // Launch a new thread for each player
        pthread_t threads[NUM_PLAYERS];
        for (int i = 0; i < NUM_PLAYERS; i++) {
            pthread_create(&threads[i], NULL, player_action, &game);
        }

        // Wait for all the threads to finish
        for (int i = 0; i < NUM_PLAYERS; i++) {
            pthread_join(threads[i], NULL);
        }

        // Increment the round counter
        game.current_round++;
    }

    // Destroy the mutex
    pthread_mutex_destroy(&game.lock);

    return 0;
}