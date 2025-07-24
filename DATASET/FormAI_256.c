//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10000

typedef struct {
  int type;
  int node[3];
  float value;
} element;

int num_elements = 0;
element elements[MAX_NODES];

void add_resistor(int node1, int node2, float resistance) {
  elements[num_elements].type = 0;
  elements[num_elements].node[0] = node1;
  elements[num_elements].node[1] = node2;
  elements[num_elements].value = resistance;
  num_elements++;
}

void add_capacitor(int node1, int node2, float capacitance) {
  elements[num_elements].type = 1;
  elements[num_elements].node[0] = node1;
  elements[num_elements].node[1] = node2;
  elements[num_elements].value = capacitance;
  num_elements++;
}

void add_inductor(int node1, int node2, float inductance) {
  elements[num_elements].type = 2;
  elements[num_elements].node[0] = node1;
  elements[num_elements].node[1] = node2;
  elements[num_elements].value = inductance;
  num_elements++;
}

void add_voltage_source(int node1, int node2, float voltage) {
  elements[num_elements].type = 3;
  elements[num_elements].node[0] = node1;
  elements[num_elements].node[1] = node2;
  elements[num_elements].value = voltage;
  num_elements++;
}

void add_current_source(int node1, int node2, float current) {
  elements[num_elements].type = 4;
  elements[num_elements].node[0] = node1;
  elements[num_elements].node[1] = node2;
  elements[num_elements].value = current;
  num_elements++;
}

int main() {
  add_resistor(1,2,5000);
  add_capacitor(2,3,0.0001);
  add_voltage_source(1,3,10);

  printf("Number of nodes: %d\n", 3);
  printf("Number of elements: %d\n", num_elements);
  printf("Elements:\n");

  for (int i = 0; i < num_elements; i++) {
    printf("%d %d %d %f\n",
           elements[i].type,
           elements[i].node[0],
           elements[i].node[1],
           elements[i].value);
  }
  
  return 0;
}