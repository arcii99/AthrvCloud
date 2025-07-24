//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define the gate types
enum GateType {
   AND,
   OR,
   NOT,
   XOR,
   NAND,
   NOR,
   XNOR
};

// Define the circuit gate structure
typedef struct CircuitGate {
   int input1;
   int input2;
   int output;
   enum GateType type;
} CircuitGate;

// Define the circuit structure
typedef struct Circuit {
   CircuitGate gates[50];
   int num_gates;
} Circuit;

// Define the circuit initialization function
void initialize_circuit(Circuit* circuit) {
   circuit->num_gates = 0;
}

// Define the gate creation function
void create_gate(int input1, int input2, int output, enum GateType type, Circuit* circuit) {
   CircuitGate gate;
   gate.input1 = input1;
   gate.input2 = input2;
   gate.output = output;
   gate.type = type;
   circuit->gates[circuit->num_gates] = gate;
   circuit->num_gates++;
}

// Define the gate evaluation function
int evaluate_gate(int input1, int input2, enum GateType type) {
   switch(type) {
      case AND:
         return input1 && input2;
      case OR:
         return input1 || input2;
      case NOT:
         return !input1;
      case XOR:
         return (input1 && !input2) || (!input1 && input2);
      case NAND:
         return !(input1 && input2);
      case NOR:
         return !(input1 || input2);
      case XNOR:
         return (input1 == input2) ? 1 : 0;
      default:
         printf("Invalid gate type\n");
         exit(1);
   }
}

// Define the circuit evaluation function
int evaluate_circuit(Circuit circuit, int input1, int input2) {
   int results[50];
   int i;
   for (i = 0; i < circuit.num_gates; i++) {
      CircuitGate gate = circuit.gates[i];
      int input1_value = (gate.input1 == -1) ? input1 : results[gate.input1];
      int input2_value = (gate.input2 == -1) ? input2 : results[gate.input2];
      int output_value = evaluate_gate(input1_value, input2_value, gate.type);
      results[gate.output] = output_value;
   }
   return results[circuit.gates[circuit.num_gates-1].output];
}

int main() {
   Circuit circuit;
   initialize_circuit(&circuit);
   create_gate(-1, -1, 0, AND, &circuit);
   create_gate(-1, -1, 1, OR, &circuit);
   create_gate(0, 1, 2, XOR, &circuit);
   printf("%d\n", evaluate_circuit(circuit, 0, 1));
   printf("%d\n", evaluate_circuit(circuit, 1, 1));
   return 0;
}