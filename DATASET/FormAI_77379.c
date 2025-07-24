//FormAI DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include<stdio.h>
#define MAX_SIZE 100

//Declaration of Stack Data Structure;
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

//Function to push an element on the top of stack
void push(Stack *s, int item){
    if(s->top == MAX_SIZE - 1){
        printf("\nStack overflow. Could not push element");
    } else {
        s->top++;
        s->data[s->top] = item;
    }
}

//Function to pop an element from the top of stack
int pop(Stack *s){
    if(s->top == -1){
        printf("\nStack underflow");
        return -1;
    } else{
        int item = s->data[s->top];
        s->top--;
        return item;
    }
}


//Function to display all elements in the stack
void display(Stack s){
    if(s.top == -1){
        printf("\nStack is empty. Nothing to display");
    } else {
        int i;
        printf("\nStack elements: ");
        for(i=s.top; i>=0; i--){
            printf("%d ", s.data[i]);
        }
    }
}

int main(){
    Stack s;
    s.top = -1;

    //Pushing elements on the stack
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    //Displaying the current stack elements
    display(s);

    //Popping top element from the stack
    int item = pop(&s);
    printf("\n\nPopped item is %d", item);

    //Displaying the elements in the stack after pop operation
    display(s);

    return 0;
}