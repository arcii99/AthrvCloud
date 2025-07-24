//FormAI DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// function prototypes
int add(int x, int y);
float subtract(float x, float y);
double multiply(double x, double y);
long divide(long x, long y);

int main()
{
    int a = 10, b = 5;
    float c = 2.5, d = 1.5;
    double e = 12.345, f = 6.789;
    long g = 100, h = 20;

    // call functions and output results
    printf("a + b = %d\n", add(a, b));
    printf("c - d = %f\n", subtract(c, d));
    printf("e * f = %lf\n", multiply(e, f));
    printf("g / h = %ld\n", divide(g, h));

    return 0;
}

// function definitions
int add(int x, int y)
{
    return x + y;
}

float subtract(float x, float y)
{
    return x - y;
}

double multiply(double x, double y)
{
    return x * y;
}

long divide(long x, long y)
{
    if (y == 0)
    {
        printf("Error: division by zero\n");
        exit(EXIT_FAILURE);
    }
    return x / y;
}