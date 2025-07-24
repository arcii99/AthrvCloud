//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: future-proof
#include<stdio.h>
#include<math.h>

void add(int num1, int num2);
void subtract(int num1, int num2);
void multiply(int num1, int num2);
void divide(int num1, int num2);
void power(int num1, int num2);
void modulus(int num1, int num2);
void squareRoot(int num);
void square(int num);
void cube(int num);
void factorial(int num);

int main(){
    int option, num1, num2;
    printf("Welcome to the Scientific Calculator\n");

    do{
        printf("\nPlease choose an option from the menu below:");
        printf("\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Power\n6. Modulus\n7. Square Root\n8. Square\n9. Cube\n10. Factorial\n0. Exit\n");
        scanf("%d", &option);

        switch(option){
            case 1:{
                printf("\nEnter the first number: ");
                scanf("%d", &num1);
                printf("\nEnter the second number: ");
                scanf("%d", &num2);
                add(num1, num2);
                break;
            }
            case 2:{
                printf("\nEnter the first number: ");
                scanf("%d", &num1);
                printf("\nEnter the second number: ");
                scanf("%d", &num2);
                subtract(num1, num2);
                break;
            }
            case 3:{
                printf("\nEnter the first number: ");
                scanf("%d", &num1);
                printf("\nEnter the second number: ");
                scanf("%d", &num2);
                multiply(num1, num2);
                break;
            }
            case 4:{
                printf("\nEnter the first number: ");
                scanf("%d", &num1);
                printf("\nEnter the second number: ");
                scanf("%d", &num2);
                divide(num1, num2);
                break;
            }
            case 5:{
                printf("\nEnter the base number: ");
                scanf("%d", &num1);
                printf("\nEnter the power number: ");
                scanf("%d", &num2);
                power(num1, num2);
                break;
            }
            case 6:{
                printf("\nEnter the first number: ");
                scanf("%d", &num1);
                printf("\nEnter the second number: ");
                scanf("%d", &num2);
                modulus(num1, num2);
                break;
            }
            case 7:{
                printf("\nEnter the number: ");
                scanf("%d", &num1);
                squareRoot(num1);
                break;
            }
            case 8:{
                printf("\nEnter the number: ");
                scanf("%d", &num1);
                square(num1);
                break;
            }
            case 9:{
                printf("\nEnter the number: ");
                scanf("%d", &num1);
                cube(num1);
                break;
            }
            case 10:{
                printf("\nEnter the number: ");
                scanf("%d", &num1);
                factorial(num1);
                break;
            }
            case 0:{
                printf("\nThank you for using the calculator!\n");
                exit(0);
            }
            default:{
                printf("\nInvalid option, please try again.\n");
                break;
            }
        }
    }while(option != 0);

    return 0;
}

void add(int num1, int num2){
    printf("\n%d + %d = %d\n", num1, num2, num1+num2);
}

void subtract(int num1, int num2){
    printf("\n%d - %d = %d\n", num1, num2, num1-num2);
}

void multiply(int num1, int num2){
    printf("\n%d * %d = %d\n", num1, num2, num1*num2);
}

void divide(int num1, int num2){
    printf("\n%d / %d = %d\n", num1, num2, num1/num2);
}

void power(int num1, int num2){
    printf("\n%d ^ %d = %lf\n", num1, num2, pow(num1, num2));
}

void modulus(int num1, int num2){
    printf("\n%d %% %d = %d\n", num1, num2, num1%num2);
}

void squareRoot(int num){
    printf("\nSquare root of %d = %lf\n", num, sqrt(num));
}

void square(int num){
    printf("\n%d ^ 2 = %d\n", num, num*num);
}

void cube(int num){
    printf("\n%d ^ 3 = %d\n", num, num*num*num);
}

void factorial(int num){
    int fact = 1;
    for(int i = 1; i <= num; i++){
        fact *= i;
    }
    printf("\n%d! = %d\n", num, fact);
}