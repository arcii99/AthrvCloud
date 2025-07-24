//FormAI DATASET v1.0 Category: Unit converter ; Style: detailed
#include<stdio.h>
int main()
{
    char fromUnit[20], toUnit[20]; // to store the unit types
    float value, result; // to store the value to be converted and the converted result
    printf("Enter the value to be converted: ");
    scanf("%f", &value);
    printf("Enter the unit to convert from (km/m/cm/mm): ");
    scanf("%s", fromUnit);
    printf("Enter the unit to convert to (km/m/cm/mm): ");
    scanf("%s", toUnit);

    // conversion of kilometer unit
    if(strcmp(fromUnit, "km")==0 && strcmp(toUnit, "m")==0)
        result = value*1000;
    else if(strcmp(fromUnit, "km")==0 && strcmp(toUnit, "cm")==0)
        result = value*100000;
    else if(strcmp(fromUnit, "km")==0 && strcmp(toUnit, "mm")==0)
        result = value*1000000;
    
    // conversion of meter unit
    else if(strcmp(fromUnit, "m")==0 && strcmp(toUnit, "km")==0)
        result = value/1000;
    else if(strcmp(fromUnit, "m")==0 && strcmp(toUnit, "cm")==0)
        result = value*100;
    else if(strcmp(fromUnit, "m")==0 && strcmp(toUnit, "mm")==0)
        result = value*1000;

    // conversion of centimeter unit
    else if(strcmp(fromUnit, "cm")==0 && strcmp(toUnit, "km")==0)
        result = value/100000;
    else if(strcmp(fromUnit, "cm")==0 && strcmp(toUnit, "m")==0)
        result = value/100;
    else if(strcmp(fromUnit, "cm")==0 && strcmp(toUnit, "mm")==0)
        result = value*10;

    // conversion of millimeter unit
    else if(strcmp(fromUnit, "mm")==0 && strcmp(toUnit, "km")==0)
        result = value/1000000;
    else if(strcmp(fromUnit, "mm")==0 && strcmp(toUnit, "m")==0)
        result = value/1000;
    else if(strcmp(fromUnit, "mm")==0 && strcmp(toUnit, "cm")==0)
        result = value/10;
    else
        printf("Invalid unit type");

    printf("%.2f %s is equal to %.2f %s", value, fromUnit, result, toUnit);
    return 0;
}