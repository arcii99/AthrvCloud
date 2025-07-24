//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define INPUT_SIZE 2
#define OUTPUT_SIZE 1

typedef enum {
  AND,
  OR,
  NOT,
  XOR
} GateType;

typedef struct {
  GateType type;
  int input1;
  int input2;
  int output;
} Gate;

int run_gate(Gate gate, int* input) {
  switch(gate.type) {
    case AND:
      return input[gate.input1] && input[gate.input2];
    case OR:
      return input[gate.input1] || input[gate.input2];
    case NOT:
      return !input[gate.input1];
    case XOR:
      return input[gate.input1] ^ input[gate.input2];
    default:
      printf("Unknown gate type");
      return 0;
  }
}

int run_circuit(Gate* gates, int num_gates, int* input, int* output) {
  int i, j;
  int* state = (int*) malloc(sizeof(int) * (num_gates - INPUT_SIZE - OUTPUT_SIZE));
  for (i = 0; i < num_gates - INPUT_SIZE - OUTPUT_SIZE; i++) {
    state[i] = 0;
  }
  
  for (i = 0; i < num_gates; i++) {
    if (i < INPUT_SIZE) {
      state[i] = input[i];
    } else if (i >= INPUT_SIZE && i < num_gates - OUTPUT_SIZE) {
      int inputs[2];
      inputs[0] = state[gates[i].input1 - INPUT_SIZE];
      inputs[1] = state[gates[i].input2 - INPUT_SIZE];
      state[i - INPUT_SIZE] = run_gate(gates[i], inputs);
    } else {
      output[0] = state[gates[i].input1 - INPUT_SIZE];
    }
  }

  free(state);
  return 0;
}

int main() {
  int input[INPUT_SIZE] = { 1, 0 }; // set the input values
  int output[OUTPUT_SIZE] = { 0 }; // init the output values
  
  // create the gates
  Gate gates[] = {
    { AND, 0, 1, 2 },
    { OR, 1, 2, 3 },
    { NOT, 3, -1, 4 },
    { XOR, 2, 3, 5 },
    { XOR, 0, 5, 6 },
  };
  
  int num_gates = sizeof(gates)/sizeof(gates[0]);
  
  // run the circuit!
  run_circuit(gates, num_gates, input, output);
  
  // print the output
  printf("Output: %d", output[0]);
  
  return 0;
}