//FormAI DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include <stdio.h> 

int main() 
{ 
    float temp;

    printf("Enter the temperature in Celsius: ");
    scanf("%f", &temp);

    if (temp < -273.15)
    {
        printf("Invalid input - temperature cannot be below absolute zero.\n");
    }
    else
    {
        printf("The temperature %.2f Celsius is equivalent to %.2f Fahrenheit and %.2f Kelvin.\n", temp, (temp * 9 / 5) + 32, temp + 273.15);
    }

    return 0; 
}