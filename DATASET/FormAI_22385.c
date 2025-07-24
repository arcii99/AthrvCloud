//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <math.h>
#include <pthread.h>

double result;

void *calculate(void *arg) {
    double *arr = (double *) arg;
    char operator = (char) arr[0];
    double num1 = arr[1];
    double num2 = arr[2];

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '^':
            result = pow(num1, num2);
            break;
        case 'r':
            result = pow(num1, 1 / num2);
            break;
        case '!':
            result = 1;
            for (int i = 1; i <= num1; i++) {
                result *= i;
            }
            break;
        default:
            printf("Invalid operator\n");
    }

    return NULL;
}

int main() {
    char operator;
    double num1, num2;

    pthread_t thread_id;

    printf("Enter operator (+, -, *, /, ^, r, !): ");
    scanf("%c", &operator);

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    double arr[] = {(double) operator, num1, num2};

    pthread_create(&thread_id, NULL, calculate, arr);

    pthread_join(thread_id, NULL);

    printf("Result: %.2f\n", result);

    return 0;
}