//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: future-proof
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

double get_input(char op);
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double square_root(double x);
double power(double x, double y);
double sine(double x);
double cosine(double x);
double tangent(double x);


int main()
{
    char operation;
    double x, y, result;
    
    printf("Welcome to the Scientific Calculator Application!\n");
    printf("Enter the operation you want to perform: [+,-,*,/,s,p,x]\n");

    scanf("%c", &operation);

    switch (operation) {
        case '+':
            x = get_input('1');
            y = get_input('2');
            result = add(x,y);
            printf("The sum of %lf and %lf is %lf\n", x, y, result);
            break;
            
        case '-':
            x = get_input('1');
            y = get_input('2');
            result = subtract(x,y); 
            printf("The difference of %lf and %lf is %lf\n", x, y, result);
            break;
            
        case '*':
            x = get_input('1');
            y = get_input('2');
            result = multiply(x,y);
            printf("The product of %lf and %lf is %lf\n", x, y, result);
            break;
            
        case '/':
            x = get_input('1');
            y = get_input('2');
            result = divide(x,y);
            printf("The quotient of %lf and %lf is %lf\n", x, y, result);
            break;
        
        case 's':
            x = get_input('1');
            result = square_root(x);
            printf("The square root of %lf is %lf\n", x, result);
            break;
            
        case 'p':
            x = get_input('1');
            y = get_input('2');
            result = power(x,y);
            printf("%lf raised to the power of %lf is %lf\n", x, y, result);
            break;
            
        case 'x':
            x = get_input('1');
            result = sine(x);
            printf("The sine of %lf is %lf\n", x, result);
            break;
            
        case 'y':
            x = get_input('1');
            result = cosine(x);
            printf("The cosine of %lf is %lf\n", x, result);
            break;
            
        case 'z':
            x = get_input('1');
            result = tangent(x);
            printf("The tangent of %lf is %lf\n", x, result);
            break;
            
        default:
            printf("Invalid operation entered. Please try again.\n");
            break;
    }

    return 0;
}


double get_input(char op)
{
    double x;
    printf("Enter number %c: ", op);
    scanf("%lf", &x);
    return x;
}

double add(double x, double y)
{
    return x + y;
}

double subtract(double x, double y)
{
    return x - y;
}

double multiply(double x, double y)
{
    return x * y;
}

double divide(double x, double y)
{
    if (y == 0)
        return -1;

    return x / y;
}

double square_root(double x)
{
    if (x < 0)
        return -1;

    return sqrt(x);
}

double power(double x, double y)
{
    return pow(x,y);
}

double sine(double x)
{
    x *= PI/180.0;
    return sin(x);
}

double cosine(double x)
{
    x *= PI/180.0;
    return cos(x);
}

double tangent(double x)
{
    x *= PI/180.0;
    return tan(x);
}