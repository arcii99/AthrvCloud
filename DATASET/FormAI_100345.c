//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 28 // the width of the game board
#define HEIGHT 36 // the height of the game board
#define MAX_GHOSTS 4 // the number of ghosts

// represent the direction a player is moving
enum direction {
  UP,
  LEFT,
  DOWN,
  RIGHT
};

// represent the type of cell on the game board
enum cell_type {
  EMPTY,
  WALL,
  DOT,
  ENERGIZER
};

// represent a single spot on the game board
struct cell {
  enum cell_type type;
  int x;
  int y;
};

// represent a player
struct player {
  int x;
  int y;
  enum direction dir;
};

// represent a ghost
struct ghost {
  int x;
  int y;
  enum direction dir;
};

// the game board
struct cell board[HEIGHT][WIDTH];

// the players
struct player players[2];

// the ghosts
struct ghost ghosts[MAX_GHOSTS];

// the score
int score = 0;

// initialize the game board
void init_board() {
  // set all cells to empty
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      board[y][x].type = EMPTY;
      board[y][x].x = x;
      board[y][x].y = y;
    }
  }
  
  // add the walls
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1) {
        board[y][x].type = WALL;
      }
    }
  }
  
  // add the dots
  for (int y = 1; y < HEIGHT - 1; y++) {
    for (int x = 1; x < WIDTH - 1; x++) {
      if (y % 2 == 0 && x % 2 == 0) {
        board[y][x].type = DOT;
      }
    }
  }
  
  // add the energizer
  board[17][13].type = ENERGIZER;
}

// initialize the players and ghosts
void init_players_and_ghosts() {
  // initialize player 1 at the top left corner
  players[0].x = 1;
  players[0].y = 1;
  players[0].dir = RIGHT;
  
  // initialize player 2 at the bottom right corner
  players[1].x = WIDTH - 2;
  players[1].y = HEIGHT - 2;
  players[1].dir = LEFT;
  
  // initialize the ghosts randomly
  srand(time(NULL));
  for (int i = 0; i < MAX_GHOSTS; i++) {
    ghosts[i].x = rand() % (WIDTH - 2) + 1;
    ghosts[i].y = rand() % (HEIGHT - 2) + 1;
    ghosts[i].dir = rand() % 4;
  }
}

// move a player or ghost in a specific direction
void move(int x, int y, enum direction dir) {
  switch (dir) {
    case UP:
      y--;
      break;
    case LEFT:
      x--;
      break;
    case DOWN:
      y++;
      break;
    case RIGHT:
      x++;
      break;
  }
  
  // check if it's possible to move
  if (board[y][x].type != WALL) {
    // update position
    if (dir == UP || dir == DOWN) {
      board[y][x].y = y;
    } else {
      board[y][x].x = x;
    }
  }
}

// move all players and ghosts
void move_all() {
  // move players
  for (int i = 0; i < 2; i++) {
    move(players[i].x, players[i].y, players[i].dir);
  }
  
  // move ghosts
  for (int i = 0; i < MAX_GHOSTS; i++) {
    move(ghosts[i].x, ghosts[i].y, ghosts[i].dir);
  }
}

// detect collisions between players and ghosts
void detect_collisions() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < MAX_GHOSTS; j++) {
      if (players[i].x == ghosts[j].x && players[i].y == ghosts[j].y) {
        printf("Player %d collided with ghost %d!\n", i+1, j+1);
        exit(0);
      }
    }
  }
}

// update the score based on the cell type
void update_score() {
  for (int i = 0; i < 2; i++) {
    int x = players[i].x;
    int y = players[i].y;
    if (board[y][x].type == DOT) {
      score++;
      board[y][x].type = EMPTY;
    } else if (board[y][x].type == ENERGIZER) {
      score += 10;
      board[y][x].type = EMPTY;
      // make ghosts run away from players for a few seconds
      for (int j = 0; j < MAX_GHOSTS; j++) {
        ghosts[j].dir += 2; // reverse direction
      }
    }
  }
}

// print the game board
void print_board() {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (y == players[0].y && x == players[0].x) {
        printf("1"); // player 1
      } else if (y == players[1].y && x == players[1].x) {
        printf("2"); // player 2
      } else if (board[y][x].type == WALL) {
        printf("#");
      } else if (board[y][x].type == DOT) {
        printf(".");
      } else if (board[y][x].type == ENERGIZER) {
        printf("O");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// the main game loop
void game_loop() {
  while (1) {
    // clear the console and print the board
    system("clear");
    print_board();
    
    // move the players and ghosts
    move_all();
    
    // detect collisions between players and ghosts
    detect_collisions();
    
    // update the score based on the cell type
    update_score();
    
    // check if the game is over
    if (score == 109) {
      printf("Game over! You win!\n");
      exit(0);
    }
    
    // wait for a second
    sleep(1);
  }
}

int main() {
  // initialize the game board
  init_board();
  
  // initialize the players and ghosts
  init_players_and_ghosts();
  
  // start the game loop
  game_loop();
  
  return 0;
}