//FormAI DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <string.h>

int main() {
    char units[][50] = {"meter", "kilometer", "inch", "yard", "mile"};
    double conversion_rates[5][5] = {
        {1, 0.001, 39.3701, 1.09361, 0.000621371},
        {1000, 1, 39370.1, 1093.61, 0.621371},
        {0.0254, 0.0000254, 1, 0.0277778, 0.0000157828},
        {0.9144, 0.0009144, 36, 1, 0.000568182},
        {1609.34, 1.60934, 63360, 1760, 1}
    };
    int input_unit, output_unit;
    double input_value, output_value;
    
    printf("Which unit would you like to convert from?\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i+1, units[i]);
    }
    scanf("%d", &input_unit);
    
    printf("Enter the value to convert:\n");
    scanf("%lf", &input_value);
    
    printf("Which unit would you like to convert to?\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i+1, units[i]);
    }
    scanf("%d", &output_unit);
    
    // Convert to base unit (meter)
    double base_value = input_value / conversion_rates[input_unit-1][0];
    
    // Convert from base unit to output unit
    output_value = base_value * conversion_rates[output_unit-1][0];
    
    printf("%.2f %s is equal to %.2f %s\n", input_value, units[input_unit-1], output_value, units[output_unit-1]);
    
    return 0;
}