//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/* This is a scientific calculator program that implements the following operations:
+ Addition
- Subtraction
* Multiplication
/ Division
^ Exponentiation
% Modulo
sin(x), cos(x), tan(x), log(x), ln(x), sqrt(x), fabs(x) */
 
int main() {
    char input[1000];
    double number, answer;
    int i, j, length, s, num_counter, dot_counter;
    char op, num[1000];
    double stack[1000];
    int top = -1;
 
    printf("Welcome to my scientific calculator program!\n");
    printf("Please enter expressions in the format: number operator number\n");
    printf("Valid operators: +, -, *, /, ^, %%, sin(x), cos(x), tan(x), log(x), ln(x), sqrt(x), fabs(x)\n");
 
    while (1) {
        printf("Enter an expression: ");
        fgets(input, sizeof(input), stdin);
        length = strlen(input);
 
        if (input[length - 1] == '\n') {
            input[length - 1] = '\0';
        }
 
        if (strcmp(input, "exit") == 0) {
            printf("Exiting calculator program...\n");
            break;
        }
 
        num_counter = 0;
        dot_counter = 0;
 
        for (i = 0; i < length; i++) {
            if (isdigit(input[i]) || input[i] == '.') {
                num[num_counter] = input[i];
                num_counter++;
 
                if (input[i] == '.') {
                    dot_counter++;
                }
            }
 
            else if (isspace(input[i])) {
                if (dot_counter > 1) {
                    printf("Error: Invalid input.\n");
                    num_counter = 0;
                    break;
                }
 
                num[num_counter] = '\0';
                number = atof(num);
                top++;
                stack[top] = number;
                num_counter = 0;
                dot_counter = 0;
            }
 
            else if (isalpha(input[i])) {
                char func_name[100];
                j = i;
                s = 0;
 
                while (isalpha(input[j])) {
                    func_name[s] = input[j];
                    j++;
                    s++;
                }
 
                func_name[s] = '\0';
 
                if (strcmp(func_name, "sin") == 0) {
                    double angle;
 
                    if (input[j] == '(') {
                        num_counter = 0;
 
                        for (i = j + 1; i < length; i++) {
                            if (isdigit(input[i]) || input[i] == '.') {
                                num[num_counter] = input[i];
                                num_counter++;
 
                                if (input[i] == '.') {
                                    dot_counter++;
                                }
                            }
 
                            else if (input[i] == ')') {
                                if (dot_counter > 1) {
                                    printf("Error: Invalid input.\n");
                                    num_counter = 0;
                                    break;
                                }
 
                                num[num_counter] = '\0';
                                angle = atof(num);
                                angle = angle * M_PI / 180;
                                top++;
                                stack[top] = sin(angle);
                                num_counter = 0;
                                dot_counter = 0;
                                break;
                            }
 
                            else {
                                printf("Error: Invalid input.\n");
                                num_counter = 0;
                                break;
                            }
                        }
 
                        if (input[i] != ')') {
                            printf("Error: Invalid input.\n");
                        }
                    }
 
                    else {
                        printf("Error: Invalid input.\n");
                    }
                }
 
                else if (strcmp(func_name, "cos") == 0) {
                    double angle;
 
                    if (input[j] == '(') {
                        num_counter = 0;
 
                        for (i = j + 1; i < length; i++) {
                            if (isdigit(input[i]) || input[i] == '.') {
                                num[num_counter] = input[i];
                                num_counter++;
 
                                if (input[i] == '.') {
                                    dot_counter++;
                                }
                            }
 
                            else if (input[i] == ')') {
                                if (dot_counter > 1) {
                                    printf("Error: Invalid input.\n");
                                    num_counter = 0;
                                    break;
                                }
 
                                num[num_counter] = '\0';
                                angle = atof(num);
                                angle = angle * M_PI / 180;
                                top++;
                                stack[top] = cos(angle);
                                num_counter = 0;
                                dot_counter = 0;
                                break;
                            }
 
                            else {
                                printf("Error: Invalid input.\n");
                                num_counter = 0;
                                break;
                            }
                        }
 
                        if (input[i] != ')') {
                            printf("Error: Invalid input.\n");
                        }
                    }
 
                    else {
                        printf("Error: Invalid input.\n");
                    }
                }
 
                else if (strcmp(func_name, "tan") == 0) {
                    double angle;
 
                    if (input[j] == '(') {
                        num_counter = 0;
 
                        for (i = j + 1; i < length; i++) {
                            if (isdigit(input[i]) || input[i] == '.') {
                                num[num_counter] = input[i];
                                num_counter++;
 
                                if (input[i] == '.') {
                                    dot_counter++;
                                }
                            }
 
                            else if (input[i] == ')') {
                                if (dot_counter > 1) {
                                    printf("Error: Invalid input.\n");
                                    num_counter = 0;
                                    break;
                                }
 
                                num[num_counter] = '\0';
                                angle = atof(num);
                                angle = angle * M_PI / 180;
                                top++;
                                stack[top] = tan(angle);
                                num_counter = 0;
                                dot_counter = 0;
                                break;
                            }
 
                            else {
                                printf("Error: Invalid input.\n");
                                num_counter = 0;
                                break;
                            }
                        }
 
                        if (input[i] != ')') {
                            printf("Error: Invalid input.\n");
                        }
                    }
 
                    else {
                        printf("Error: Invalid input.\n");
                    }
                }
 
                else if (strcmp(func_name, "log") == 0) {
                    double val;
                    int base;
 
                    if (input[j] == '(') {
                        num_counter = 0;
 
                        for (i = j + 1; i < length; i++) {
                            if (isdigit(input[i]) || input[i] == '.') {
                                num[num_counter] = input[i];
                                num_counter++;
 
                                if (input[i] == '.') {
                                    dot_counter++;
                                }
                            }
 
                            else if (input[i] == ',') {
                                if (dot_counter > 1) {
                                    printf("Error: Invalid input.\n");
                                    num_counter = 0;
                                    break;
                                }
 
                                num[num_counter] = '\0';
                                val = atof(num);
                                num_counter = 0;
                                dot_counter = 0;
                            }
 
                            else if (isdigit(input[i])) {
                                base = base * 10 + (input[i] - '0');
                            }
 
                            else {
                                printf("Error: Invalid input.\n");
                                num_counter = 0;
                                break;
                            }
                        }
 
                        if (input[i] != ')') {
                            printf("Error: Invalid input.\n");
                        }
                    }
 
                    else {
                        printf("Error: Invalid input.\n");
                    }
 
                    top++;
                    stack[top] = log(val) / log(base);
                }
 
                else if (strcmp(func_name, "ln") == 0) {
                    double val;
 
                    if (input[j] == '(') {
                        num_counter = 0;
 
                        for (i = j + 1; i < length; i++) {
                            if (isdigit(input[i]) || input[i] == '.') {
                                num[num_counter] = input[i];
                                num_counter++;
 
                                if (input[i] == '.') {
                                    dot_counter++;
                                }
                            }
 
                            else if (input[i] == ')') {
                                if (dot_counter > 1) {
                                    printf("Error: Invalid input.\n");
                                    num_counter = 0;
                                    break;
                                }
 
                                num[num_counter] = '\0';
                                val = atof(num);
                                top++;
                                stack[top] = log(val);
                                num_counter = 0;
                                dot_counter = 0;
                                break;
                            }
 
                            else {
                                printf("Error: Invalid input.\n");
                                num_counter = 0;
                                break;
                            }
                        }
 
                        if (input[i] != ')') {
                            printf("Error: Invalid input.\n");
                        }
                    }
 
                    else {
                        printf("Error: Invalid input.\n");
                    }
                }
 
                else if (strcmp(func_name, "sqrt") == 0) {
                    double val;
 
                    if (input[j] == '(') {
                        num_counter = 0;
 
                        for (i = j + 1; i < length; i++) {
                            if (isdigit(input[i]) || input[i] == '.') {
                                num[num_counter] = input[i];
                                num_counter++;
 
                                if (input[i] == '.') {
                                    dot_counter++;
                                }
                            }
 
                            else if (input[i] == ')') {
                                if (dot_counter > 1) {
                                    printf("Error: Invalid input.\n");
                                    num_counter = 0;
                                    break;
                                }
 
                                num[num_counter] = '\0';
                                val = atof(num);
                                top++;
                                stack[top] = sqrt(val);
                                num_counter = 0;
                                dot_counter = 0;
                                break;
                            }
 
                            else {
                                printf("Error: Invalid input.\n");
                                num_counter = 0;
                                break;
                            }
                        }
 
                        if (input[i] != ')') {
                            printf("Error: Invalid input.\n");
                        }
                    }
 
                    else {
                        printf("Error: Invalid input.\n");
                    }
                }
 
                else if (strcmp(func_name, "fabs") == 0) {
                    double val;
 
                    if (input[j] == '(') {
                        num_counter = 0;
 
                        for (i = j + 1; i < length; i++) {
                            if (isdigit(input[i]) || input[i] == '.') {
                                num[num_counter] = input[i];
                                num_counter++;
 
                                if (input[i] == '.') {
                                    dot_counter++;
                                }
                            }
 
                            else if (input[i] == ')') {
                                if (dot_counter > 1) {
                                    printf("Error: Invalid input.\n");
                                    num_counter = 0;
                                    break;
                                }
 
                                num[num_counter] = '\0';
                                val = atof(num);
                                top++;
                                stack[top] = fabs(val);
                                num_counter = 0;
                                dot_counter = 0;
                                break;
                            }
 
                            else {
                                printf("Error: Invalid input.\n");
                                num_counter = 0;
                                break;
                            }
                        }
 
                        if (input[i] != ')') {
                            printf("Error: Invalid input.\n");
                        }
                    }
 
                    else {
                        printf("Error: Invalid input.\n");
                    }
                }
 
                else {
                    printf("Error: Invalid function.\n");
                }
 
                i = j - 1;
            }
 
            else {
                op = input[i];
 
                if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '%') {
                    if (top < 1) {
                        printf("Error: Invalid input.\n");
                        break;
                    }
 
                    if (op == '+') {
                        answer = stack[top - 1] + stack[top];
                    }
 
                    else if (op == '-') {
                        answer = stack[top - 1] - stack[top];
                    }
 
                    else if (op == '*') {
                        answer = stack[top - 1] * stack[top];
                    }
 
                    else if (op == '/') {
                        if (stack[top] == 0) {
                            printf("Error: Division by zero.\n");
                            top--;
                            break;
                        }
 
                        answer = stack[top - 1] / stack[top];
                    }
 
                    else if (op == '^') {
                        answer = pow(stack[top - 1], stack[top]);
                    }
 
                    else if (op == '%') {
                        answer = fmod(stack[top - 1], stack[top]);
                    }
 
                    top--;
                    stack[top] = answer;
                }
 
                else {
                    printf("Error: Invalid input.\n");
                    break;
                }
            }
        }
 
        if (top != 0) {
            printf("Error: Invalid input.\n");
            top = -1;
        }
 
        else {
            printf("Answer: %.10lf\n", stack[top]);
            top = -1;
        }
    }
 
    return 0;
}