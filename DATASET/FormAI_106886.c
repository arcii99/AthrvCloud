//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include <stdio.h>

int main() {
    int celsius, fahrenheit;
    printf("Enter the temperature in Celsius: ");
    scanf("%d", &celsius);

    //Conversion formula
    fahrenheit = (celsius * 9/5) + 32;

    printf("%d Celsius is %d Fahrenheit\n", celsius, fahrenheit);

    return 0;
}