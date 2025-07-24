//FormAI DATASET v1.0 Category: Calculator ; Style: inquisitive
#include<stdio.h>

int main(){

//Initializing variables
int num1, num2, option, answer;

//Displaying menu
printf("Welcome to calculator program!\n");
printf("Please select an option:\n");
printf("1. Addition\n");
printf("2. Subtraction\n");
printf("3. Multiplication\n");
printf("4. Division\n");
printf("Enter your choice: ");
scanf("%d", &option);

//Taking user input
printf("Enter first number: ");
scanf("%d", &num1);
printf("Enter second number: ");
scanf("%d", &num2);

//Performing calculation based on user input
switch(option){
case 1:
    answer = num1 + num2;
    printf("The sum of %d and %d is %d.", num1, num2, answer);
    break;
case 2:
    answer = num1 - num2;
    printf("The difference of %d and %d is %d.", num1, num2, answer);
    break;
case 3:
    answer = num1 * num2;
    printf("The product of %d and %d is %d.", num1, num2, answer);
    break;
case 4:
    //Handling division by zero
    if(num2 == 0){
        printf("Cannot divide by zero.");
    }else{
        answer = num1 / num2;
        printf("The quotient of %d divided by %d is %d.", num1, num2, answer);
    }
    break;
default:
    printf("Invalid option selected.");
}

return 0;
}