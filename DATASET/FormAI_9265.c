//FormAI DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>

int main() {

    char unitFrom, unitTo;
    float valueFrom, valueTo;

    printf("Enter the unit you want to convert from (C, F, K, cm, in): ");
    scanf("%c", &unitFrom);

    printf("Enter the unit you want to convert to (C, F, K, cm, in): ");
    scanf(" %c", &unitTo);

    printf("Enter the value you want to convert: ");
    scanf("%f", &valueFrom);

    if(unitFrom == unitTo) {
        valueTo = valueFrom;
    } else if(unitFrom == 'C' && unitTo == 'F') {
        valueTo = valueFrom * 1.8 + 32;
    } else if(unitFrom == 'F' && unitTo == 'C') {
        valueTo = (valueFrom - 32) / 1.8;
    } else if(unitFrom == 'C' && unitTo == 'K') {
        valueTo = valueFrom + 273.15;
    } else if(unitFrom == 'K' && unitTo == 'C') {
        valueTo = valueFrom - 273.15;
    } else if(unitFrom == 'in' && unitTo == 'cm') {
        valueTo = valueFrom * 2.54;
    } else if(unitFrom == 'cm' && unitTo == 'in') {
        valueTo = valueFrom / 2.54;
    } else {
        printf("Error: Invalid Units\n");
        return 1;
    }

    printf("%.2f %c = %.2f %c\n", valueFrom, unitFrom, valueTo, unitTo);

    return 0;
}