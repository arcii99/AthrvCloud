//FormAI DATASET v1.0 Category: Unit converter ; Style: lively
#include<stdio.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius){
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit){
    return (fahrenheit - 32) * 5/9;
}

// Function to convert Centimeters to Inches
float cm_to_inches(float cm){
    return cm / 2.54;
}

// Function to convert Inches to Centimeters
float inches_to_cm(float inches){
    return inches * 2.54;
}

// Function to convert Kilometers to Miles
float km_to_miles(float km){
    return km / 1.609;
}

// Function to convert Miles to Kilometers
float miles_to_km(float miles){
    return miles * 1.609;
}

// Main Function
int main(){
    int choice;
    float value, result;
    printf("Welcome to the Unit Converter Program!\n");

    while(1){
        printf("\nPlease select the conversion type:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Centimeters to Inches\n");
        printf("4. Inches to Centimeters\n");
        printf("5. Kilometers to Miles\n");
        printf("6. Miles to Kilometers\n");
        printf("7. Exit\n");
        scanf("%d", &choice);

        if(choice == 7){
            printf("\nThank you for using the Unit Converter Program!\n");
            break;
        }

        printf("Enter the value to be converted: ");
        scanf("%f", &value);

        switch(choice){
            case 1:
                result = celsius_to_fahrenheit(value);
                printf("%.2f Celsius = %.2f Fahrenheit\n", value, result);
                break;

            case 2:
                result = fahrenheit_to_celsius(value);
                printf("%.2f Fahrenheit = %.2f Celsius\n", value, result);
                break;

            case 3:
                result = cm_to_inches(value);
                printf("%.2f Centimeters = %.2f Inches\n", value, result);
                break;

            case 4:
                result = inches_to_cm(value);
                printf("%.2f Inches = %.2f Centimeters\n", value, result);
                break;

            case 5:
                result = km_to_miles(value);
                printf("%.2f Kilometers = %.2f Miles\n", value, result);
                break;

            case 6:
                result = miles_to_km(value);
                printf("%.2f Miles = %.2f Kilometers\n", value, result);
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}