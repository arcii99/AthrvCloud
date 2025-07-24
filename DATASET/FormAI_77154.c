//FormAI DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>

int main() {
    int inputUnit, outputUnit, inputValue;
    float outputValue;

    printf("Enter the input unit:\n");
    printf("1. Meter\n");
    printf("2. Centimeter\n");
    printf("3. Kilometer\n");
    printf("4. Millimeter\n");
    printf("5. Micrometer\n");
    printf("6. Nanometer\n");
    scanf("%d", &inputUnit);

    printf("Enter the output unit:\n");
    printf("1. Meter\n");
    printf("2. Centimeter\n");
    printf("3. Kilometer\n");
    printf("4. Millimeter\n");
    printf("5. Micrometer\n");
    printf("6. Nanometer\n");
    scanf("%d", &outputUnit);

    printf("Enter the input value:\n");
    scanf("%d", &inputValue);

    if (inputUnit == 1 && outputUnit == 2) {
        outputValue = inputValue * 100;
    } else if (inputUnit == 1 && outputUnit == 3) {
        outputValue = inputValue / 1000;
    } else if (inputUnit == 1 && outputUnit == 4) {
        outputValue = inputValue * 1000;
    } else if (inputUnit == 1 && outputUnit == 5) {
        outputValue = inputValue * 1000000;
    } else if (inputUnit == 1 && outputUnit == 6) {
        outputValue = inputValue * 1000000000;
    } else if (inputUnit == 2 && outputUnit == 1) {
        outputValue = inputValue / 100;
    } else if (inputUnit == 2 && outputUnit == 3) {
        outputValue = inputValue / 100000;
    } else if (inputUnit == 2 && outputUnit == 4) {
        outputValue = inputValue * 10;
    } else if (inputUnit == 2 && outputUnit == 5) {
        outputValue = inputValue * 10000;
    } else if (inputUnit == 2 && outputUnit == 6) {
        outputValue = inputValue * 10000000;
    } else if (inputUnit == 3 && outputUnit == 1) {
        outputValue = inputValue * 1000;
    } else if (inputUnit == 3 && outputUnit == 2) {
        outputValue = inputValue * 100000;
    } else if (inputUnit == 3 && outputUnit == 4) {
        outputValue = inputValue * 1000000;
    } else if (inputUnit == 3 && outputUnit == 5) {
        outputValue = inputValue * 1000000000;
    } else if (inputUnit == 3 && outputUnit == 6) {
        outputValue = inputValue * 1000000000000;
    } else if (inputUnit == 4 && outputUnit == 1) {
        outputValue = inputValue / 1000;
    } else if (inputUnit == 4 && outputUnit == 2) {
        outputValue = inputValue / 10;
    } else if (inputUnit == 4 && outputUnit == 3) {
        outputValue = inputValue / 1000000;
    } else if (inputUnit == 4 && outputUnit == 5) {
        outputValue = inputValue * 1000;
    } else if (inputUnit == 4 && outputUnit == 6) {
        outputValue = inputValue * 1000000;
    } else if (inputUnit == 5 && outputUnit == 1) {
        outputValue = inputValue / 1000000;
    } else if (inputUnit == 5 && outputUnit == 2) {
        outputValue = inputValue / 10000;
    } else if (inputUnit == 5 && outputUnit == 3) {
        outputValue = inputValue / 1000000000;
    } else if (inputUnit == 5 && outputUnit == 4) {
        outputValue = inputValue / 1000;
    } else if (inputUnit == 5 && outputUnit == 6) {
        outputValue = inputValue * 1000;
    } else if (inputUnit == 6 && outputUnit == 1) {
        outputValue = inputValue / 1000000000;
    } else if (inputUnit == 6 && outputUnit == 2) {
        outputValue = inputValue / 10000000;
    } else if (inputUnit == 6 && outputUnit == 3) {
        outputValue = inputValue / 1000000000000;
    } else if (inputUnit == 6 && outputUnit == 4) {
        outputValue = inputValue / 1000000;
    } else if (inputUnit == 6 && outputUnit == 5) {
        outputValue = inputValue / 1000;
    }

    printf("Output value: %0.4f", outputValue);

    return 0;
}