//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//function declarations
double add(double, double);
double sub(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double squareRoot(double);
double cubeRoot(double);
double sine(double);
double cosine(double);
double tangent(double);
void displayMenu();


int main(){
    //variables to hold user input and result
    int choice;
    double num1, num2, result;

    do{
        displayMenu();
        printf("\nEnter your choice(1-10): ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%lf %lf", &num1, &num2);
                result = sub(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%lf %lf", &num1, &num2);
                if(num2 == 0){
                    printf("Cannot divide by zero\n");
                    break;
                }
                result = divide(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case 5:
                printf("Enter the base and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                result = power(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = squareRoot(num1);
                printf("Result: %.2f\n", result);
                break;
            case 7:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = cubeRoot(num1);
                printf("Result: %.2f\n", result);
                break;
            case 8:
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = sine(num1);
                printf("Result: %.2f\n", result);
                break;
            case 9:
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = cosine(num1);
                printf("Result: %.2f\n", result);
                break;
            case 10:
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = tangent(num1);
                printf("Result: %.2f\n", result);
                break;
            case 0:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice. Try again\n");
        }
    }while(1);

    return 0;
}

//function definitions
double add(double num1, double num2){
    return num1 + num2;
}

double sub(double num1, double num2){
    return num1 - num2;
}

double multiply(double num1, double num2){
    return num1 * num2;
}

double divide(double num1, double num2){
    return num1 / num2;
}

double power(double base, double exponent){
    return pow(base, exponent);
}

double squareRoot(double num){
    return sqrt(num);
}

double cubeRoot(double num){
    return cbrt(num);
}

double sine(double angle){
    double radians = angle * M_PI / 180.0;
    return sin(radians);
}

double cosine(double angle){
    double radians = angle * M_PI / 180.0;
    return cos(radians);
}

double tangent(double angle){
    double radians = angle * M_PI / 180.0;
    return tan(radians);
}

void displayMenu(){
    printf("Scientific Calculator\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Cube Root\n");
    printf("8. Sine\n");
    printf("9. Cosine\n");
    printf("10. Tangent\n");
    printf("0. Exit\n");
}