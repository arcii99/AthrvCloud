//FormAI DATASET v1.0 Category: Unit converter ; Style: shocked
/* This program converts temperature units from Celsius to Fahrenheit */

#include <stdio.h>

int main() {

    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // conversion formula
    fahrenheit = (celsius * 9/5) + 32;
    
    // check if temperature is below freezing point
    if (celsius <= 0) {
      printf("Warning: Temperature is below freezing point!\n");
    }
    
    // display result
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);

    return 0;
}