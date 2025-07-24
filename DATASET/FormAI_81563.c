//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define OPEN 1
#define BLOCKED 0

int grid[N][N];
int connected[N*N];
int num_connected = 0;

void display_grid() {
  for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
      if (grid[row][col] == OPEN) {
        printf("O ");
      } else {
        printf("X ");
      }
    }
    printf("\n");
  }
}

int check_connection(int node1, int node2) {
  return connected[node1] == connected[node2];
}

void union_nodes(int node1, int node2) {
  int temp = connected[node1];
  for (int i = 0; i < N*N; i++) {
    if (connected[i] == temp) {
      connected[i] = connected[node2];
    }
  }
}

int open_node(int row, int col) {
  if (grid[row][col] == BLOCKED) {
    grid[row][col] = OPEN;
    if (row > 0 && grid[row-1][col] == OPEN) {
      if (!check_connection(row*N+col, (row-1)*N+col)) {
        union_nodes(row*N+col, (row-1)*N+col);
        num_connected--;
      }
    }
    if (row < N-1 && grid[row+1][col] == OPEN) {
      if (!check_connection(row*N+col, (row+1)*N+col)) {
        union_nodes(row*N+col, (row+1)*N+col);
        num_connected--;
      }
    }
    if (col > 0 && grid[row][col-1] == OPEN) {
      if (!check_connection(row*N+col, row*N+col-1)) {
        union_nodes(row*N+col, row*N+col-1);
        num_connected--;
      }
    }
    if (col < N-1 && grid[row][col+1] == OPEN) {
      if (!check_connection(row*N+col, row*N+col+1)) {
        union_nodes(row*N+col, row*N+col+1);
        num_connected--;
      }
    }
    return 1;
  } else {
    return 0;
  }
}

void percolate() {
  srand(time(NULL));
  for (int i = 0; i < N*N; i++) {
    connected[i] = i;
  }
  num_connected = N*N;
  while (num_connected > N) {
    int row = rand() % N;
    int col = rand() % N;
    open_node(row, col);
  }
}

int main() {
  percolate();
  display_grid();
  printf("\n");
  if (connected[0] == connected[N*N-1]) {
    printf("Woohoo! The system percolates!\n");
  } else {
    printf("Sorry, the system did not percolate. Better luck next time!\n");
  }
  return 0;
}