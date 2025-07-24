//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/* This is a C Scientific Calculator Program that enables the user to perform various mathematical calculations on integers and floating-point numbers. */

// function to display menu and get user choice
int displayMenu(){
    int choice;
    printf("\n\n------SCIENTIFIC CALCULATOR------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Square\n");
    printf("7. Cube\n");
    printf("8. Square root\n");
    printf("9. Exponent\n");
    printf("10. Logarithm\n");
    printf("11. Trigonometric Functions\n");
    printf("12. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to perform addition
float add(float num1, float num2){
    return num1 + num2;
}

// function to perform subtraction
float subtract(float num1, float num2){
    return num1 - num2;
}

// function to perform multiplication
float multiply(float num1, float num2){
    return num1 * num2;
}

// function to perform division
float divide(float num1, float num2){
    return num1 / num2;
}

// function to perform modulus
int modulo(int num1, int num2){
    return num1 % num2;
}

// function to perform square
float square(float num){
    return num * num;
}

// function to perform cube
float cube(float num){
    return num * num * num;
}

// function to perform square root
float squareRoot(float num){
    return sqrt(num);
}

// function to perform exponent
float exponent(float num1, float num2){
    return pow(num1, num2);
}

// function to perform logarithm
float logarithm(float num){
    return log10(num);
}

// function to perform trigonometric functions
void trigonometry(){
    float angle, radian, result;
    int choice;
    printf("\nEnter the angle in degrees: ");
    scanf("%f", &angle);
    radian = angle * (3.14156 / 180);
    printf("1. Sine\n2. Cosine\n3. Tangent\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            result = sin(radian);
            printf("Sine(%0.2f) = %0.2f", angle, result);
            break;
        case 2:
            result = cos(radian);
            printf("Cosine(%0.2f) = %0.2f", angle, result);
            break;
        case 3:
            result = tan(radian);
            printf("Tangent(%0.2f) = %0.2f", angle, result);
            break;
        default:
            printf("Invalid choice!");
    }
}

int main(){
    int choice, num1, num2;
    float answer, num3, num4;
    while(1){
        choice = displayMenu();
        switch(choice){
            case 1:
                printf("\nEnter two numbers (separated by space): ");
                scanf("%f %f", &num3, &num4);
                answer = add(num3, num4);
                printf("%0.2f + %0.2f = %0.2f", num3, num4, answer);
                break;
            case 2:
                printf("\nEnter two numbers (separated by space): ");
                scanf("%f %f", &num3, &num4);
                answer = subtract(num3, num4);
                printf("%0.2f - %0.2f = %0.2f", num3, num4, answer);
                break;
            case 3:
                printf("\nEnter two numbers (separated by space): ");
                scanf("%f %f", &num3, &num4);
                answer = multiply(num3, num4);
                printf("%0.2f * %0.2f = %0.2f", num3, num4, answer);
                break;
            case 4:
                printf("\nEnter two numbers (separated by space): ");
                scanf("%f %f", &num3, &num4);
                answer = divide(num3, num4);
                printf("%0.2f / %0.2f = %0.2f", num3, num4, answer);
                break;
            case 5:
                printf("\nEnter two numbers (separated by space): ");
                scanf("%d %d", &num1, &num2);
                answer = modulo(num1, num2);
                printf("%d %% %d = %d", num1, num2, answer);
                break;
            case 6:
                printf("\nEnter a number: ");
                scanf("%f", &num3);
                answer = square(num3);
                printf("Square of %0.2f = %0.2f", num3, answer);
                break;
            case 7:
                printf("\nEnter a number: ");
                scanf("%f", &num3);
                answer = cube(num3);
                printf("Cube of %0.2f = %0.2f", num3, answer);
                break;
            case 8:
                printf("\nEnter a number: ");
                scanf("%f", &num3);
                if(num3 < 0){
                    printf("Square root of negative number is not possible!");
                    break;
                }
                answer = squareRoot(num3);
                printf("Square root of %0.2f = %0.2f", num3, answer);
                break;
            case 9:
                printf("\nEnter two numbers (separated by space): ");
                scanf("%f %f", &num3, &num4);
                answer = exponent(num3, num4);
                printf("%0.2f ^ %0.2f = %0.2f", num3, num4, answer);
                break;
            case 10:
                printf("\nEnter a number: ");
                scanf("%f", &num3);
                if(num3 <= 0){
                    printf("Logarithm of number less than or equal to zero is not possible!");
                    break;
                }
                answer = logarithm(num3);
                printf("Logarithm of %0.2f = %0.2f", num3, answer);
                break;
            case 11:
                trigonometry();
                break;
            case 12:
                printf("\n\nThank you for using the calculator!");
                exit(0);
            default:
                printf("\nInvalid choice! Please choose a valid option.");
        }
    }
    return 0;
}