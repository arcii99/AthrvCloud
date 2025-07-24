//FormAI DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

int main()
{
    float cel, far; //variable declaration for celsius and fahrenheit
    int choice; //variable declaration for user choice
    
    printf("Welcome to the Temperature Converter!\n\n");
    
    do{
        printf("Enter a choice:\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Exit\n\n");
        scanf("%d",&choice); // taking user's choice
        
        switch(choice){
            case 1:
                printf("Enter Temperature in Celsius: ");
                scanf("%f", &cel); //taking temperature in Celsius from user
                far = (cel  * 9 / 5) + 32; //converting temperature from Celsius to Fahrenheit
                printf("\n%.2f degree Celsius = %.2f degree Fahrenheit\n\n", cel, far); //displaying the results
                break;
            case 2:
                printf("Enter Temperature in Fahrenheit: ");
                scanf("%f", &far); //taking temperature in Fahrenheit from user
                cel = (far - 32) * 5 / 9; //converting temperature from Fahrenheit to Celsius
                printf("\n%.2f degree Fahrenheit = %.2f degree Celsius\n\n", far, cel); //displaying the results
                break;
            case 3:
                printf("Thank you for using Temperature Converter. Goodbye!\n");
                exit(0); //exiting from the program
            default:
                printf("Invalid Choice! Please Try Again.\n\n"); //displaying error message for invalid input
        }
    }while(choice!=3); //program runs until user wants to exit
    
    return 0;
}