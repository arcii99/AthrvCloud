//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mathematical
/* This is a custom implementation of a Scientific Calculator in C */
/* The calculator uses Reverse Polish Notation (RPN) to evaluate expressions */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_STACK_SIZE 1000
#define MAX_EXPRESSION_SIZE 1000

double stack[MAX_STACK_SIZE];
int stack_top = -1;

void push(double val) {
   if (stack_top < MAX_STACK_SIZE - 1) {
      stack[++stack_top] = val;
   } else {
      printf("Error: Stack overflow\n");
      exit(EXIT_FAILURE);
   }
}

double pop() {
   if (stack_top >= 0) {
      return stack[stack_top--];
   } else {
      printf("Error: Stack underflow\n");
      exit(EXIT_FAILURE);
   }
}

void clear_stack() {
   stack_top = -1;
}

int is_operator(char c) {
   return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '$';
}

double evaluate(char expression[]) {
   clear_stack();
   char *token = strtok(expression, " ");
   while (token != NULL) {
      if (isdigit(token[0])) {
         push(atof(token));
      } else if (is_operator(token[0])) {
         double op2 = pop();
         double op1 = pop();
         switch (token[0]) {
            case '+':
               push(op1 + op2);
               break;
            case '-':
               push(op1 - op2);
               break;
            case '*':
               push(op1 * op2);
               break;
            case '/':
               push(op1 / op2);
               break;
            case '^':
               push(pow(op1, op2));
               break;
            case '$':
               push(sqrt(op2));
               break;
            default:
               printf("Error: Invalid operator '%c'\n", token[0]);
               exit(EXIT_FAILURE);
         }
      }
      token = strtok(NULL, " ");
   }
   return pop();
}

int main() {
   char expression[MAX_EXPRESSION_SIZE];
   printf("Enter an expression in RPN: ");
   fgets(expression, MAX_EXPRESSION_SIZE, stdin);
   printf("Result: %g\n", evaluate(expression));
   return 0;
}