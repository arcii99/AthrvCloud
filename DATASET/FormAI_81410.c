//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>

#define MAX_NODES 10
#define MAX_VAL 1000

int numNodes = 0;
int nodeMap[MAX_NODES][2] = {0};
int nodeCount[MAX_NODES] = {0};
float capacitance[MAX_NODES][MAX_NODES] = {{0}};
float resistance[MAX_NODES][MAX_NODES] = {{0}};
float voltage[MAX_NODES] = {0};
float current[MAX_NODES] = {0};
float charge[MAX_NODES] = {0};

int addNode(int x, int y) {
  for (int i = 0; i < numNodes; i++) {
    if (nodeMap[i][0] == x && nodeMap[i][1] == y) {
      nodeCount[i]++;
      return i;
    }
  }
  nodeMap[numNodes][0] = x;
  nodeMap[numNodes][1] = y;
  nodeCount[numNodes]++;
  return numNodes++;
}

void addComponent(int x1, int y1, int x2, int y2, float value, char* type) {
  int node1 = addNode(x1, y1);
  int node2 = addNode(x2, y2);
  if (type == "resistor") {
    resistance[node1][node2] += value;
  } else if (type == "capacitor") {
    capacitance[node1][node2] += value;
  }
}

void addVoltageSource(int x1, int y1, int x2, int y2, float value) {
  int node1 = addNode(x1, y1);
  int node2 = addNode(x2, y2);
  voltage[node1] += value;
  voltage[node2] -= value;
}

void simulate(float timestep, float duration) {
  float time = 0;
  while (time < duration) {
    float admittance[MAX_NODES][MAX_NODES] = {{0}};
    for (int i = 0; i < numNodes; i++) {
      for (int j = 0; j < numNodes; j++) {
        if (i == j) {
          for (int k = 0; k < numNodes; k++) {
            admittance[i][j] += capacitance[i][k] / timestep;
          }
        } else {
          admittance[i][j] -= capacitance[i][j] / timestep;
        }
        admittance[i][j] += resistance[i][j];
      }
    }
    for (int i = 0; i < numNodes; i++) {
      admittance[numNodes-1][i] += nodeCount[i];
    }
    admittance[numNodes-1][numNodes-1] = 0;
    for (int i = 0; i < numNodes-1; i++) {
      current[i] = 0;
      for (int j = 0; j < numNodes; j++) {
        current[i] += admittance[i][j] * voltage[j];
      }
    }
    for (int i = 0; i < numNodes; i++) {
      charge[i] += current[i] * timestep;
      voltage[i] += current[i] / nodeCount[i];
    }
    printf("Time: %f\n", time);
    for (int i = 0; i < numNodes; i++) {
      printf("Node %d: Voltage: %f Current: %f Charge: %f\n", i, voltage[i], current[i], charge[i]);
    }
    printf("\n");
    time += timestep;
  }
}

int main() {
  addComponent(0, 0, 0, 1, 100, "resistor");
  addComponent(0, 1, 1, 1, 50, "capacitor");
  addVoltageSource(0, 0, 1, 1, 10);
  simulate(0.0001, 0.1);
  return 0;
}