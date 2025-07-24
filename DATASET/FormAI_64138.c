//FormAI DATASET v1.0 Category: Color Code Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to hexadecimal color code
void decToHex(int decimal, char hex[]) {
    int i = 0;
    while(decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i++] = remainder + 48;
        } else {
            hex[i++] = remainder + 55;
        }
        decimal /= 16;
    }
    // Reverse the order of characters in hex[]
    for(int j=0; j<i/2; j++) {
        char temp = hex[j];
        hex[j] = hex[i-j-1];
        hex[i-j-1] = temp;
    }
}

int main() {
    int red, green, blue;
    printf("Enter the RGB values (0-255):\n");
    printf("Red: ");
    scanf("%d", &red);
    printf("Green: ");
    scanf("%d", &green);
    printf("Blue: ");
    scanf("%d", &blue);

    char redHex[2], greenHex[2], blueHex[2]; // Array to store hexadecimal values

    decToHex(red, redHex);
    decToHex(green, greenHex);
    decToHex(blue, blueHex);

    printf("The hexadecimal color code for RGB(%d,%d,%d) is #%s%s%s", red, green, blue, redHex, greenHex, blueHex);

    return 0;
}