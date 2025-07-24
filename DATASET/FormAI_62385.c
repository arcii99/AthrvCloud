//FormAI DATASET v1.0 Category: Math exercise ; Style: Cryptic
#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, x1, x2, discriminant, realPart, imaginaryPart;

    printf("Enter coefficients a, b and c: ");
    scanf("%f %f %f", &a, &b, &c);

    discriminant = b*b - 4*a*c;

    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        printf("Roots are real and different. \n");
        printf("x1 = %f \n", x1);
        printf("x2 = %f \n", x2);
    }
    else if (discriminant == 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        printf("Roots are real and same. \n");
        printf("x1 = %f \n", x1);
    }
    else {
        realPart = -b/(2*a);
        imaginaryPart = sqrt(-discriminant)/(2*a);
        printf("Roots are complex and different. \n");
        printf("x1 = %f + %fi\n", realPart, imaginaryPart);
        printf("x2 = %f - %fi\n", realPart, imaginaryPart);
    }

    return 0;
}