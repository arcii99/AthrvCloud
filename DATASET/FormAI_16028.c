//FormAI DATASET v1.0 Category: Temperature Converter ; Style: excited
#include<stdio.h>

int main(){
    int choice; 
    float f,c;
    printf("Welcome to the Temperature Converter! \n");
    printf("This program will help you convert temperatures between Fahrenheit and Celsius. \n");
    printf("Please enter 1 if you would like to convert from Fahrenheit to Celsius and 2 if you would like to convert from Celsius to Fahrenheit: \n");
    scanf("%d",&choice);
    if(choice==1){
        printf("Great! You have chosen to convert from Fahrenheit to Celsius. \n");
        printf("Please enter the temperature in Fahrenheit: \n");
        scanf("%f",&f);
        c=(f-32)*5/9;
        printf("The temperature in Celsius is: %f \n",c);
        printf("Thank you for using the Temperature Converter! \n");

    }
    else if(choice==2){
        printf("Awesome! You have chosen to convert from Celsius to Fahrenheit. \n");
        printf("Please enter the temperature in Celsius: \n");
        scanf("%f",&c);
        f=(c*9/5)+32;
        printf("The temperature in Fahrenheit is: %f \n",f);
        printf("Thank you for using the Temperature Converter! \n");

    }
    else{
        printf("Oops! Looks like you have entered an incorrect choice. Please enter either 1 or 2. \n");
        main();
    }
    return 0; 
}