//FormAI DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>

typedef struct {
    float real;
    float imaginary;
} Complex;

void print_complex(Complex c) {
    if (c.imaginary >= 0) {
        printf("%f + %fi\n", c.real, c.imaginary);
    } else {
        printf("%f - %fi\n", c.real, -c.imaginary);
    }
}

Complex add_complex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

Complex subtract_complex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real - c2.real;
    result.imaginary = c1.imaginary - c2.imaginary;
    return result;
}

Complex multiply_complex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    result.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
    return result;
}

Complex divide_complex(Complex c1, Complex c2) {
    Complex result;
    float denominator = c2.real * c2.real + c2.imaginary * c2.imaginary;
    result.real = (c1.real * c2.real + c1.imaginary * c2.imaginary) / denominator;
    result.imaginary = (c1.imaginary * c2.real - c1.real * c2.imaginary) / denominator;
    return result;
}

int main() {
    Complex c1 = {3.5, 4.2};
    Complex c2 = {2.1, -1.4};
    
    printf("c1: ");
    print_complex(c1);
    printf("c2: ");
    print_complex(c2);
    
    Complex sum = add_complex(c1, c2);
    printf("c1 + c2: ");
    print_complex(sum);
    
    Complex difference = subtract_complex(c1, c2);
    printf("c1 - c2: ");
    print_complex(difference);
    
    Complex product = multiply_complex(c1, c2);
    printf("c1 * c2: ");
    print_complex(product);
    
    Complex quotient = divide_complex(c1, c2);
    printf("c1 / c2: ");
    print_complex(quotient);
    
    return 0;
}