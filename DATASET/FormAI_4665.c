//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: creative
#include <stdio.h>

// Function to simulate a classical circuit
void classicalCircuitSimulator(int inputA, int inputB, int *output) {
  // Set the output to be the XOR of the inputs
  *output = inputA ^ inputB;
}

int main() {
  int inputA, inputB, output;
  
  // Prompt the user for inputs
  printf("Enter input A: ");
  scanf("%d", &inputA);
  printf("\nEnter input B: ");
  scanf("%d", &inputB);
  
  // Call the simulator function
  classicalCircuitSimulator(inputA, inputB, &output);
  
  // Output the result
  printf("\nOutput: %d\n", output);
  
  return 0;
}