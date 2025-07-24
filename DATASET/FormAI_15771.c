//FormAI DATASET v1.0 Category: Data structures visualization ; Style: retro
#include <stdio.h>

/* Custom C Data Structure */
#define MAX_ELEMENTS 10
typedef struct {
  int elements[MAX_ELEMENTS];
  int top; // Top element index, -1 means empty stack
} Stack;

void push(Stack* stack, int element) {
  if (stack->top < MAX_ELEMENTS - 1) {
    stack->top++;
    stack->elements[stack->top] = element;
  }
}

int pop(Stack* stack) {
  if (stack->top >= 0) {
    int element = stack->elements[stack->top];
    stack->top--;
    return element;
  }
  return -1; // Error, empty stack
}

void drawStack(Stack* stack) {
  printf("+=======+\n");
  int i;
  for (i = MAX_ELEMENTS - 1; i >= 0; i--) {
    printf("|%3d   |\n", stack->elements[i]);
    if (i == stack->top) {
      printf("+=======+\n");
    } else {
      printf("|       |\n");
    }
  }
  printf("+=======+\n");
}

int main() {
  Stack stack = { {0}, -1 }; // Create empty stack
  push(&stack, 7);
  push(&stack, 21);
  push(&stack, 9);

  drawStack(&stack); // Output stack
  printf("Popped %d from top of stack.\n", pop(&stack));
  drawStack(&stack);
  printf("Popped %d from top of stack.\n", pop(&stack));
  drawStack(&stack);
  return 0;
}