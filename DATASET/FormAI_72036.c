//FormAI DATASET v1.0 Category: Unit converter ; Style: Ada Lovelace
// Unit Converter: Celsius to Fahrenheit

#include <stdio.h> // Header File for Standard Input/Output Operations

/*
 * Main Function
 */
int main()
{
    /*
     * Variable Declaration
     */
    float celsius, fahrenheit;
    
    /*
     * Input from user
     */
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    /*
     * Conversion Formula
     */
    fahrenheit = (celsius * 9 / 5) + 32;
    
    /*
     * Output
     */
    printf("%0.2f degree Celsius is equal to %0.2f degree Fahrenheit.", celsius, fahrenheit);
    
    /*
     * End of Main Function
     */
    return 0;
}