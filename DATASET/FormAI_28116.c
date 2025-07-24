//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

void calculateSum(double* a, double* b, double* c, double* d, double* e, double* f, double* g, double* h, double* i, double* j)
{
    for(int k = 0; k < N; ++k)
    {
        *a += k;
        *b += k*k;
        *c += k*k*k;
        *d += 1.0/k;
        *e += sin(k);
        *f += cos(k);
        *g += exp(k);
        *h += sqrt((double)k);
        *i += log(k);
        *j += pow(k, 3);
    }
}

int main(void)
{
    clock_t begin = clock();

    double a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0;

    calculateSum(&a, &b, &c, &d, &e, &f, &g, &h, &i, &j);

    printf("The sum of a is: %f\n", a);
    printf("The sum of b is: %f\n", b);
    printf("The sum of c is: %f\n", c);
    printf("The sum of d is: %f\n", d);
    printf("The sum of e is: %f\n", e);
    printf("The sum of f is: %f\n", f);
    printf("The sum of g is: %f\n", g);
    printf("The sum of h is: %f\n", h);
    printf("The sum of i is: %f\n", i);
    printf("The sum of j is: %f\n", j);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time taken to execute the function: %f\n", time_spent);

    return 0;
}