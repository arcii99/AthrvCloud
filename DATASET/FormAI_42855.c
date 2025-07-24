//FormAI DATASET v1.0 Category: Temperature monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>

typedef struct Temperature {
    float value;
    char unit[3];
} Temperature;

int main() {
    Temperature temp;
    printf("Welcome to the Temperature Monitor Program!\n\n");
    printf("Please enter a temperature value: ");
    scanf("%f", &temp.value);
    printf("Please enter the unit of the temperature (c, f, k): ");
    scanf("%s", temp.unit);
    
    if ((temp.unit[0] == 'c' && temp.unit[1] == '\0') || (temp.unit[0] == 'C' && temp.unit[1] == '\0')) {
        printf("The temperature is %.2f%s.\n", temp.value, temp.unit);
        if (temp.value >= 100) {
            printf("Caution: The temperature is at boiling point!\n");
        } else if (temp.value <= 0) {
            printf("Caution: The temperature is at freezing point!\n");
        }
    } else if ((temp.unit[0] == 'f' && temp.unit[1] == '\0') || (temp.unit[0] == 'F' && temp.unit[1] == '\0')) {
        temp.value = (temp.value - 32) * 5 / 9;
        printf("The temperature is %.2f%s.\n", temp.value, "C");
        if (temp.value >= 100) {
            printf("Caution: The temperature is at boiling point!\n");
        } else if (temp.value <= 0) {
            printf("Caution: The temperature is at freezing point!\n");
        }
    } else if ((temp.unit[0] == 'k' && temp.unit[1] == '\0') || (temp.unit[0] == 'K' && temp.unit[1] == '\0')) {
        temp.value = temp.value - 273.15;
        printf("The temperature is %.2f%s.\n", temp.value, "C");
        if (temp.value >= 100) {
            printf("Caution: The temperature is at boiling point!\n");
        } else if (temp.value <= 0) {
            printf("Caution: The temperature is at freezing point!\n");
        }
    } else {
        printf("Invalid unit entered. Please try again.\n");
        return 1;
    }
    
    return 0;
}