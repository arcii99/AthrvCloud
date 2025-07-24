//FormAI DATASET v1.0 Category: Unit converter ; Style: recursive
#include <stdio.h>

void convert(int num, char unit[]) {
    char *units[] = {"Celsius", "Fahrenheit", "Meters", "Feet", "Kilograms", "Pounds"};
    float conversions[][2] = {{num, num * 9/5 + 32}, {num, (num - 32) * 5/9}, {num, num * 3.28084}, {num, num / 3.28084}, {num, num * 2.20462}, {num, num / 2.20462}};

    int unitIndex = -1;
    for(int i = 0; i < 6; i++) {
        if(strcmp(unit, units[i]) == 0) {
            unitIndex = i;
            break;
        }
    }

    if(unitIndex == -1) {
        printf("Invalid unit. Please try again with a valid unit.");
        return;
    }

    printf("%.2f %s is equivalent to %.2f %s\n", conversions[unitIndex][0], units[unitIndex], conversions[unitIndex][1], units[(unitIndex + 1) % 6]);
    convert(conversions[unitIndex][1], units[(unitIndex + 1) % 6]);
}

int main() {
    int num;
    char unit[20];

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Enter its unit (Celsius, Fahrenheit, Meters, Feet, Kilograms, or Pounds): ");
    scanf("%s", unit);

    convert(num, unit);

    return 0;
}