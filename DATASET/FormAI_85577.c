//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// function prototypes
int mainMenu();
double addition();
double subtraction();
double multiplication();
double division();
double power();
double squareRoot();
double absolute();


int main(){
    int choice;
    printf("\t\t***SCIENTIFIC CALCULATOR***\n");
    do{
        choice = mainMenu();
        
        switch(choice){
            case 1:{
                double result = addition();
                printf("The result is: %.2lf\n\n", result);
                break;
            }
            case 2:{
                double result = subtraction();
                printf("The result is: %.2lf\n\n", result);
                break;
            }
            case 3:{
                double result = multiplication();
                printf("The result is: %.2lf\n\n", result);
                break;
            }
            case 4:{
                double result = division();
                printf("The result is: %.2lf\n\n", result);
                break;
            }
            case 5:{
                double result = power();
                printf("The result is: %.2lf\n\n", result);
                break;
            }
            case 6:{
                double result = squareRoot();
                printf("The result is: %.2lf\n\n", result);
                break;
            }
            case 7:{
                double result = absolute();
                printf("The result is: %.2lf\n\n", result);
                break;
            }
            case 8:{
                printf("Thank you for using the Scientific Calculator :)\n");
                break;
            }
            default:{
                printf("Invalid choice, please try again!\n");
                break;
            }
        }
    }while(choice != 8);
    
    return 0;
}

int mainMenu(){
    int choice;
    printf("Please choose an operation:\n");
    printf("\t1. Addition\n");
    printf("\t2. Subtraction\n");
    printf("\t3. Multiplication\n");
    printf("\t4. Division\n");
    printf("\t5. Power (a^b)\n");
    printf("\t6. Square Root\n");
    printf("\t7. Absolute value\n");
    printf("\t8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

double addition(){
    int n;
    printf("Enter how many numbers you want to add: ");
    scanf("%d", &n);
    double result = 0, num;
    printf("Enter the numbers:\n");
    for (int i = 1; i <= n; i++){
        scanf("%lf", &num);
        result += num;
    }
    return result;
}

double subtraction(){
    double n1, n2;
    printf("Enter two numbers to subtract:\n");
    scanf("%lf %lf", &n1, &n2);
    return n1 - n2;
}

double multiplication(){
    int n;
    printf("Enter how many numbers you want to multiply: ");
    scanf("%d", &n);
    double result = 1, num;
    printf("Enter the numbers:\n");
    for (int i = 1; i <= n; i++){
        scanf("%lf", &num);
        result *= num;
    }
    return result;
}

double division(){
    double n1, n2;
    printf("Enter two numbers to divide:\n");
    scanf("%lf %lf", &n1, &n2);
    if (n2 != 0){
        return n1/n2;
    }
    else{
        printf("Error: Division by zero!\n");
        return 0;
    }
}

double power(){
    double base, exponent;
    printf("Enter base number and exponent:\n");
    scanf("%lf %lf", &base, &exponent);
    return pow(base, exponent);
}

double squareRoot(){
    double num;
    printf("Enter number to find square root:\n");
    scanf("%lf", &num);
    if (num >= 0){
        return sqrt(num);
    }
    else{
        printf("Error: Invalid input!\n");
        return 0;
    }
}

double absolute(){
    double num;
    printf("Enter number to find absolute value:\n");
    scanf("%lf", &num);
    return fabs(num);
}