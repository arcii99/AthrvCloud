//FormAI DATASET v1.0 Category: Syntax parsing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

char stack[STACK_SIZE];
int top = -1;

void push(char c) {
    if (top == STACK_SIZE - 1) {
        printf("Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

bool is_balanced(char* code) {
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '{' || code[i] == '[' || code[i] == '(') {
            push(code[i]);
        } else if (code[i] == '}' || code[i] == ']' || code[i] == ')') {
            char c = pop();
            if ((c == '{' && code[i] != '}') ||
                (c == '[' && code[i] != ']') ||
                (c == '(' && code[i] != ')')) {
                return false;
            }
        }
    }
    return top == -1;
}

int main() {
    char code[] = "int main() {\n"
                  "    int a = 5;\n"
                  "    if (a > 0) {\n"
                  "        printf(\"a is positive\");\n"
                  "    } else {\n"
                  "        printf(\"a is nonpositive\");\n"
                  "    }\n"
                  "    return 0;\n"
                  "}";
    if (is_balanced(code)) {
        printf("Code is balanced\n");
    } else {
        printf("Code is unbalanced\n");
    }
    return 0;
}