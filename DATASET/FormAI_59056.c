//FormAI DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>
#include<math.h>

int main()
{
    int num1,num2;
    float root1,root2,discriminant,realPart,imaginaryPart;

    // take input from user
    printf("Enter values of a, b and c of quadratic equation (ax^2 + bx + c):\n");
    scanf("%d %d",&num1,&num2);

    // calculate discriminant
    discriminant = (num2*num2) - (4*num1*num2);

    // check the nature of roots
    if (discriminant > 0)
    {
        // calculate roots
        root1 = (-num2 + sqrt(discriminant))/(2*num1);
        root2 = (-num2 - sqrt(discriminant))/(2*num1);

        printf("Roots are real and distinct\n");
        printf("Root 1 = %.2f and Root 2 = %.2f\n", root1, root2);
    }
    else if (discriminant == 0)
    {
        // calculate roots
        root1 = root2 = (-num2)/(2*num1);

        printf("Roots are real and equal\n");
        printf("Root 1 = Root 2 = %.2f\n", root1);
    }
    else
    {
        // calculate real and imaginary parts of roots
        realPart = (-num2)/(2*num1);
        imaginaryPart = sqrt(-discriminant)/(2*num1);

        printf("Roots are complex and different\n");
        printf("Root 1 = %.2f + %.2fi and Root 2 = %.2f - %.2fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}