//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    float r0, r1, r2, r3, temp;
    
    printf("Enter the value of R0: ");
    scanf("%f", &r0);
    
    printf("Enter the value of R1: ");
    scanf("%f", &r1);
    
    printf("Enter the value of R2: ");
    scanf("%f", &r2);
    
    printf("Enter the value of R3: ");
    scanf("%f", &r3);
    
    temp = (1 / ((log(r0 / r1) / 3435) + (1 / 298.15))) - 273.15;
    
    printf("\nTemperature: %f °C", temp);
    
    temp = -0.0307 * pow(r2, 2) + 18.412 * r2 - 288.88;
    
    printf("\nTemperature: %f °C", temp);
    
    temp = ((r2 - r3) / (r3 / 3950)) + (1 / (273.15 + 25));
    temp = 1 / temp - 273.15;
    
    printf("\nTemperature: %f °C", temp);
}