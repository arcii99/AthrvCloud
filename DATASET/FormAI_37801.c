//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NODES 10
#define SOURCES 5
#define RESISTORS 7

double A[NODES+1][NODES+2];
double X[NODES+1];
double error = 0.001;
int max_iter = 100;

void initialize_matrix() {
  int i, j;
  for(i = 1; i <= NODES; i++) {
    for(j = 1; j <= NODES+1; j++) {
      A[i][j] = 0;
    }
  }
  A[1][1] = 1;
}

void set_resistors(double resistors[]) {
  A[1][2] = resistors[0] + resistors[1];
  A[1][3] = -resistors[1];
  A[2][2] = resistors[1];
  A[2][4] = -resistors[2];
  A[3][2] = -resistors[1];
  A[3][3] = resistors[1] + resistors[3] + resistors[4];
  A[3][4] = -resistors[4];
  A[4][3] = -resistors[4];
  A[4][5] = -resistors[5];
  A[4][6] = resistors[5];
  A[5][4] = -resistors[5];
  A[5][6] = resistors[5] + resistors[6];
  A[5][7] = -resistors[6];
  A[6][6] = resistors[6];
  A[7][7] = resistors[6] + resistors[7];
  A[7][8] = -resistors[7];
  A[8][9] = -1;
  A[9][7] = -resistors[7];
  A[9][9] = 1;
  A[9][10] = 1;
}

void set_sources(double sources[]) {
  A[4][NODES+1] = sources[0];
  A[5][NODES+1] = sources[1];
  A[6][NODES+1] = sources[2];
  A[7][NODES+1] = -sources[2];
  A[8][NODES+1] = sources[3];
}

void print_matrix() {
  int i, j;
  printf("Matrix of coefficients and constants:\n");
  for(i = 1; i <= NODES; i++) {
    for(j = 1; j <= NODES+1; j++) {
      printf("%.2f ", A[i][j]);
    }
    printf("\n");
  }
}

int jacobi_method() {
  int iter = 0, i, j;
  double X_old[NODES+1];
  while(iter < max_iter) {
    for(i = 1; i <= NODES; i++) {
      X_old[i] = X[i];
      double sum = 0;
      for(j = 1; j <= NODES+1; j++) {
        if(j != i)
          sum += A[i][j]*X_old[j];
      }
      X[i] = (A[i][NODES+1]-sum)/A[i][i];
    }
    double max_err = 0;
    for(i = 1; i <= NODES; i++) {
      double curr_err = fabs(X[i]-X_old[i])/X[i];
      if(curr_err > max_err)
        max_err = curr_err;
    }
    if(max_err < error)
      return iter;
    iter++;
  }
  return -1;
}

int main() {
  double resistors[RESISTORS] = {100, 100, 150, 50, 150, 200, 100};
  double sources[SOURCES] = {5, 10, 15, 20, 30};
  initialize_matrix();
  set_resistors(resistors);
  set_sources(sources);
  print_matrix();
  int iter = jacobi_method();
  if(iter == -1)
    printf("Divergence occurred\n");
  else
    printf("Convergence achieved after %d iterations\n", iter+1);
  printf("Node voltages:\n");
  int i;
  for(i = 1; i <= NODES; i++) {
    printf("V%d = %.2f\n", i, X[i]);
  }
  return 0;
}