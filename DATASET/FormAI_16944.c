//FormAI DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>

float convert(char* from, char* to, float value);

int main() {
    char from[10];
    char to[10];
    float value;
    float result;

    printf("Enter the unit to convert from: ");
    scanf("%s", from);

    printf("Enter the unit to convert to: ");
    scanf("%s", to);

    printf("Enter the value to convert: ");
    scanf("%f", &value);

    result = convert(from, to, value);

    printf("%f %s is %f %s \n", value, from, result, to);

    return 0;
}

float convert(char* from, char* to, float value) {
    if (strcmp(from, "cm") == 0 && strcmp(to, "in") == 0) {
        return value / 2.54;
    } else if (strcmp(from, "in") == 0 && strcmp(to, "cm") == 0) {
        return value * 2.54;
    } else if (strcmp(from, "m") == 0 && strcmp(to, "ft") == 0) {
        return value * 3.2808399;
    } else if (strcmp(from, "ft") == 0 && strcmp(to, "m") == 0) {
        return value / 3.2808399;
    } else if (strcmp(from, "kg") == 0 && strcmp(to, "lb") == 0) {
        return value * 2.20462262;
    } else if (strcmp(from, "lb") == 0 && strcmp(to, "kg") == 0) {
        return value / 2.20462262;
    } else {
        printf("Invalid units or conversion not possible \n");
        return 0;
    }
}