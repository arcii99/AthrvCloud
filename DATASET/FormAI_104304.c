//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Donald Knuth
/* 
 * Fractal Generation in C
 * A Donald Knuth Style Example Program
 */

#include <stdio.h>
#include <stdlib.h>

/* Struct for storing complex numbers */
typedef struct complex {
    double real;
    double imag;
} complex;

/* Function for adding two complex numbers */
complex add(complex a, complex b) {
    complex sum;
    sum.real = a.real + b.real;
    sum.imag = a.imag + b.imag;
    return sum;
}

/* Function for squaring a complex number */
complex square(complex z) {
    complex result;
    result.real = (z.real * z.real) - (z.imag * z.imag);
    result.imag = 2 * z.real * z.imag;
    return result;
}

/* Function for generating the fractal */
void generateFractal(int n) {
    int i, j, k;
    double x, y;
    complex z, c, temp;

    for(i = -n; i <= n; i++) {
        for(j = -n; j <= n; j++) {
            x = (double) j / n;
            y = (double) i / n;
            z.real = 0;
            z.imag = 0;
            c.real = x;
            c.imag = y;
            for(k = 0; k < 100; k++) {
                temp = square(z);
                z = add(temp, c);
                if(z.real * z.real + z.imag * z.imag > 4) {
                    putchar(' ');
                    break;
                }
                putchar('*');
            }
        }
        putchar('\n');
        fflush(stdout);
    }
}

/* Main function */
int main() {
    generateFractal(30);
    return 0;
}