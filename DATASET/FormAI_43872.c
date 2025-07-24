//FormAI DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>

int main() {
    float input_value;
    int option;
    float result;

    printf("Enter the value to be converted: ");
    scanf("%f", &input_value);

    printf("Enter the option of your conversion you want to perform:\n");
    printf("1. Convert Celsius to Fahrenheit \n");
    printf("2. Convert Fahrenheit to Celsius \n");
    printf("3. Convert Kilometers per hour to Miles per hour \n");
    printf("4. Convert Miles per hour to Kilometers per hour \n");
    scanf("%d", &option);

    switch(option) {
        case 1:
          // convert Celsius to Fahrenheit
          result = (input_value * 9/5) + 32;
          printf("%.2f Celsius is equal to %.2f Fahrenheit \n", input_value, result);
          break;
        case 2:
          // convert Fahrenheit to Celsius
          result = (input_value - 32) * 5/9;
          printf("%.2f Fahrenheit is equal to %.2f Celsius \n", input_value, result);
          break;
        case 3:
          // convert Kilometers per hour to Miles per hour
          result = input_value / 1.609;
          printf("%.2f Kilometers per hour is equal to %.2f Miles per hour \n", input_value, result);
          break;
        case 4:
          // convert Miles per hour to Kilometers per hour
          result = input_value * 1.609;
          printf("%.2f Miles per hour is equal to %.2f Kilometers per hour \n", input_value, result);
          break;
        default:
          printf("Invalid option selected \n");
    }

    return 0;
}