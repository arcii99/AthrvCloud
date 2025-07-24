//FormAI DATASET v1.0 Category: Data structures visualization ; Style: energetic
// Energizing Data Structures Visualization Example in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10    // maximum stack size

// Structure for Stack
typedef struct {
   int data[MAX_SIZE];   // array to store stack elements
   int top;              // top of stack
} stack;

// Function to initialize stack
void init(stack *s) {
   s->top = -1;
}

// Function to check if stack is empty
int isempty(stack *s) {
   return s->top == -1;
}

// Function to check if stack is full
int isfull(stack *s) {
   return s->top == MAX_SIZE - 1;
}

// Function to push an element onto stack
int push(stack *s, int x) {
   if (isfull(s)) {
      printf("Stack Overflow!\n");
      return 0;
   } else {
      s->data[++(s->top)] = x;
      return 1;
   }
}

// Function to pop an element from stack
int pop(stack *s) {
   if (isempty(s)) {
      printf("Stack Underflow!\n");
      return 0;
   } else {
      return s->data[(s->top)--];
   }
}

int main() {
   // Display Welcome Message
   printf("\nWelcome to our Energizing Data Structures Visualization Example!\n\n"); 

   // Initialize Stack
   stack s;
   init(&s);

   // Generate some Random Numbers and Push Them onto Stack
   srand(time(NULL));
   int i;
   for (i = 0; i < MAX_SIZE; i++) {
      push(&s, rand()%100);
   }

   // Display the Stack
   printf("\nStack Elements:\n");
   for (i = s.top; i >= 0; i--) {
      printf("%d\n", s.data[i]);
   }

   // Pop Some Elements from Stack
   printf("\nPOP some Elements from Stack:\n");
   printf("%d\n", pop(&s));
   printf("%d\n", pop(&s));
   printf("%d\n", pop(&s));

   // Display the Stack after Popping
   printf("\nStack Elements after Popping:\n");
   for (i = s.top; i >= 0; i--) {
      printf("%d\n", s.data[i]);
   }

   // Display Farewell Message
   printf("\nThank you for using our Energizing Data Structures Visualization Example!\n\n");

   return 0;  
}