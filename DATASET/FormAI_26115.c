//FormAI DATASET v1.0 Category: Table Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Number of players
#define NUM_PLAYERS 4

// Maximum number of rounds in the game
#define MAX_ROUNDS 10

// Structure for player data
struct Player {
  int id;
  int score;
};

// Global variables
int round = 1;
int active_players = NUM_PLAYERS;
pthread_mutex_t lock;

// Function declarations
void *play_game(void *arg);
int roll_dice();

int main() {
  // Seed random number generator
  srand(time(NULL));
  
  // Initialize mutex lock
  if (pthread_mutex_init(&lock, NULL) != 0) {
    printf("Mutex init failed\n");
    return 1;
  }
  
  // Initialize player array
  struct Player players[NUM_PLAYERS];
  for (int i = 0; i < NUM_PLAYERS; i++) {
    players[i].id = i + 1;
    players[i].score = 0;
  }
  
  // Create player threads
  pthread_t player_threads[NUM_PLAYERS];
  for (int i = 0; i < NUM_PLAYERS; i++) {
    if (pthread_create(&player_threads[i], NULL, play_game, (void *)&players[i]) != 0) {
      printf("Thread create failed\n");
      return 1;
    }
  }
  
  // Join player threads
  for (int i = 0; i < NUM_PLAYERS; i++) {
    if (pthread_join(player_threads[i], NULL) != 0) {
      printf("Thread join failed\n");
      return 1;
    }
  }
  
  // Destroy mutex lock
  pthread_mutex_destroy(&lock);
  
  // Print final scores
  printf("\nFinal Scores:\n");
  for (int i = 0; i < NUM_PLAYERS; i++) {
    printf("Player %d: %d\n", players[i].id, players[i].score);
  }
  
  return 0;
}

void *play_game(void *arg) {
  struct Player *player = (struct Player *)arg;
  printf("Player %d has joined the game\n", player->id);
  
  // Play rounds until game is finished
  while (round <= MAX_ROUNDS && active_players > 0) {
    // Roll dice
    int score = roll_dice();
    
    // Lock mutex
    pthread_mutex_lock(&lock);
    
    // Update player score
    player->score += score;
    printf("Player %d rolled a %d in round %d and now has a total score of %d\n", player->id, score, round, player->score);
    
    // Check if player has won the game
    if (player->score >= 100) {
      printf("Player %d has won the game!\n", player->id);
      active_players--;
    }
    
    // Unlock mutex
    pthread_mutex_unlock(&lock);
    
    // Sleep for 1 second to simulate gameplay
    sleep(1);
  }
  
  printf("Player %d has left the game\n", player->id);
  
  return NULL;
}

int roll_dice() {
  return rand() % 6 + 1;
}