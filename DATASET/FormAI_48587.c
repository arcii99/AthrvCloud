//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

int main() {
    double x, y, result;
    char operator;

    printf("Enter a mathematical expression in the format: a operator b\n");
    scanf("%lf %c %lf", &x, &operator, &y);

    switch (operator) {
        case '+':
            result = x + y;
            printf("%lf + %lf = %lf\n", x, y, result);
            break;
        case '-':
            result = x - y;
            printf("%lf - %lf = %lf\n", x, y, result);
            break;
        case '*':
            result = x * y;
            printf("%lf * %lf = %lf\n", x, y, result);
            break;
        case '/':
            if (y == 0) {
                printf("Cannot divide by zero\n");
            } else {
                result = x / y;
                printf("%lf / %lf = %lf\n", x, y, result);
            }
            break;
        case '^':
            result = pow(x, y);
            printf("%lf ^ %lf = %lf\n", x, y, result);
            break;
        case 's':
            result = sin(x);
            printf("sin(%lf) = %lf\n", x, result);
            break;
        case 'c':
            result = cos(x);
            printf("cos(%lf) = %lf\n", x, result);
            break;
        case 't':
            result = tan(x);
            printf("tan(%lf) = %lf\n", x, result);
            break;
        case 'q':
            result = sqrt(x);
            printf("sqrt(%lf) = %lf\n", x, result);
            break;
        default:
            printf("Invalid operator\n");
    }

    return 0;
}