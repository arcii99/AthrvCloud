//FormAI DATASET v1.0 Category: Temperature Converter ; Style: secure
#include <stdio.h>

float convertFtoC(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

float convertCtoF(float celsius) {
    return celsius * 9/5 + 32;
}

int main() {
    char choice;
    float temp;

    printf("Enter temperature: ");
    scanf("%f", &temp);

    printf("Convert from Fahrenheit to Celsius (F) or from Celsius to Fahrenheit (C)? ");
    scanf(" %c", &choice);

    if(choice == 'F' || choice == 'f') {
        printf("%.2f degrees Fahrenheit is %.2f degrees Celsius\n", temp, convertFtoC(temp));
    }
    else if(choice == 'C' || choice == 'c') {
        printf("%.2f degrees Celsius is %.2f degrees Fahrenheit\n", temp, convertCtoF(temp));
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}