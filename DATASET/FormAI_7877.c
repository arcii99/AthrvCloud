//FormAI DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_OPERATIONS 1000000

int main() {
  srand(time(NULL));

  int a = 0, b = 0, c = 0, d = 0, e = 0;
  bool add_a = true, add_b = true, add_c = true, add_d = true, add_e = true;
  int *values = malloc(sizeof(int) * MAX_OPERATIONS);
  int operations_count = 0;

  printf("Starting the asynchronous arithmetic operations!\n\n");

  for(int i = 0; i < MAX_OPERATIONS; i++) {
    int operation_type = rand() % 5;

    switch(operation_type) {
      case 0: // Addition
        if(add_a) {
          a++;
          values[i] = a;
          operations_count++;
        }

        if(add_b) {
          b++;
          values[i] = b;
          operations_count++;
        }

        if(add_c) {
          c++;
          values[i] = c;
          operations_count++;
        }

        if(add_d) {
          d++;
          values[i] = d;
          operations_count++;
        }

        if(add_e) {
          e++;
          values[i] = e;
          operations_count++;
        }
        break;

      case 1: // Subtraction
        if(a > 0) {
          a--;
          values[i] = a;
          operations_count++;
        }

        if(b > 0) {
          b--;
          values[i] = b;
          operations_count++;
        }

        if(c > 0) {
          c--;
          values[i] = c;
          operations_count++;
        }

        if(d > 0) {
          d--;
          values[i] = d;
          operations_count++;
        }

        if(e > 0) {
          e--;
          values[i] = e;
          operations_count++;
        }
        break;

      case 2: // Toggle variable
        int toggle_var = rand() % 5;

        switch(toggle_var) {
          case 0: add_a = !add_a; break;
          case 1: add_b = !add_b; break;
          case 2: add_c = !add_c; break;
          case 3: add_d = !add_d; break;
          case 4: add_e = !add_e; break;
        }

        values[i] = 0; // Mark as no change to variables
        operations_count++;
        break;

      case 3: // Set all variables to zero
        a = b = c = d = e = 0;
        values[i] = 0; // Mark as no change to variables
        operations_count++;
        break;

      case 4: // No operation
        values[i] = 0; // Mark as no change to variables
        operations_count++;
        break;
    }
  }

  printf("Asynchronous arithmetic operations completed with %d total operations!\n\n", operations_count);

  // Print out the final values of variables
  printf("Final values:\n");
  printf("a: %d\n", a);
  printf("b: %d\n", b);
  printf("c: %d\n", c);
  printf("d: %d\n", d);
  printf("e: %d\n\n", e);

  // Print out the values of the variables that were changed by each operation
  printf("Values changed by each operation:\n");

  for(int i = 0; i < MAX_OPERATIONS; i++) {
    if(values[i] != 0) {
      printf("Operation %d: ", i);

      if(values[i] == a) printf("a ");
      if(values[i] == b) printf("b ");
      if(values[i] == c) printf("c ");
      if(values[i] == d) printf("d ");
      if(values[i] == e) printf("e ");

      printf("\n");
    }
  }

  free(values);
  return 0;
}