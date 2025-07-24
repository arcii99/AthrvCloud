//FormAI DATASET v1.0 Category: Error handling ; Style: careful
// Code to handle divide by zero error
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void div_zero_handler(int sig);

int main() {
  signal(SIGFPE, div_zero_handler); // Set the signal handler for SIGFPE
  
  int x = 10, y = 0, z;
  
  z = x / y; // Divide by zero error
  
  printf("Result: %d\n", z);
  
  return 0;
}

void div_zero_handler(int sig) {
  printf("Error: Divide by zero\n");
  exit(1);
}