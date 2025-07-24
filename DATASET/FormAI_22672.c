//FormAI DATASET v1.0 Category: Temperature Converter ; Style: standalone
#include <stdio.h>

int main() {
    float c_temp, f_temp;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &c_temp);

    //convert celsius to fahrenheit
    f_temp = (c_temp * 9 / 5) + 32;

    printf("\n%.2fC is %.2fF\n", c_temp, f_temp);

    return 0;
}