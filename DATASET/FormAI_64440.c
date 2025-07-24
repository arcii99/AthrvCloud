//FormAI DATASET v1.0 Category: Temperature Converter ; Style: immersive
#include<stdio.h>

int main(){
    float celsius, fahrenheit;
    int choice;
    
    /* Introduction */
    printf("\n\n\t<< Temperature Converter >>\n\n");
    printf("Find out the equivalent temperature in Celsius or Fahrenheit\n");
    
    /* Menu */
    printf("Please select an option\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);
    
    /* Temperature Input */
    if(choice == 1){
        printf("Please enter a temperature in Celsius: ");
        scanf("%f", &celsius);
        /* Conversion Formula */
        fahrenheit = (celsius * 9/5) + 32;
        printf("The equivalent temperature is %.2f Fahrenheit\n", fahrenheit);
    }
    else if(choice == 2){
        printf("Please enter a temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        /* Conversion Formula */
        celsius = (fahrenheit - 32) * 5/9;
        printf("The equivalent temperature is %.2f Celsius\n", celsius);
    }
    else{
        printf("Invalid option selected\n");
    }
    
    return 0;
}