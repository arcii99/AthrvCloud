//FormAI DATASET v1.0 Category: Data structures visualization ; Style: energetic
/* Welcome to the Energizing Data Structures Visualization Program! */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

/* Define our example data structure: a simple Stack */
typedef struct Stack {
    int items[SIZE];
    int top;
} Stack;

/* Define function prototypes */
void push(Stack *s, int value);
int pop(Stack *s);
void display(Stack *s);

/* Our main function */
int main() {
    /* Initialize our empty stack */
    Stack s;
    s.top = -1;

    /* Energize the program! */
    printf("******************************\n");
    printf("** Energizing Data Structures **\n");
    printf("**  Visualization Program!   **\n");
    printf("******************************\n\n");

    /* Demonstrate pushing and popping elements */
    push(&s, 5);
    push(&s, 10);
    push(&s, 15);
    printf("The top element is %d\n", s.items[s.top]);
    display(&s);
    pop(&s);
    printf("The top element is %d\n", s.items[s.top]);
    display(&s);

    /* Generate a random stack and display it */
    Stack randStack;
    randStack.top = -1;
    for (int i = 0; i < SIZE; i++) {
        push(&randStack, rand() % 100);
    }
    printf("Here is a randomly generated stack:\n");
    display(&randStack);
    printf("The top element is %d\n", randStack.items[randStack.top]);

    /* Energize the user! */
    printf("\n\n******************************\n");
    printf("**   Thank you for using the  **\n");
    printf("** Energizing Data Structures **\n");
    printf("**  Visualization Program!   **\n");
    printf("******************************\n");

    return 0;
}

/* Function definitions */
void push(Stack *s, int value) {
    if (s->top == SIZE-1) {
        printf("Stack is full!\n");
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(Stack *s) {
    int value;
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        value = s->items[s->top];
        s->top--;
        return value;
    }
}

void display(Stack *s) {
    printf("Stack elements:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->items[i]);
    }
}