//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main() {

    int r, g, b;

    printf("Enter the red value (0-255): ");
    scanf("%d", &r);

    printf("Enter the green value (0-255): ");
    scanf("%d", &g);

    printf("Enter the blue value (0-255): ");
    scanf("%d", &b);

    //convert the values to hex and print the hex color code

    printf("The hex color code is: #%02X%02X%02X", r, g, b);

    return 0;
}