//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000

int main() {
  int resistors[SIZE]; // stores the resistance values
  int nodes[SIZE]; // stores the node numbers 
  float currents[SIZE]; // stores the current values

  int num_resistors, num_nodes;

  // prompt user for number of resistors and nodes
  printf("Please enter the number of resistors: ");
  scanf("%d", &num_resistors);
  printf("Please enter the number of nodes: ");
  scanf("%d", &num_nodes);

  // prompt user for resistance values and node numbers
  for (int i = 0; i < num_resistors; i++) {
    printf("Please enter the resistance value for resistor %d: ", i+1);
    scanf("%d", &resistors[i]);
  }

  for (int i = 0; i < num_nodes; i++) {
    printf("Please enter the node number for node %d: ", i+1);
    scanf("%d", &nodes[i]);
  }

  // calculate the currents through each resistor using Ohm's Law
  for (int i = 0; i < num_resistors; i++) {
    currents[i] = (float) nodes[i] / resistors[i];
  }

  // print the current values for each resistor
  printf("The current values for each resistor are:\n");
  for (int i = 0; i < num_resistors; i++) {
    printf("Resistor %d: %.2f A\n", i+1, currents[i]);
  }

  return 0;
}