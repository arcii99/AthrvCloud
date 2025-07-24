//FormAI DATASET v1.0 Category: Calculator ; Style: complex
// Complex Calculator Example Program in C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    double real;
    double imag;
} Complex;

void print_complex(Complex c) {
    if (c.imag < 0) {
        printf("%.2f - %.2fi\n", c.real, fabs(c.imag));
    } else {
        printf("%.2f + %.2fi\n", c.real, c.imag);
    }
}

Complex add_complex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

Complex subtract_complex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}

Complex multiply_complex(Complex c1, Complex c2) {
    Complex result;
    result.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    result.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
    return result;
}

Complex divide_complex(Complex c1, Complex c2) {
    Complex result;
    double denominator = pow(c2.real, 2) + pow(c2.imag, 2);
    result.real = ((c1.real * c2.real) + (c1.imag * c2.imag)) / denominator;
    result.imag = ((c1.imag * c2.real) - (c1.real * c2.imag)) / denominator;
    return result;
}

double get_magnitude(Complex c) {
    double magnitude = sqrt(pow(c.real, 2) + pow(c.imag, 2));
    return magnitude;
}

double get_phase(Complex c) {
    double phase = atan2(c.imag, c.real);
    return phase;
}

int main() {
    Complex c1, c2, result;
    char operation;
    bool valid_operation = true;

    printf("Enter the first complex number (a + bi): ");
    scanf("%lf%lf", &c1.real, &c1.imag);
    printf("Enter the second complex number (a + bi): ");
    scanf("%lf%lf", &c2.real, &c2.imag);

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    if (operation == '+') {
        result = add_complex(c1, c2);
    } else if (operation == '-') {
        result = subtract_complex(c1, c2);
    } else if (operation == '*') {
        result = multiply_complex(c1, c2);
    } else if (operation == '/') {
        result = divide_complex(c1, c2);
    } else {
        valid_operation = false;
        printf("Invalid Operation!\n");
    }

    if (valid_operation) {
        printf("Result: ");
        print_complex(result);

        printf("Magnitude of Result: %.2f\n", get_magnitude(result));
        printf("Phase of Result: %.2f radians\n", get_phase(result));
    }

    return 0;
}