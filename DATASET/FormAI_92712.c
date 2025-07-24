//FormAI DATASET v1.0 Category: Temperature Converter ; Style: unmistakable
#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    //Ask the user to enter temperature in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    //Convert Celsius to Fahrenheit
    fahrenheit = (celsius * 9/5) + 32;

    //Display the result
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);

    return 0;
}

/*
Sample Output:
Enter temperature in Celsius: 25
25.00 Celsius = 77.00 Fahrenheit
*/