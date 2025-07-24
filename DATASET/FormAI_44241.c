//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: invasive
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    float a,b,c;

    printf("Enter the operation you want to perform: \n1: Addition \n2: Subtraction \n3: Multiplication \n4: Division \n5: Power \n6: Square Root \n7: Sine \n8: Cosine \n9: Tangent");
    scanf("%d",&choice);

    switch(choice) {
        case 1: {
            printf("Enter two numbers to add: ");
            scanf("%f%f",&a,&b);
            c = a + b;
            printf("%f + %f = %f",a,b,c);
            break;
        }
        case 2: {
            printf("Enter two numbers to subtract: ");
            scanf("%f%f",&a,&b);
            c = a - b;
            printf("%f - %f = %f",a,b,c);
            break;
        }
        case 3: {
            printf("Enter two numbers to multiply: ");
            scanf("%f%f",&a,&b);
            c = a * b;
            printf("%f * %f = %f",a,b,c);
            break;
        }
        case 4: {
            printf("Enter two numbers to divide: ");
            scanf("%f%f",&a,&b);
            c = a / b;
            printf("%f / %f = %f",a,b,c);
            break;
        }
        case 5: {
            printf("Enter the number and power to raise: ");
            scanf("%f%f",&a,&b);
            c = pow(a,b);
            printf("%f raised to power %f is %f",a,b,c);
            break;
        }
        case 6: {
            printf("Enter a number to find square root: ");
            scanf("%f",&a);
            c = sqrt(a);
            printf("The square root of %f is %f",a,c);
            break;
        }
        case 7: {
            printf("Enter the angle in degrees: ");
            scanf("%f",&a);
            c = sin(a*(3.141592/180));
            printf("The sine of %f is %f",a,c);
            break;
        }
        case 8: {
            printf("Enter the angle in degrees: ");
            scanf("%f",&a);
            c = cos(a*(3.141592/180));
            printf("The cosine of %f is %f",a,c);
            break;
        }
        case 9: {
            printf("Enter the angle in degrees: ");
            scanf("%f",&a);
            c = tan(a*(3.141592/180));
            printf("The tangent of %f is %f",a,c);
            break;
        }
        default: {
            printf("Invalid choice!");
        }
    }
    return 0;
}