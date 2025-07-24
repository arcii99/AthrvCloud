//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10 // Number of players
#define M 5 // Number of rounds

typedef struct {
  int id;
  float score;
  float x;
  float y;
} Player;

float distance(float x1, float y1, float x2, float y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void show_scores(Player players[]) {
  printf("Scores:\n");
  for(int i = 0; i < N; i++) {
    printf("Player %d: %.2f\n", players[i].id, players[i].score);
  }
}

void play_round(Player players[]) {
  float center_x = 0, center_y = 0;
  for (int i = 0; i < N; i++) {
    center_x += players[i].x;
    center_y += players[i].y;
  }
  center_x /= N;
  center_y /= N;
  printf("Round starting! Center is at (%.2f, %.2f)\n", center_x, center_y);
  for (int i = 0; i < N; i++) {
    float dist = distance(center_x, center_y, players[i].x, players[i].y);
    printf("Player %d, enter the distance to the center: ", players[i].id);
    float answer;
    scanf("%f", &answer);
    if (fabs(dist - answer) <= 0.1) {
      players[i].score++;
      printf("Correct! Player %d gets 1 point!\n", players[i].id);
    } else {
      printf("Wrong! Player %d loses 1 point!\n", players[i].id);
      players[i].score--;
    }
  }
}

int main() {
  Player players[N];
  srand(time(NULL));

  // Initialize player positions randomly
  for (int i = 0; i < N; i++) {
    players[i].id = i+1;
    players[i].score = 0;
    players[i].x = rand() % 10 + 1;
    players[i].y = rand() % 10 + 1;
    printf("Player %d is at (%.2f, %.2f)\n", players[i].id, players[i].x, players[i].y);
  }

  for (int i = 0; i < M; i++) {
    printf("\n--- Round %d ---\n", i+1);
    play_round(players);
    show_scores(players);
  }

  printf("\n--- Final Scores ---\n");
  show_scores(players);

  return 0;
}