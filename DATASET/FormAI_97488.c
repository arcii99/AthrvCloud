//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int choice;
    float num, ans;
   
    printf("\t\tWelcome to the Puzzling Scientific Calculator\n");
    printf("============================================================\n");
    printf("\n 1) Square Root       2) Cube Root        3) Power of 2 \n 4) Natural Logarithm  5) Base 10 Logarithm 6) Sine \n 7) Cosine             8) Tangent          9) Exit \n");
    printf("\n============================================================\n");

    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter a number to find the square root: ");
                scanf("%f", &num);
                ans = sqrt(num);
                printf("The square root of %f is %f\n", num, ans);
                break;

            case 2:
                printf("Enter a number to find the cube root: ");
                scanf("%f", &num);
                ans = cbrt(num);
                printf("The cube root of %f is %f\n", num, ans);
                break;

            case 3:
                printf("Enter a number to raise to the power of 2: ");
                scanf("%f", &num);
                ans = pow(num, 2);
                printf("%f raised to the power of 2 is %f\n", num, ans);
                break;

            case 4:
                printf("Enter a number for natural logarithm: ");
                scanf("%f", &num);
                ans = log(num);
                printf("ln(%f) is %f\n", num, ans);
                break;

            case 5:
                printf("Enter a number for base 10 logarithm: ");
                scanf("%f", &num);
                ans = log10(num);
                printf("log(%f) is %f\n", num, ans);
                break;

            case 6:
                printf("Enter the angle in degrees: ");
                scanf("%f", &num);
                ans = sin(num);
                printf("The sine of %f degrees is %f\n", num, ans);
                break;

            case 7:
                printf("Enter the angle in degrees: ");
                scanf("%f", &num);
                ans = cos(num);
                printf("The cosine of %f degrees is %f\n", num, ans);
                break;

            case 8:
                printf("Enter the angle in degrees: ");
                scanf("%f", &num);
                ans = tan(num);
                printf("The tangent of %f degrees is %f\n", num, ans);
                break;

            case 9:
                printf("Exiting the program!\n");
                exit(0);

            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}