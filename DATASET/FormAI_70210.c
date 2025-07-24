//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int choice;
    double num1, num2, ans;
    printf("Welcome to the Scientific Calculator\n\n");

    do{
        printf("Please select an operation:\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exponentiation (x^y)\n");
        printf("6. Square Root (√)\n");
        printf("7. Absolute Value (|x|)\n");
        printf("8. Logarithm (log base 10)\n");
        printf("9. Sine (sin)\n");
        printf("10. Cosine (cos)\n");
        printf("11. Tangent (tan)\n");
        printf("12. Quit\n");

        scanf("%d", &choice);

        switch(choice){
        case 1:
            printf("Enter two numbers seperated by space: ");
            scanf("%lf %lf",&num1, &num2);
            ans = num1 + num2;
            printf("The sum of %.2lf and %.2lf is %.2lf\n\n", num1, num2, ans);
            break;

        case 2:
            printf("Enter two numbers seperated by space: ");
            scanf("%lf %lf",&num1, &num2);
            ans = num1 - num2;
            printf("The difference between %.2lf and %.2lf is %.2lf\n\n", num1, num2, ans);
            break;

        case 3:
            printf("Enter two numbers seperated by space: ");
            scanf("%lf %lf",&num1, &num2);
            ans = num1 * num2;
            printf("The product of %.2lf and %.2lf is %.2lf\n\n", num1, num2, ans);
            break;

        case 4:
            printf("Enter two numbers seperated by space: ");
            scanf("%lf %lf",&num1, &num2);
            ans = num1 / num2;
            printf("The quotient of %.2lf and %.2lf is %.2lf\n\n", num1, num2, ans);
            break;

        case 5:
            printf("Enter two numbers seperated by space (x y): ");
            scanf("%lf %lf",&num1, &num2);
            ans = pow(num1,num2);
            printf("%.2lf raised to the power of %.2lf is %.2lf\n\n", num1, num2, ans);
            break;

        case 6:
            printf("Enter a number: ");
            scanf("%lf",&num1);
            if(num1<0){
                printf("The square root of a negative number is undefined.\n\n");
            }
            else{
                ans = sqrt(num1);
                printf("The square root of %.2lf is %.2lf\n\n", num1, ans);
            }
            break;

        case 7:
            printf("Enter a number: ");
            scanf("%lf",&num1);
            ans = fabs(num1);
            printf("The absolute value of %.2lf is %.2lf\n\n", num1, ans);
            break;

        case 8:
            printf("Enter a number: ");
            scanf("%lf",&num1);
            if(num1<=0){
                printf("Log(a) is undefined for a<=0. Please enter a positive number.\n\n");
            }
            else{
                ans = log10(num1);
                printf("The logarithm (base 10) of %.2lf is %.2lf\n\n", num1, ans);
            }
            break;

        case 9:
            printf("Enter an angle in degrees: ");
            scanf("%lf",&num1);
            ans = sin(num1*M_PI/180.0);
            printf("%.2lf degrees is equal to %.2lf radians.\n", num1, num1*M_PI/180.0);
            printf("The sine of %.2lf degrees is %.2lf\n\n", num1, ans);
            break;

        case 10:
            printf("Enter an angle in degrees: ");
            scanf("%lf",&num1);
            ans = cos(num1*M_PI/180.0);
            printf("%.2lf degrees is equal to %.2lf radians.\n", num1, num1*M_PI/180.0);
            printf("The cosine of %.2lf degrees is %.2lf\n\n", num1, ans);
            break;

        case 11:
            printf("Enter an angle in degrees: ");
            scanf("%lf",&num1);
            ans = tan(num1*M_PI/180.0);
            printf("%.2lf degrees is equal to %.2lf radians.\n", num1, num1*M_PI/180.0);
            printf("The tangent of %.2lf degrees is %.2lf\n\n", num1, ans);
            break;

        case 12:
            printf("Goodbye!\n");
            exit(0);

        default:
            printf("Invalid operation. Please try again.\n\n");
            break;
        }

    }while(1);
    return 0;
}