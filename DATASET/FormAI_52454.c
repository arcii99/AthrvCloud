//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Component {
  char type;
  int node1;
  int node2;
  float value;
} Component;

typedef struct Node {
  float voltage;
  int is_ground;
} Node;

float get_resistor_current(Component* resistor, Node* nodes) {
  int node1 = resistor->node1;
  int node2 = resistor->node2;

  float voltage1 = nodes[node1].voltage;
  float voltage2 = nodes[node2].voltage;
  float resistance = resistor->value;

  return (voltage1 - voltage2) / resistance;
}

float get_capacitor_current(Component* capacitor, Node* nodes, float time_step) {
  int node1 = capacitor->node1;
  int node2 = capacitor->node2;

  float voltage1 = nodes[node1].voltage;
  float voltage2 = nodes[node2].voltage;
  float capacitance = capacitor->value;

  float current = capacitance * (voltage1 - voltage2) / time_step;

  return current;
}

void update_nodes(Component* components, int num_components, Node* nodes, float time_step) {
  for (int i = 0; i < num_components; i++) {
    Component component = components[i];
    if (component.type == 'R') {
      float current = get_resistor_current(&component, nodes);
      nodes[component.node1].voltage -= current * time_step;
      nodes[component.node2].voltage += current * time_step;
    } else if (component.type == 'C') {
      float current = get_capacitor_current(&component, nodes, time_step);
      nodes[component.node1].voltage -= current * time_step;
      nodes[component.node2].voltage += current * time_step;
    }
  }
}

void print_nodes(Node* nodes, int num_nodes) {
  for (int i = 1; i < num_nodes; i++) {
    printf("Node %d voltage: %f\n", i, nodes[i].voltage);
  }
  printf("\n");
}

int main() {
  Component components[] = {
    {.type = 'R', .node1 = 1, .node2 = 2, .value = 100},
    {.type = 'C', .node1 = 2, .node2 = 0, .value = 1e-6}
  };

  int num_components = sizeof(components) / sizeof(components[0]);
  int num_nodes = 3;
  Node nodes[num_nodes];

  nodes[0].voltage = 0;
  nodes[0].is_ground = 1;
  nodes[1].voltage = 5;
  nodes[1].is_ground = 0;
  nodes[2].voltage = 0;
  nodes[2].is_ground = 0;

  float time_step = 1e-6;
  float total_time = 10 * time_step;

  for (float t = 0; t < total_time; t += time_step) {
    update_nodes(components, num_components, nodes, time_step);
  }

  print_nodes(nodes, num_nodes);

  return 0;
}