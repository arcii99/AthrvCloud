//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define N 4 /* number of nodes */
#define M 5 /* number of elements */

/* data structure to represent circuit elements */
struct element {
  int type;
  int node1;
  int node2;
  float value;
};

/* function to solve the circuit */
void solve_circuit(struct element elements[M], float solution[N]) {
  int i, j, k, l, row;
  float matrix[N][N+1], factor, sum;

  /* initialize matrix */
  for (i = 0; i < N; i++) {
    for (j = 0; j < N+1; j++) {
      matrix[i][j] = 0;
    }
  }

  /* populate matrix */
  for (i = 0; i < M; i++) {
    if (elements[i].type == 1) { /* resistance */
      factor = 1 / elements[i].value;
      matrix[elements[i].node1-1][elements[i].node1-1] += factor;
      matrix[elements[i].node2-1][elements[i].node2-1] += factor;
      matrix[elements[i].node1-1][elements[i].node2-1] -= factor;
      matrix[elements[i].node2-1][elements[i].node1-1] -= factor;
    } else if (elements[i].type == 2) { /* current source */
      matrix[elements[i].node1-1][N] += elements[i].value;
      matrix[elements[i].node2-1][N] -= elements[i].value;
    } else if (elements[i].type == 3) { /* voltage source */
      matrix[N-1][elements[i].node1-1] += 1;
      matrix[N-1][elements[i].node2-1] -= 1;
      matrix[elements[i].node1-1][N-1] += 1;
      matrix[elements[i].node2-1][N-1] -= 1;
      matrix[elements[i].node1-1][elements[i].node1-1] += elements[i].value;
      matrix[elements[i].node2-1][elements[i].node2-1] += elements[i].value;
      matrix[elements[i].node1-1][elements[i].node2-1] -= elements[i].value;
      matrix[elements[i].node2-1][elements[i].node1-1] -= elements[i].value;
    }
  }

  /* solve matrix */
  for (i = 0; i < N-1; i++) {
    row = i;
    for (j = i+1; j < N-1; j++) {
      if (matrix[j][i] > matrix[row][i]) {
        row = j;
      }
    }
    if (row != i) {
      for (j = 0; j < N+1; j++) {
        factor = matrix[i][j];
        matrix[i][j] = matrix[row][j];
        matrix[row][j] = factor;
      }
    }
    factor = matrix[i][i];
    for (j = 0; j < N+1; j++) {
      matrix[i][j] /= factor;
    }
    for (j = i+1; j < N-1; j++) {
      factor = matrix[j][i];
      for (k = 0; k < N+1; k++) {
        matrix[j][k] -= factor * matrix[i][k];
      }
    }
  }
  solution[N-1] = matrix[N-1][N] / matrix[N-1][N-1];
  for (i = N-2; i >= 0; i--) {
    sum = 0;
    for (j = i+1; j < N-1; j++) {
      sum += matrix[i][j] * solution[j];
    }
    solution[i] = (matrix[i][N] - sum) / matrix[i][i];
  }

  /* print solution */
  for (i = 0; i < N-1; i++) {
    printf("Node %d: %.2f V\n", i+1, solution[i]);
  }
  printf("Current through voltage source: %.2f A\n", solution[N-1]);
}

/* example circuit */
int main() {
  struct element elements[M] = {
    {1, 1, 2, 50},
    {1, 2, 3, 100},
    {1, 2, 4, 200},
    {2, 1, 3, 2},
    {3, 3, 4, 150}
  };
  float solution[N];
  solve_circuit(elements, solution);
  return 0;
}