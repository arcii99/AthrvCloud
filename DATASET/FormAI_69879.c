//FormAI DATASET v1.0 Category: Math exercise ; Style: introspective
#include <stdio.h>
#include <math.h>

int main()
{
    int choice;
    float a,b,c,result,degree,radian;

    printf("Welcome to the Math Exercise program!\n");
    printf("Please select an operation from the following options:\n");
    printf("1. Square Root\n");
    printf("2. Power\n");
    printf("3. Logarithm\n");
    printf("4. Sine\n");
    printf("5. Cosine\n");
    printf("6. Tangent\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("Enter a number to find its square root: ");
            scanf("%f",&a);
            result = sqrt(a);
            printf("The square root of %f is %f\n",a,result);
            break;

        case 2:
            printf("Enter a base number: ");
            scanf("%f",&a);
            printf("Enter an exponent number: ");
            scanf("%f",&b);
            result = pow(a,b);
            printf("%f raised to the power of %f is %f\n",a,b,result);
            break;

        case 3:
            printf("Enter a number to find its natural logarithm: ");
            scanf("%f",&a);
            result = log(a);
            printf("The natural logarithm of %f is %f\n",a,result);
            break;

        case 4:
            printf("Enter an angle in degrees to find its sine value: ");
            scanf("%f",&degree);
            radian = degree * (M_PI / 180);
            result = sin(radian);
            printf("The sine of %f degrees is %f\n",degree,result);
            break;

        case 5:
            printf("Enter an angle in degrees to find its cosine value: ");
            scanf("%f",&degree);
            radian = degree * (M_PI / 180);
            result = cos(radian);
            printf("The cosine of %f degrees is %f\n",degree,result);
            break;

        case 6:
            printf("Enter an angle in degrees to find its tangent value: ");
            scanf("%f",&degree);
            radian = degree * (M_PI / 180);
            result = tan(radian);
            printf("The tangent of %f degrees is %f\n",degree,result);
            break;

        default:
            printf("Invalid choice. Please select a number between 1 and 6.\n");
    }

    return 0;
}