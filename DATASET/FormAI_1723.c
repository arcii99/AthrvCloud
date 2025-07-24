//FormAI DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // variables to store RGB values
    int red, green, blue;
    // variables to store hexadecimal values of RGB
    char hex_red[3], hex_green[3], hex_blue[3];

    // input RGB values from user
    printf("Enter the value of Red: ");
    scanf("%d", &red);
    printf("Enter the value of Green: ");
    scanf("%d", &green);
    printf("Enter the value of Blue: ");
    scanf("%d", &blue);

    // convert RGB to hexadecimal
    sprintf(hex_red, "%02X", red);
    sprintf(hex_green, "%02X", green);
    sprintf(hex_blue, "%02X", blue);

    // output hexadecimal code in different formats
    printf("\nHexadecimal Code: #%s%s%s\n", hex_red, hex_green, hex_blue);
    printf("Color Code for CSS: rgb(%d, %d, %d)\n", red, green, blue);
    printf("Color Code for OpenGL: {%f, %f, %f}\n", (float)red/255, (float)green/255, (float)blue/255);

    return 0;
}