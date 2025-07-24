//FormAI DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include<stdio.h>

void main(){
    printf("##################################################\n");
    printf("#                                                #\n");
    printf("#      Welcome to Celsius Temperature Converter   #\n");
    printf("#                                                #\n");
    printf("##################################################\n");
    printf("\nInstructions: \n");
    printf("\t1.Enter a temperature in Celsius to convert to Fahrenheit\n");
    printf("\t2.Enter a temperature in Fahrenheit to convert to Celsius\n");
    printf("\t3.Enter any other number to exit the program.\n");
    int option;
    float temp;
    while(1){
        printf("\nEnter the option(1/2/3): ");
        scanf("%d",&option);
        if(option==1){
            printf("\nEnter The Temperature in Celsius: ");
            scanf("%f",&temp);
            float f =(9*temp)/5 + 32;
            printf("%0.2f Celsius is equal to %0.2f Fahrenheit.\n",temp,f);
        }
        else if(option==2){
            printf("\nEnter The Temperature in Fahrenheit: ");
            scanf("%f",&temp);
            float c = (5*(temp-32))/9;
            printf("%0.2f Fahrenheit is equal to %0.2f Celsius.\n",temp,c);
        }
        else{
            printf("\nThank you for using Celsius Temperature Converter.\nExiting...\n");
            break;
        }
    }
}