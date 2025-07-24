//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: innovative
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define PI 3.14159265358979323846

// Global stack variables
double stack[MAX_STACK_SIZE];
int top = -1;

// Stack functions
void push(double x) {
    if (top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    else {
        stack[++top] = x;
    }
}

double pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    else {
        return stack[top--];
    }
}

// Scientific Calculator functions
double sin_func(double x) {
    return sin(x * PI / 180);
}

double cos_func(double x) {
    return cos(x * PI / 180);
}

double tan_func(double x) {
    return tan(x * PI / 180);
}

double log_func(double x) {
    return log10(x);
}

double ln_func(double x) {
    return log(x);
}

double exp_func(double x) {
    return exp(x);
}

double sqrt_func(double x) {
    return sqrt(x);
}

double pow_func(double x, double y) {
    return pow(x, y);
}

// Main function
int main() {
    char input[MAX_STACK_SIZE];
    double num, x, y;

    printf("Welcome to the Scientific Calculator!\n");
    printf("Valid operators: +, -, *, /, sin(), cos(), tan(), log(), ln(), exp(), sqrt(), pow()\n");
    printf("Valid constants: pi\n");

    while (1) {
        printf("Enter an expression or 'exit' to quit: ");
        fgets(input, MAX_STACK_SIZE, stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        for (int i = 0; i < strlen(input); i++) {
            if (isdigit(input[i])) {
                num = input[i] - '0';
                while (isdigit(input[i+1])) {
                    num = num * 10 + input[i+1] - '0';
                    i++;
                }
                push(num);
            }
            else if (isspace(input[i])) {
                continue;
            }
            else if (input[i] == '+') {
                x = pop();
                y = pop();
                push(y + x);
            }
            else if (input[i] == '-') {
                x = pop();
                y = pop();
                push(y - x);
            }
            else if (input[i] == '*') {
                x = pop();
                y = pop();
                push(y * x);
            }
            else if (input[i] == '/') {
                x = pop();
                y = pop();
                push(y / x);
            }
            else if (input[i] == 's' && input[i+1] == 'i' && input[i+2] == 'n' && input[i+3] == '(') {
                i += 3;
                int j = i+1;
                while (input[j] != ')') {
                    j++;
                }
                num = atof(strndup(&input[i+1], j-i-1));
                push(sin_func(num));
                i = j;
            }
            else if (input[i] == 'c' && input[i+1] == 'o' && input[i+2] == 's' && input[i+3] == '(') {
                i += 3;
                int j = i+1;
                while (input[j] != ')') {
                    j++;
                }
                num = atof(strndup(&input[i+1], j-i-1));
                push(cos_func(num));
                i = j;
            }
            else if (input[i] == 't' && input[i+1] == 'a' && input[i+2] == 'n' && input[i+3] == '(') {
                i += 3;
                int j = i+1;
                while (input[j] != ')') {
                    j++;
                }
                num = atof(strndup(&input[i+1], j-i-1));
                push(tan_func(num));
                i = j;
            }
            else if (input[i] == 'l' && input[i+1] == 'o' && input[i+2] == 'g' && input[i+3] == '(') {
                i += 3;
                int j = i+1;
                while (input[j] != ')') {
                    j++;
                }
                num = atof(strndup(&input[i+1], j-i-1));
                push(log_func(num));
                i = j;
            }
            else if (input[i] == 'l' && input[i+1] == 'n' && input[i+2] == '(') {
                i += 2;
                int j = i+1;
                while (input[j] != ')') {
                    j++;
                }
                num = atof(strndup(&input[i+1], j-i-1));
                push(ln_func(num));
                i = j;
            }
            else if (input[i] == 'e' && input[i+1] == 'x' && input[i+2] == 'p' && input[i+3] == '(') {
                i += 3;
                int j = i+1;
                while (input[j] != ')') {
                    j++;
                }
                num = atof(strndup(&input[i+1], j-i-1));
                push(exp_func(num));
                i = j;
            }
            else if (input[i] == 's' && input[i+1] == 'q' && input[i+2] == 'r' && input[i+3] == 't' && input[i+4] == '(') {
                i += 4;
                int j = i+1;
                while (input[j] != ')') {
                    j++;
                }
                num = atof(strndup(&input[i+1], j-i-1));
                push(sqrt_func(num));
                i = j;
            }
            else if (input[i] == 'p' && input[i+1] == 'o' && input[i+2] == 'w' && input[i+3] == '(') {
                i += 3;
                int j = i+1;
                while (input[j] != ',') {
                    j++;
                }
                x = atof(strndup(&input[i+1], j-i-1));
                i = j + 1;
                j = i+1;
                while (input[j] != ')') {
                    j++;
                }
                y = atof(strndup(&input[i], j-i));
                push(pow_func(x, y));
                i = j;
            }
            else if (input[i] == 'p' && input[i+1] == 'i') {
                push(PI);
                i++;
            }
            else {
                printf("Invalid operator or constant\n");
                break;
            }
        }

        printf("Result: %.2f\n", pop());
    }

    return 0;
}