//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: genious
#include <stdio.h>
#include <math.h>

#define MAX_NODES 15
#define MAX_ELEMENTS 20
#define NODES 4 // number of nodes

typedef struct {
  double conductance;
  int node1;
  int node2;
} element;

int num_elements;
element circuit[MAX_ELEMENTS];
double node_voltage[MAX_NODES];

void new_element(double conductance, int node1, int node2) {
  circuit[num_elements].conductance = conductance;
  circuit[num_elements].node1 = node1;
  circuit[num_elements].node2 = node2;
  num_elements++;
}

void simulate_circuit() {
  int i, j, convergence_flag;
  double previous_voltage;

  do {
    convergence_flag = 1;

    for (i = 0; i < NODES; i++) {
      previous_voltage = node_voltage[i];
      node_voltage[i] = 0;

      for (j = 0; j < num_elements; j++) {
        if (circuit[j].node1 == i)
          node_voltage[i] += circuit[j].conductance * node_voltage[circuit[j].node2];
        else if (circuit[j].node2 == i)
          node_voltage[i] += circuit[j].conductance * node_voltage[circuit[j].node1];
      }

      if (fabs(node_voltage[i] - previous_voltage) > 0.0001)
        convergence_flag = 0;
    }
  } while (!convergence_flag);
}

int main() {
  new_element(0.2, 0, 1);
  new_element(0.1, 0, 2);
  new_element(0.3, 1, 2);

  simulate_circuit();

  printf("Node voltages:\n");
  printf("Node 1: %.3f\n", node_voltage[0]);
  printf("Node 2: %.3f\n", node_voltage[1]);
  printf("Node 3: %.3f\n", node_voltage[2]);

  return 0;
}