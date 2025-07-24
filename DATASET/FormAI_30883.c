//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

/* Medieval-inspired Circuit Simulator */

/* Constants */
#define MAX_CIRCUITS 10
#define MAX_NODES 20
#define MAX_RESISTORS 30

/* Structures */
typedef struct {
  int nodeA;
  int nodeB;
  double value;
} Resistor;

typedef struct {
  int numNodes;
  Resistor resistors[MAX_RESISTORS];
} Circuit;

/* Functions */
void addResistor(Circuit *circuit, int nodeA, int nodeB, double value);
double calculateResistance(Circuit *circuit, int startNode, int endNode);

/* Main Program */
int main(void) {
  int numCircuits = 0;
  Circuit circuits[MAX_CIRCUITS];

  /* Create Circuit 1 */
  circuits[numCircuits].numNodes = 2;
  addResistor(&circuits[numCircuits], 1, 2, 45.0);
  addResistor(&circuits[numCircuits], 2, 3, 55.0);
  addResistor(&circuits[numCircuits], 3, 1, 30.0);
  double resistance1 = calculateResistance(&circuits[numCircuits], 1, 3);
  printf("Resistance of Circuit 1: %.2lf Ohms\n", resistance1);
  numCircuits++;

  /* Create Circuit 2 */
  circuits[numCircuits].numNodes = 3;
  addResistor(&circuits[numCircuits], 1, 2, 25.0);
  addResistor(&circuits[numCircuits], 2, 3, 35.0);
  addResistor(&circuits[numCircuits], 3, 1, 50.0);
  double resistance2 = calculateResistance(&circuits[numCircuits], 1, 3);
  printf("Resistance of Circuit 2: %.2lf Ohms\n", resistance2);
  numCircuits++;

  return EXIT_SUCCESS;
}

void addResistor(Circuit *circuit, int nodeA, int nodeB, double value) {
  /* Check for valid node numbers */
  if (nodeA < 1 || nodeA > circuit->numNodes || nodeB < 1 || nodeB > circuit->numNodes) {
    printf("Invalid node numbers for resistor\n");
    exit(EXIT_FAILURE);
  }

  /* Add resistor to circuit */
  Resistor newResistor = {nodeA, nodeB, value};
  circuit->resistors[0] = newResistor;
}

double calculateResistance(Circuit *circuit, int startNode, int endNode) {
  /* Check for valid node numbers */
  if (startNode < 1 || startNode > circuit->numNodes || endNode < 1 || endNode > circuit->numNodes) {
    printf("Invalid node numbers for resistance calculation\n");
    exit(EXIT_FAILURE);
  }

  /* Loop through all resistors and calculate total resistance */
  double totalResistance = 0.0;
  for (int i = 0; i < MAX_RESISTORS; i++) {
    if (circuit->resistors[i].value == 0.0) {
      break;
    }
    if (circuit->resistors[i].nodeA == startNode || circuit->resistors[i].nodeB == startNode) {
      int nextNode = (circuit->resistors[i].nodeA == startNode) ? circuit->resistors[i].nodeB : circuit->resistors[i].nodeA;
      if (nextNode == endNode) {
        totalResistance += circuit->resistors[i].value;
        break;
      } else {
        double subResistance = calculateResistance(circuit, nextNode, endNode);
        double parallelResistance = (circuit->resistors[i].value * subResistance) / (circuit->resistors[i].value + subResistance);
        totalResistance += parallelResistance;
      }
    }
  }
  return totalResistance;
}