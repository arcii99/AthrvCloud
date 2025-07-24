//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265358979323846

int main(){
    int choice, num;
    double angle, result;

    while(1){
        printf("\nWelcome to the Scientific Calculator\n\n");
        printf("1. Trigonometric Sin\n");
        printf("2. Trigonometric Cos\n");
        printf("3. Trigonometric Tan\n");
        printf("4. Inverse Trigonometric Sin\n");
        printf("5. Inverse Trigonometric Cos\n");
        printf("6. Inverse Trigonometric Tan\n");
        printf("7. Natural Logarithm\n");
        printf("8. Logarithm to base 10\n");
        printf("9. Square Root\n");
        printf("10. Cube Root\n");
        printf("11. Exponential Function\n");
        printf("12. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 12)
            break;

        switch(choice){
            case 1:
                printf("Enter angle in radians: ");
                scanf("%lf", &angle);
                result = sin(angle);
                printf("%.3lf\n", result);
                break;
            case 2:
                printf("Enter angle in radians: ");
                scanf("%lf", &angle);
                result = cos(angle);
                printf("%.3lf\n", result);
                break;
            case 3:
                printf("Enter angle in radians: ");
                scanf("%lf", &angle);
                result = tan(angle);
                printf("%.3lf\n", result);
                break;
            case 4:
                printf("Enter a value between -1 to 1: ");
                scanf("%lf", &num);
                result = asin(num);
                printf("%.3lf\n", result);
                break;
            case 5:
                printf("Enter a value between -1 to 1: ");
                scanf("%lf", &num);
                result = acos(num);
                printf("%.3lf\n", result);
                break;
            case 6:
                printf("Enter a value: ");
                scanf("%lf", &num);
                result = atan(num);
                printf("%.3lf\n", result);
                break;
            case 7:
                printf("Enter a value: ");
                scanf("%lf", &num);
                result = log(num);
                printf("%.3lf\n", result);
                break;
            case 8:
                printf("Enter a value: ");
                scanf("%lf", &num);
                result = log10(num);
                printf("%.3lf\n", result);
                break;
            case 9:
                printf("Enter a value: ");
                scanf("%lf", &num);
                result = sqrt(num);
                printf("%.3lf\n", result);
                break;
            case 10:
                printf("Enter a value: ");
                scanf("%lf", &num);
                result = cbrt(num);
                printf("%.3lf\n", result);
                break;
            case 11:
                printf("Enter a value: ");
                scanf("%lf", &num);
                result = exp(num);
                printf("%.3lf\n", result);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    printf("Goodbye!\n");
    return 0;
}