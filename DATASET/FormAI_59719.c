//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAP_SIZE 25
#define NUM_PLAYERS 4

// The game map
char map[MAP_SIZE][MAP_SIZE];

// Lock for updating the map
pthread_mutex_t map_lock;

// The player struct
typedef struct player {
  int id; // player ID
  int x; // player x position
  int y; // player y position
  int score; // player score
} player_t;

// The array of players
player_t players[NUM_PLAYERS];

// The thread function for a player
void* player_func(void* arg) {
  player_t* p = (player_t*) arg;
  while (1) {
    // Update the position randomly
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;
    pthread_mutex_lock(&map_lock);
    if (map[p->y + dy][p->x + dx] == '.') {
      map[p->y][p->x] = '.';
      p->x += dx;
      p->y += dy;
      p->score++;
      map[p->y][p->x] = p->id + 1 + '0'; // update the map with player ID
    }
    pthread_mutex_unlock(&map_lock);
    usleep(100 * 1000); // wait for 100 milliseconds
  }
  return NULL;
}

// The main function
int main() {
  // Initialize the map
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      map[i][j] = '.';
    }
  }
  // Initialize the players randomly
  srand(time(NULL));
  for (int i = 0; i < NUM_PLAYERS; i++) {
    players[i].id = i;
    players[i].x = rand() % MAP_SIZE;
    players[i].y = rand() % MAP_SIZE;
    players[i].score = 0;
    map[players[i].y][players[i].x] = i + 1 + '0'; // update the map with player ID
  }
  // Create the player threads
  pthread_t threads[NUM_PLAYERS];
  for (int i = 0; i < NUM_PLAYERS; i++) {
    pthread_create(&threads[i], NULL, player_func, &players[i]);
  }
  // Start the game loop
  while (1) {
    // Print the map
    printf("\033[2J\033[1;1H"); // clear the screen
    for (int i = 0; i < MAP_SIZE; i++) {
      for (int j = 0; j < MAP_SIZE; j++) {
        printf("%c", map[i][j]);
      }
      printf("\n");
    }
    // Print the players' scores
    printf("Scores:\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
      printf("Player %d: %d\n", i + 1, players[i].score);
    }
    usleep(100 * 1000); // wait for 100 milliseconds
  }
  return 0;
}