//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: modular
#include<stdio.h>
#include<math.h>

double add(double x, double y) {
    return x+y;
}

double subtract(double x, double y) {
    return x-y;
}

double multiply(double x, double y){
    return x*y;
}

double divide(double x, double y){
    return x/y;
}

double power(double x, double y){
    return pow(x,y);
}

double square_root(double x){
    return sqrt(x);
}

double absolute(double x){
    return fabs(x);
}

double modulus(double x, double y){
    return fmod(x, y);
}

int main(){
    char operator;
    double first_num, second_num, result;
    printf("Enter an operator (+, -, *, /, ^, s, a, %%,): ");
    scanf("%c", &operator);

    switch(operator){
        case '+':
            printf("Enter the first number: ");
            scanf("%lf", &first_num);
            printf("Enter the second number: ");
            scanf("%lf", &second_num);
            result = add(first_num, second_num);
            printf("%.2lf + %.2lf = %.2lf\n", first_num, second_num, result);
            break;
            
        case '-':
            printf("Enter the first number: ");
            scanf("%lf", &first_num);
            printf("Enter the second number: ");
            scanf("%lf", &second_num);
            result = subtract(first_num, second_num);
            printf("%.2lf - %.2lf = %.2lf\n", first_num, second_num, result);
            break;
            
        case '*':
            printf("Enter the first number: ");
            scanf("%lf", &first_num);
            printf("Enter the second number: ");
            scanf("%lf", &second_num);
            result = multiply(first_num, second_num);
            printf("%.2lf * %.2lf = %.2lf\n", first_num, second_num, result);
            break;
            
        case '/':
            printf("Enter the first number: ");
            scanf("%lf", &first_num);
            printf("Enter the second number: ");
            scanf("%lf", &second_num);
            if(second_num != 0) {
                result = divide(first_num, second_num);
                printf("%.2lf / %.2lf = %.2lf\n", first_num, second_num, result);
            }
            else {
                printf("Error: Division by zero.\n");
            }
            break;

        case '^':
            printf("Enter the base: ");
            scanf("%lf", &first_num);
            printf("Enter the exponent: ");
            scanf("%lf", &second_num);
            result = power(first_num, second_num);
            printf("%.2lf ^ %.2lf = %.2lf\n", first_num, second_num, result);
            break;

        case 's':
            printf("Enter the number: ");
            scanf("%lf", &first_num);
            result = square_root(first_num);
            printf("sqrt(%.2lf) = %.2lf\n", first_num, result);
            break;

        case 'a':
            printf("Enter the number: ");
            scanf("%lf", &first_num);
            result = absolute(first_num);
            printf("abs(%.2lf) = %.2lf\n", first_num, result);
            break;

        case '%':
            printf("Enter the dividend: ");
            scanf("%lf", &first_num);
            printf("Enter the divisor: ");
            scanf("%lf", &second_num);
            result = modulus(first_num, second_num);
            printf("%.2lf %% %.2lf = %.2lf\n", first_num, second_num, result);
            break;

        default:
            printf("Error: Invalid operator.\n");
            break;
    }
    return 0;
}