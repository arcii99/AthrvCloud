//FormAI DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Structure definition
typedef struct {
   int arr[MAX_SIZE];
   int top;
} Stack;

// Initializing the stack
void initializeStack(Stack *s) {
   s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
   return (s->top == -1);
}

// Check if the stack is full
int isFull(Stack *s) {
   return (s->top == MAX_SIZE - 1);
}

// Push an element to the stack
void push(Stack *s, int element) {
   if (isFull(s)) {
      printf("Stack Overflow\n");
      return;
   } else {
      s->top++;
      s->arr[s->top] = element;
   }
}

// Pop an element from the stack
int pop(Stack *s) {
   if (isEmpty(s)) {
      printf("Stack Underflow\n");
      return -1;
   } else {
      int element = s->arr[s->top];
      s->top--;
      return element;
   }
}

// Print stack elements
void printStack(Stack *s) {
   if (isEmpty(s)) {
      printf("Stack is empty");
   } else {
      printf("Stack elements: ");
      for (int i = 0; i <= s->top; i++) {
         printf("%d ", s->arr[i]);
      }
   }
   printf("\n");
}

// Main function
int main() {
   Stack s;

   // Initialize the stack
   initializeStack(&s);

   // Push some elements to stack
   push(&s, 10);
   push(&s, 20);
   push(&s, 30);
   push(&s, 40);
   push(&s, 50);

   // Print stack elements
   printStack(&s);

   // Pop an element
   int poppedElement = pop(&s);

   // Print popped element
   printf("Popped element: %d\n", poppedElement);

   // Print stack elements
   printStack(&s);

   return 0;
}