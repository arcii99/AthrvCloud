//FormAI DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float a, b, c, discriminant, root1, root2, realPart, imagPart;

    printf("Enter coefficients of quadratic equation (a, b, c): ");
    scanf("%f%f%f", &a, &b, &c);

    discriminant = b*b - 4*a*c;

    if(discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2*a);
        root2 = (-b - sqrt(discriminant)) / (2*a);

        printf("Roots are: %.2f and %.2f", root1, root2);
    }
    else if(discriminant == 0) {
        root1 = root2 = -b / (2*a);

        printf("Roots are: %.2f and %.2f", root1, root2);
    }
    else {
        realPart = -b / (2*a);
        imagPart = sqrt(-discriminant) / (2*a);

        printf("Roots are: %.2f+%.2fi and %.2f-%.2fi", realPart, imagPart, realPart, imagPart);
    }

    return 0;
}