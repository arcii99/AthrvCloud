//FormAI DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>

int main() {
    int option;
    float valToConvert;
    float convertedVal;
    
    printf("------Unit Converter------\n\n");
    printf("Select the type of conversion:\n");
    printf("1. Distance\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Exit\n");
    
    scanf("%d", &option);
    
    if(option == 1) {
        printf("------Distance Converter------\n\n");
        printf("Select input unit:\n");
        printf("1. Meters\n");
        printf("2. Kilometers\n");
        printf("3. Miles\n");
        printf("4. Feet\n");
        
        int inputUnit;
        scanf("%d", &inputUnit);
        
        printf("Select output unit:\n");
        printf("1. Meters\n");
        printf("2. Kilometers\n");
        printf("3. Miles\n");
        printf("4. Feet\n");
        
        int outputUnit;
        scanf("%d", &outputUnit);
        
        printf("Enter value to convert: ");
        scanf("%f", &valToConvert);
        
        // Conversion logic
        if(inputUnit == 1) {
            if(outputUnit == 1) {
                convertedVal = valToConvert; // Meters to meters
            } else if(outputUnit == 2) {
                convertedVal = valToConvert / 1000; // Meters to kilometers
            } else if(outputUnit == 3) {
                convertedVal = valToConvert / 1609.34; // Meters to miles
            } else if(outputUnit == 4) {
                convertedVal = valToConvert * 3.28084; // Meters to feet
            }
        } else if(inputUnit == 2) {
            if(outputUnit == 1) {
                convertedVal = valToConvert * 1000; // Kilometers to meters
            } else if(outputUnit == 2) {
                convertedVal = valToConvert; // Kilometers to kilometers
            } else if(outputUnit == 3) {
                convertedVal = valToConvert / 1.60934; // Kilometers to miles
            } else if(outputUnit == 4) {
                convertedVal = valToConvert * 3280.84; // Kilometers to feet
            }
        } else if(inputUnit == 3) {
            if(outputUnit == 1) {
                convertedVal = valToConvert * 1609.34; // Miles to meters
            } else if(outputUnit == 2) {
                convertedVal = valToConvert * 1.60934; // Miles to kilometers
            } else if(outputUnit == 3) {
                convertedVal = valToConvert; // Miles to miles
            } else if(outputUnit == 4) {
                convertedVal = valToConvert * 5280; // Miles to feet
            }
        } else if(inputUnit == 4) {
            if(outputUnit == 1) {
                convertedVal = valToConvert / 3.28084; // Feet to meters
            } else if(outputUnit == 2) {
                convertedVal = valToConvert / 3280.84; // Feet to kilometers
            } else if(outputUnit == 3) {
                convertedVal = valToConvert / 5280; // Feet to miles
            } else if(outputUnit == 4) {
                convertedVal = valToConvert; // Feet to feet
            }
        }
        
        printf("Converted value: %f\n", convertedVal);
        
    } else if(option == 2) {
        printf("------Weight Converter------\n\n");
        printf("Select input unit:\n");
        printf("1. Kilograms\n");
        printf("2. Pounds\n");
        printf("3. Grams\n");
        printf("4. Ounces\n");
        
        int inputUnit;
        scanf("%d", &inputUnit);
        
        printf("Select output unit:\n");
        printf("1. Kilograms\n");
        printf("2. Pounds\n");
        printf("3. Grams\n");
        printf("4. Ounces\n");
        
        int outputUnit;
        scanf("%d", &outputUnit);
        
        printf("Enter value to convert: ");
        scanf("%f", &valToConvert);
        
        // Conversion logic
        if(inputUnit == 1) {
            if(outputUnit == 1) {
                convertedVal = valToConvert; // Kilograms to kilograms
            } else if(outputUnit == 2) {
                convertedVal = valToConvert * 2.20462; // Kilograms to pounds
            } else if(outputUnit == 3) {
                convertedVal = valToConvert * 1000; // Kilograms to grams
            } else if(outputUnit == 4) {
                convertedVal = valToConvert * 35.274; // Kilograms to ounces
            }
        } else if(inputUnit == 2) {
            if(outputUnit == 1) {
                convertedVal = valToConvert / 2.20462; // Pounds to kilograms
            } else if(outputUnit == 2) {
                convertedVal = valToConvert; // Pounds to pounds
            } else if(outputUnit == 3) {
                convertedVal = valToConvert * 453.592; // Pounds to grams
            } else if(outputUnit == 4) {
                convertedVal = valToConvert * 16; // Pounds to ounces
            }
        } else if(inputUnit == 3) {
            if(outputUnit == 1) {
                convertedVal = valToConvert / 1000; // Grams to kilograms
            } else if(outputUnit == 2) {
                convertedVal = valToConvert / 453.592; // Grams to pounds
            } else if(outputUnit == 3) {
                convertedVal = valToConvert; // Grams to grams
            } else if(outputUnit == 4) {
                convertedVal = valToConvert / 28.3495; // Grams to ounces
            }
        } else if(inputUnit == 4) {
            if(outputUnit == 1) {
                convertedVal = valToConvert / 35.274; // Ounces to kilograms
            } else if(outputUnit == 2) {
                convertedVal = valToConvert / 16; // Ounces to pounds
            } else if(outputUnit == 3) {
                convertedVal = valToConvert * 28.3495; // Ounces to grams
            } else if(outputUnit == 4) {
                convertedVal = valToConvert; // Ounces to ounces
            }
        }
        
        printf("Converted value: %f\n", convertedVal);
        
    } else if(option == 3) {
        printf("------Temperature Converter------\n\n");
        printf("Select input unit:\n");
        printf("1. Celsius\n");
        printf("2. Fahrenheit\n");
        printf("3. Kelvin\n");
        
        int inputUnit;
        scanf("%d", &inputUnit);
        
        printf("Select output unit:\n");
        printf("1. Celsius\n");
        printf("2. Fahrenheit\n");
        printf("3. Kelvin\n");
        
        int outputUnit;
        scanf("%d", &outputUnit);
        
        printf("Enter value to convert: ");
        scanf("%f", &valToConvert);
        
        // Conversion logic
        if(inputUnit == 1) {
            if(outputUnit == 1) {
                convertedVal = valToConvert; // Celsius to celsius
            } else if(outputUnit == 2) {
                convertedVal = (valToConvert * 1.8) + 32; // Celsius to fahrenheit
            } else if(outputUnit == 3) {
                convertedVal = valToConvert + 273.15; // Celsius to kelvin
            }
        } else if(inputUnit == 2) {
            if(outputUnit == 1) {
                convertedVal = (valToConvert - 32) / 1.8; // Fahrenheit to celsius
            } else if(outputUnit == 2) {
                convertedVal = valToConvert; // Fahrenheit to fahrenheit
            } else if(outputUnit == 3) {
                convertedVal = ((valToConvert - 32) / 1.8) + 273.15; // Fahrenheit to kelvin
            }
        } else if(inputUnit == 3) {
            if(outputUnit == 1) {
                convertedVal = valToConvert - 273.15; // Kelvin to celsius
            } else if(outputUnit == 2) {
                convertedVal = ((valToConvert - 273.15) * 1.8) + 32; // Kelvin to fahrenheit
            } else if(outputUnit == 3) {
                convertedVal = valToConvert; // Kelvin to kelvin
            }
        }
        
        printf("Converted value: %f\n", convertedVal);
        
    } else if(option == 4) {
        printf("Exiting...\n");
        return 0;
    } else {
        printf("Invalid option. Exiting...\n");
        return 0;
    }
    
    return 0;
}