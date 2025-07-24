//FormAI DATASET v1.0 Category: Math exercise ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

int main() {

    float a, b, c, discriminant, root1, root2, realPart, imaginaryPart;
    
    printf("Enter the values of a, b and c: ");
    scanf("%f%f%f", &a, &b, &c);
    
    discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2*a);
        root2 = (-b - sqrt(discriminant)) / (2*a);
        printf("Roots are: %.2f and %.2f", root1, root2);
    }
    else if (discriminant == 0) {
        root1 = root2 = -b / (2*a);
        printf("Roots are: %.2f and %.2f", root1, root2);
    }
    else {
        realPart = -b / (2*a);
        imaginaryPart = sqrt(-discriminant) / (2*a);
        printf("Roots are: %.2f + %.2fi and %.2f - %.2fi", realPart, imaginaryPart, realPart, imaginaryPart);
    }

    // Calculate absolute value of a,b,c
    float abs_a = fabs(a);
    float abs_b = fabs(b);
    float abs_c = fabs(c);
    
    // Calculate logarithm of a,b,c
    float log_a = log10(abs_a);
    float log_b = log10(abs_b);
    float log_c = log10(abs_c);

    // Calculate power of a,b,c
    float pow_a = pow(a,2);
    float pow_b = pow(b,2);
    float pow_c = pow(c,2);

    // Calculate square root of a,b,c
    float sqrt_a = sqrt(abs_a);
    float sqrt_b = sqrt(abs_b);
    float sqrt_c = sqrt(abs_c);

    printf("\nAbsolute value of a, b and c: %.2f, %.2f, %.2f", abs_a, abs_b, abs_c);
    printf("\nLogarithm of a, b and c: %.2f, %.2f, %.2f", log_a, log_b, log_c);
    printf("\nSquare of a, b and c: %.2f, %.2f, %.2f", pow_a, pow_b, pow_c);
    printf("\nSquare root of a, b and c: %.2f, %.2f, %.2f", sqrt_a, sqrt_b, sqrt_c);
    
    return 0;
}