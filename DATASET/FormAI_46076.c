//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define operations
#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define SIN 's'
#define COS 'c'
#define TAN 't'
#define SQRT 'q'
#define LOG 'l'
#define EXP 'e'

// Function to perform arithmetic operation
double arithmetic_operate(double first_operand, char operator, double second_operand) {
    switch(operator) {
        case ADD:
            return first_operand + second_operand;
        case SUB:
            return first_operand - second_operand;
        case MUL:
            return first_operand * second_operand;
        case DIV:
            return first_operand / second_operand;
        default:
            return 0.0;
    }
}

// Function to perform scientific operation
double scientific_operate(char operator, double operand) {
    switch(operator) {
        case SIN:
            return sin(operand);
        case COS:
            return cos(operand);
        case TAN:
            return tan(operand);
        case SQRT:
            return sqrt(operand);
        case LOG:
            return log(operand);
        case EXP:
            return exp(operand);
        default:
            return 0.0;
    }
}

// Main function
int main() {
    // Declare variables
    char opr;
    double first_num, second_num, result;
    int mode;

    // Ask user to select mode
    printf("Select mode:\n1 - Arithmetic\n2 - Scientific\n");
    scanf("%d", &mode);

    // Perform operation based on selected mode
    if(mode == 1) {
        // Get input and perform arithmetic operation
        printf("Enter first number: ");
        scanf("%lf", &first_num);
        printf("Enter operator (+, -, *, /): ");
        scanf(" %c", &opr);
        printf("Enter second number: ");
        scanf("%lf", &second_num);

        result = arithmetic_operate(first_num, opr, second_num);

        // Display result
        printf("%.2lf %c %.2lf = %.2lf", first_num, opr, second_num, result);
    }
    else {
        // Get input and perform scientific operation
        printf("Enter operator (s, c, t, q, l, e): ");
        scanf(" %c", &opr);
        printf("Enter number: ");
        scanf("%lf", &first_num);

        result = scientific_operate(opr, first_num);

        // Display result
        printf("%c(%.2lf) = %.2lf", opr, first_num, result);
    }

    return 0;
}