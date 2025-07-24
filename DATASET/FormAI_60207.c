//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Sherlock Holmes
#include <stdio.h>

int main() {

int temp_choice; //user choice for what type of temperature they are converting
float temp_val; //user input of temperature value
float converted_val; //temperature converted to desired type
char cont; //allow user to continue converting temperatures or not

printf("Welcome, dear friend. I see you are in need of a temperature conversion. Let us proceed with caution and proper consideration of the facts. \n");

do {
    printf("\n\nPlease select the type of temperature you are converting from. \n1. Celsius \n2. Fahrenheit \n3. Kelvin \n");
    scanf("%d", &temp_choice);
    printf("Please enter the temperature value: ");
    scanf("%f", &temp_val);

    switch(temp_choice) { //main switch statement for type of temperature being converted
        case 1: //Celsius to Fahrenheit and Kelvin
            converted_val = (temp_val * 1.8) + 32;
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit and %.2f Kelvin. \n", temp_val, converted_val, temp_val + 273.15);
            break;
        case 2: //Fahrenheit to Celsius and Kelvin
            converted_val = (temp_val - 32) / 1.8;
            printf("%.2f degrees Fahrenheit is %.2f degrees Celsius and %.2f Kelvin. \n", temp_val, converted_val, (converted_val + 273.15));
            break;
        case 3: //Kelvin to Celsius and Fahrenheit
            converted_val = temp_val - 273.15;
            printf("%.2f Kelvin is %.2f degrees Celsius and %.2f degrees Fahrenheit. \n", temp_val, converted_val, (converted_val * 1.8) + 32);
            break;
        default: //in case user input is invalid
            printf("I am afraid I cannot perform such a calculation. Please try again. \n");
            break;
    }

    printf("\nWould you like to continue with another temperature conversion? (y/n)"); //allow user to continue converting temperatures or not
    scanf(" %c", &cont);

} while(cont == 'y' || cont == 'Y');

printf("May your converted temperatures bring you clarity and understanding. Farewell. \n");

return 0;
}