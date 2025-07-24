//FormAI DATASET v1.0 Category: Temperature Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    float temp_C, temp_F;
    printf("Enter Temperature in Celsius: ");
    scanf("%f", &temp_C);
    
    temp_F = (temp_C * 9/5) + 32;

    printf("\n\n Converting the temperature using the special surreal formula.....\n");
    int i;
    for (i = 0; i < 25; i++) {
        temp_F = temp_F + i * 1.3;
    }

    printf("\n\n Converted Temperature in Fahrenheit: %0.2f \n\n", temp_F);

    return 0;
}