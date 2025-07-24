//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Claude Shannon
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_X 70
#define MAX_Y 20
#define PADDLE_SIZE 3
#define BALL_SYMBOL 'o'
#define PADDLE_SYMBOL '#'
#define AI_DIFFICULTY 0.5 // 0.0 <= AI_DIFFICULTY <= 1.0

int ball_x, ball_y;
int ball_direction_x, ball_direction_y;
int paddle_y;
int ai_paddle_y;
int player_score, ai_score;

bool game_is_over = false;
bool ai_won = false;

char game_board[MAX_Y][MAX_X + 1];

void initialize_game_board() {
  int i, j;
  for (i = 0; i < MAX_Y; i++)
    for (j = 0; j < MAX_X; j++)
      game_board[i][j] = ' ';
  game_board[MAX_Y - 1][MAX_X] = '\0';
}

void print_game_board() {
  int i;
  for (i = 0; i < MAX_Y; i++)
    puts(game_board[i]);
}

void move_ball() {
  int new_x = ball_x + ball_direction_x;
  int new_y = ball_y + ball_direction_y;
  // check if ball hits the walls
  if (new_x < 0 || new_x >= MAX_X) {
    game_is_over = true;
    ai_won = true;
    return;
  }
  if (new_y < 0 || new_y >= MAX_Y) {
    game_is_over = true;
    return;
  }
  // check if ball hits the player's paddle
  if (new_x == 0 && new_y >= paddle_y && new_y < paddle_y + PADDLE_SIZE) {
    ball_direction_x = 1;
    ball_direction_y = (new_y - paddle_y - PADDLE_SIZE / 2) / 2;
  }
  // check if ball hits the AI's paddle
  if (new_x == MAX_X - 1 && new_y >= ai_paddle_y && new_y < ai_paddle_y + PADDLE_SIZE) {
    ball_direction_x = -1;
    ball_direction_y = (new_y - ai_paddle_y - PADDLE_SIZE / 2) / 2;
  }
  // update ball coordinates
  ball_x = new_x;
  ball_y = new_y;
}

void move_ai_paddle() {
  if (ball_direction_x == 1)
    return; // ball moving away from AI
  int target_y = ball_y - PADDLE_SIZE / 2 + rand() % PADDLE_SIZE;
  if (abs(target_y - ai_paddle_y) <= AI_DIFFICULTY * MAX_Y)
    ai_paddle_y = target_y;
  else if (target_y > ai_paddle_y)
    ai_paddle_y++;
  else
    ai_paddle_y--;
}

int main() {
  srand(time(NULL));
  // initialize game state
  ball_x = MAX_X / 2;
  ball_y = MAX_Y / 2;
  ball_direction_x = -1 + rand() % 2 * 2; // -1 or 1
  ball_direction_y = -1 + rand() % 3; // -1, 0, or 1
  paddle_y = MAX_Y / 2 - PADDLE_SIZE / 2;
  ai_paddle_y = paddle_y;
  player_score = 0;
  ai_score = 0;
  int i, j;
  // main game loop
  while (!game_is_over) {
    // clear game board
    initialize_game_board();
    // update game state
    move_ball();
    move_ai_paddle();
    // draw game elements
    for (i = 0; i < PADDLE_SIZE; i++) {
      game_board[paddle_y + i][0] = PADDLE_SYMBOL;
      game_board[ai_paddle_y + i][MAX_X - 1] = PADDLE_SYMBOL;
    }
    game_board[ball_y][ball_x] = BALL_SYMBOL;
    // print game board to screen
    system("clear");
    print_game_board();
    // print scores
    printf("Player: %d   AI: %d\n", player_score, ai_score);
    // wait for a short period of time
    usleep(50000);
  }
  // print end game message
  system("clear");
  if (ai_won)
    printf("Game Over! AI Wins!\n");
  else
    printf("Game Over! Player Wins!\n");
  printf("Final Score: Player: %d    AI: %d\n", player_score, ai_score);
  return 0;
}