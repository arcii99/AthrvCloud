//FormAI DATASET v1.0 Category: Data structures visualization ; Style: expert-level
#define MAX_SIZE 1000

typedef struct Stack {
    int arr[MAX_SIZE];
    int top;
} Stack;

void push(Stack* s, int val) {
    if(s->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    s->arr[++s->top] = val;
}

int pop(Stack* s) {
    if(s->top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->arr[s->top--];
}

void display(Stack* s) {
    if(s->top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Current Stack:\n");
    for(int i = s->top; i >= 0; i--) {
        printf("%d\n", s->arr[i]);
    }
}

int main() {
    Stack stk = {.top = -1};
    push(&stk, 10);
    push(&stk, 20);
    push(&stk, 30);
    printf("Element popped: %d\n", pop(&stk));
    display(&stk);
    return 0;
}