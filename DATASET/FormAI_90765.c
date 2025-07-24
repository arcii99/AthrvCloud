//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define maximum nodes in the circuit
#define MAX_NODES 100

// Define maximum number of resistors in the circuit
#define MAX_RESISTORS 50

// Define maximum number of independent voltage sources in the circuit
#define MAX_V_SOURCES 10

int main()
{
  // Input variables
  int i, j, n_nodes, n_resistors, n_v_sources;
  double resistance[MAX_RESISTORS], voltage[MAX_V_SOURCES];

  // Initialize arrays to zero
  for (i = 0; i < MAX_RESISTORS; i++)
    resistance[i] = 0.0;
  for (i = 0; i < MAX_V_SOURCES; i++)
    voltage[i] = 0.0;

  // Get number of nodes in the circuit
  printf("Enter the number of nodes in the circuit: ");
  scanf("%d", &n_nodes);

  // Get number of resistors in the circuit
  printf("Enter the number of resistors in the circuit: ");
  scanf("%d", &n_resistors);

  // Get resistance values for each resistor
  for (i = 0; i < n_resistors; i++)
  {
    printf("Enter resistance value for resistor %d: ", i+1);
    scanf("%lf", &resistance[i]);
  }

  // Get number of independent voltage sources in the circuit
  printf("Enter the number of independent voltage sources in the circuit: ");
  scanf("%d", &n_v_sources);

  // Get voltage values for each voltage source
  for (i = 0; i < n_v_sources; i++)
  {
    printf("Enter voltage value for voltage source %d: ", i+1);
    scanf("%lf", &voltage[i]);
  }

  // Allocate memory for the conductance matrix
  double **G = (double **)malloc((n_nodes+1) * sizeof(double *));
  for (i = 0; i <= n_nodes; i++)
    G[i] = (double *)malloc((n_nodes+1) * sizeof(double));

  // Initialize conductance matrix to zero
  for (i = 0; i <= n_nodes; i++)
    for (j = 0; j <= n_nodes; j++)
      G[i][j] = 0.0;

  // Fill conductance matrix with resistance values
  for (i = 0; i < n_resistors; i++)
  {
    int node1, node2;
    printf("Enter node numbers for resistor %d: ", i+1);
    scanf("%d %d", &node1, &node2);
    G[node1][node1] += 1.0 / resistance[i];
    G[node2][node2] += 1.0 / resistance[i];
    G[node1][node2] -= 1.0 / resistance[i];
    G[node2][node1] -= 1.0 / resistance[i];
  }

  // Fill conductance matrix with voltage source values
  for (i = 0; i < n_v_sources; i++)
  {
    int node1, node2;
    printf("Enter node numbers for voltage source %d: ", i+1);
    scanf("%d %d", &node1, &node2);
    G[node1][n_nodes+1] += 1.0;
    G[node2][n_nodes+1] -= 1.0;
    G[n_nodes+1][node1] += 1.0;
    G[n_nodes+1][node2] -= 1.0;
  }

  // Allocate memory for the result vector
  double *V = (double *)malloc((n_nodes+1) * sizeof(double));

  // Initialize result vector to zero
  for (i = 0; i <= n_nodes; i++)
    V[i] = 0.0;

  // Fill result vector with voltage source values
  for (i = 0; i < n_v_sources; i++)
  {
    int node1, node2;
    printf("Enter node numbers for voltage source %d: ", i+1);
    scanf("%d %d", &node1, &node2);
    V[node1] = voltage[i];
    V[node2] = -voltage[i];
  }

  // Solve the system of linear equations
  for (i = 1; i <= n_nodes; i++)
  {
    for (j = i+1; j <= n_nodes; j++)
    {
      double ratio = G[j][i] / G[i][i];
      for (int k = i; k <= n_nodes+1; k++)
        G[j][k] -= ratio * G[i][k];
    }
  }

  for (i = n_nodes; i >= 1; i--)
  {
    double sum = G[i][n_nodes+1];
    for (j = i+1; j <= n_nodes; j++)
      sum -= G[i][j] * V[j];
    V[i] = sum / G[i][i];
  }

  // Output results
  printf("Node voltages:\n");
  for (i = 1; i <= n_nodes; i++)
    printf("Node %d: %f\n", i, V[i]);

  // Free memory
  free(V);
  for (i = 0; i <= n_nodes; i++)
    free(G[i]);
  free(G);

  return 0;
}