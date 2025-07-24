//FormAI DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include<stdio.h>
#include<ctype.h>

int main() {
    char unit[10] = {'\0'};
    float value = 0, converted_value = 0;
    int convert_to = 0;
    printf("Welcome to the C Unit Converter program.\n");
    printf("Please enter the unit you want to convert from: ");
    scanf("%s", unit);
    printf("Please enter the value you want to convert: ");
    scanf("%f", &value);
    printf("Please select the unit you want to convert to:\n");
    printf("1. Centimeters.\n");
    printf("2. Meters.\n");
    printf("3. Kilometers.\n");
    printf("4. Inches.\n");
    printf("5. Feet.\n");
    printf("6. Yards.\n");
    printf("7. Miles.\n");
    printf("Enter the corresponding number: ");
    scanf("%d", &convert_to);
    switch(convert_to) {
        case 1:
            if(tolower(unit[0]) == 'm') {
                converted_value = value * 100;
            } else if(tolower(unit[0]) == 'k') {
                converted_value = value * 100000;
            } else if(tolower(unit[0]) == 'i') {
                converted_value = value * 2.54;
            } else if(tolower(unit[0]) == 'f') {
                converted_value = value * 30.48;
            } else if(tolower(unit[0]) == 'y') {
                converted_value = value * 91.44;
            } else if(tolower(unit[0]) == 'm') {
                converted_value = value * 160934;
            }
            break;
        case 2:
            if(tolower(unit[0]) == 'c') {
                converted_value = value / 100;
            } else if(tolower(unit[0]) == 'k') {
                converted_value = value * 1000;
            } else if(tolower(unit[0]) == 'i') {
                converted_value = value / 39.37;
            } else if(tolower(unit[0]) == 'f') {
                converted_value = value / 3.281;
            } else if(tolower(unit[0]) == 'y') {
                converted_value = value / 1.094;
            } else if(tolower(unit[0]) == 'm') {
                converted_value = value * 1609.34;
            }
            break;
        case 3:
            if(tolower(unit[0]) == 'c') {
                converted_value = value / 100000;
            } else if(tolower(unit[0]) == 'm') {
                converted_value = value / 1000;
            } else if(tolower(unit[0]) == 'i') {
                converted_value = value / 39370.1;
            } else if(tolower(unit[0]) == 'f') {
                converted_value = value / 3280.84;
            } else if(tolower(unit[0]) == 'y') {
                converted_value = value / 1093.61;
            } else if(tolower(unit[0]) == 'm') {
                converted_value = value * 1.60934;
            }
            break;
        case 4:
            if(tolower(unit[0]) == 'c') {
                converted_value = value / 2.54;
            } else if(tolower(unit[0]) == 'm') {
                converted_value = value * 39.37;
            } else if(tolower(unit[0]) == 'k') {
                converted_value = value * 39370.1;
            } else if(tolower(unit[0]) == 'f') {
                converted_value = value / 12;
            } else if(tolower(unit[0]) == 'y') {
                converted_value = value / 36;
            } else if(tolower(unit[0]) == 'm') {
                converted_value = value / 1609.34;
            }
            break;
        case 5:
            if(tolower(unit[0]) == 'c') {
                converted_value = value / 30.48;
            } else if(tolower(unit[0]) == 'm') {
                converted_value = value * 3.281;
            } else if(tolower(unit[0]) == 'k') {
                converted_value = value * 3280.84;
            } else if(tolower(unit[0]) == 'i') {
                converted_value = value * 12;
            } else if(tolower(unit[0]) == 'y') {
                converted_value = value / 3;
            } else if(tolower(unit[0]) == 'm') {
                converted_value = value / 1609.34;
            }
            break;
        case 6:
            if(tolower(unit[0]) == 'c') {
                converted_value = value / 91.44;
            } else if(tolower(unit[0]) == 'm') {
                converted_value = value * 1.094;
            } else if(tolower(unit[0]) == 'k') {
                converted_value = value * 1093.61;
            } else if(tolower(unit[0]) == 'i') {
                converted_value = value * 36;
            } else if(tolower(unit[0]) == 'f') {
                converted_value = value * 3;
            } else if(tolower(unit[0]) == 'm') {
                converted_value = value / 1609.34;
            }
            break;
        case 7:
            if(tolower(unit[0]) == 'c') {
                converted_value = value / 160934;
            } else if(tolower(unit[0]) == 'm') {
                converted_value = value / 1609.34;
            } else if(tolower(unit[0]) == 'k') {
                converted_value = value / 1.60934;
            } else if(tolower(unit[0]) == 'i') {
                converted_value = value / 63360;
            } else if(tolower(unit[0]) == 'f') {
                converted_value = value / 5280;
            } else if(tolower(unit[0]) == 'm') {
                converted_value = value / 1.60934;
            }
            break;
        default:
            printf("Invalid option selected.\n");
            break;
    }
    printf("%f %s is equal to %f ", value, unit, converted_value);
    switch(convert_to) {
        case 1:
            printf("centimeters.\n");
            break;
        case 2:
            printf("meters.\n");
            break;
        case 3:
            printf("kilometers.\n");
            break;
        case 4:
            printf("inches.\n");
            break;
        case 5:
            printf("feet.\n");
            break;
        case 6:
            printf("yards.\n");
            break;
        case 7:
            printf("miles.\n");
            break;
    }
    return 0;
}