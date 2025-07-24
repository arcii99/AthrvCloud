//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Romeo and Juliet
// Romeo: My love, let me write a program for thee
// Juliet: Oh Romeo, what program dost thou write?
// Romeo: A Scientific Calculator, my dearest, to help us solve mathematical plights
// Juliet: How splendid! But how shall thy program be written?
// Romeo: Fear not, my love. With C, an elegant language, our code shall be smitten

#include<stdio.h>
#include<math.h>

int main(){
    int choice;
    float num1, num2, result;

    printf("My love, please select the operation thou dost desire:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square root\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("My love, please enter the first number: ");
            scanf("%f", &num1);
            printf("Thou hast entered %.2f, now enter the second number: ", num1);
            scanf("%f", &num2);
            result = num1 + num2;
            printf("The result of thy calculation is %.2f", result);
            break;

        case 2:
            printf("My love, please enter the first number: ");
            scanf("%f", &num1);
            printf("Thou hast entered %.2f, now enter the second number: ", num1);
            scanf("%f", &num2);
            result = num1 - num2;
            printf("The result of thy calculation is %.2f", result);
            break;

        case 3:
            printf("My love, please enter the first number: ");
            scanf("%f", &num1);
            printf("Thou hast entered %.2f, now enter the second number: ", num1);
            scanf("%f", &num2);
            result = num1 * num2;
            printf("The result of thy calculation is %.2f", result);
            break;

        case 4:
            printf("My love, please enter the first number: ");
            scanf("%f", &num1);
            printf("Thou hast entered %.2f, now enter the second number: ", num1);
            scanf("%f", &num2);
            result = num1 / num2;
            printf("The result of thy calculation is %.2f", result);
            break;

        case 5:
            printf("My love, please enter the first number: ");
            scanf("%f", &num1);
            printf("Thou hast entered %.2f, now enter the power to which thou dost desire to raise it: ", num1);
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("%.2f raised to the power of %.2f is equal to %.2f", num1, num2, result);
            break;

        case 6:
            printf("My love, please enter the number: ");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("The square root of %.2f is equal to %.2f", num1, result);
            break;

        default:
            printf("My love, thou hast entered an invalid choice. Please tryeth again");
    }

    return 0;
}