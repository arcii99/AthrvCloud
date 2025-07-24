//FormAI DATASET v1.0 Category: Temperature Converter ; Style: excited
#include<stdio.h>

int main(){
    float celsius, fahrenheit;
    int choice;
    printf("*****Temperature Converter*****\n");
    printf("1) Celsius to Fahrenheit\n2) Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1){
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9 / 5) + 32;
        printf("%f degree Celsius is equal to %f degree Fahrenheit.\n", celsius, fahrenheit);
    }
    else if(choice == 2){
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32) * 5 / 9;
        printf("%f degree Fahrenheit is equal to %f degree Celsius.\n", fahrenheit, celsius);
    }
    else{
        printf("Invalid choice! Please select 1 or 2.\n");
    }

    return 0;
}