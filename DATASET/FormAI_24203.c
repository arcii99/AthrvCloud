//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multiplayer
#include <stdio.h>

// This program is a multiplayer game where the objective is to find the distance between two given points on a cartesian plane.

struct Point {
   int x, y;
};

typedef struct Point point;

int main() {
  int num_players;
  printf("Enter the number of players: ");
  scanf("%d", &num_players);

  point player[num_players]; // Array of player points
  for (int i = 0; i < num_players; i++) {
     printf("Enter x and y coordinates for Player %d: ", i+1);
     scanf("%d %d", &player[i].x, &player[i].y);
  }

  int player1, player2;
  printf("Enter player numbers to find distance between: ");
  scanf("%d %d", &player1, &player2);

  // Calculating distance using distance formula
  float distance = sqrt(pow((player[player2-1].x - player[player1-1].x), 2) + pow((player[player2-1].y - player[player1-1].y), 2));

  printf("Distance between Player %d and Player %d: %.2f", player1, player2, distance);

  return 0;
}