//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: intelligent
#include <stdio.h>

#define SIZE 10

int x = 1, y = 1; // Pac-Man starting position
int score = 0;
int lives = 3;
char maze[SIZE][SIZE] = {
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
  {'#', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
  {'#', '.', '#', '.', '#', '.', '.', '.', '.', '#'},
  {'#', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
  {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
  {'#', '#', '.', '#', '#', '.', '#', '#', '.', '#'},
  {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
  {'#', '.', '#', '#', '#', '.', '#', '.', '.', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

void displayMaze() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (i == x && j == y) printf("C");
      else printf("%c", maze[i][j]);
    }
    printf("\n");
  }
  printf("Score: %d\nLives: %d\n", score, lives);
}

void move(char direction) {
  int newX = x, newY = y;
  switch (direction) {
    case 'u':
      newX--;
      break;
    case 'd':
      newX++;
      break;
    case 'l':
      newY--;
      break;
    case 'r':
      newY++;
      break;
  }
  if (maze[newX][newY] != '#') {
    x = newX;
    y = newY;
    if (maze[x][y] == '.') {
      score++;
      maze[x][y] = ' ';
    }
  } else {
    lives--;
  }
}

int main() {
  while (lives > 0) {
    displayMaze();
    char input;
    printf("Enter direction to move (u/d/l/r): ");
    scanf("%c", &input);
    move(input);
    system("cls"); // clear screen
  }
  printf("Game over! Final score: %d\n", score);
  return 0;
}