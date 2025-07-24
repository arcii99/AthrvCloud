//FormAI DATASET v1.0 Category: Temperature Converter ; Style: excited
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Are you ready to convert Celsius to Fahrenheit? (Y/N)\n");
    char input;
    scanf("%c",&input);
    if (input == 'Y'){
    printf("Awesome! Let's get started!\n");
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    printf("Wasn't that easy? Do you want to convert another temperature? (Y/N)\n");
        } else {
            printf("Oh no! Don't worry though, you can always come back later!\n");
            return 0;
            }
    while(1){
    char ans;
    scanf(" %c", &ans);
    if(ans == 'Y' || ans == 'y'){
        printf("Great! Please enter the temperature in Celsius: ");
        float celsius, fahrenheit;
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9/5) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
        printf("Do you want to convert another temperature? (Y/N)\n");
    }else if(ans == 'N' || ans == 'n'){
        printf("Okay! Thanks for trying out my Celsius to Fahrenheit Converter!\n");
        return 0;
    }else{
        printf("Invalid input! Please enter either Y or N: ");
    }
}
return 0;
}