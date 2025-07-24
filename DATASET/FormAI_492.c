//FormAI DATASET v1.0 Category: Temperature monitor ; Style: curious
#include <stdio.h>

int main() {
    printf("Welcome to the Temperature Monitor Program!\n");
    printf("We are curious to know the temperature around you.\n");

    float temp_c, temp_f;

    printf("Please enter the temperature in Celsius: ");
    scanf("%f", &temp_c);

    temp_f = (temp_c * 9/5) + 32;

    printf("\nWow! That's %.2f degrees Fahrenheit!\n", temp_f);

    if (temp_f <= 32) {
        printf("\nBrrr! That's freezing cold. Bundle up!\n");
    } else if (temp_f > 32 && temp_f <= 50) {
        printf("\nIt's chilly outside. Don't forget your coat!\n");
    } else if (temp_f > 50 && temp_f <= 70) {
        printf("\nIt's comfortable outside. Enjoy the weather!\n");
    } else if (temp_f > 70 && temp_f <= 85) {
        printf("\nIt's warm today. Wear something light!\n");
    } else {
        printf("\nIt's hot today! Stay cool!\n");
    }

    printf("\nThank you for using the Temperature Monitor. Stay curious!\n");

    return 0;
}