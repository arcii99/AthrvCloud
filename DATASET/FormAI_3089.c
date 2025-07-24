//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>

void main() {
    // declare variables for the RGB values
    int red, green, blue;

    // prompts the user to enter the RGB values
    printf("Enter the value of the Red (0-255): ");
    scanf("%d", &red);
    printf("Enter the value of the Green (0-255): ");
    scanf("%d", &green);
    printf("Enter the value of the Blue (0-255): ");
    scanf("%d", &blue);

    // convert the RGB values to HEX
    int r_hex = red / 16;
    int r_rem = red % 16;

    int g_hex = green / 16;
    int g_rem = green % 16;

    int b_hex = blue / 16;
    int b_rem = blue % 16;

    // declare string variable to store the HEX value
    char hex[8];

    // populate the HEX string using a switch statement
    switch (r_hex) {
        case 0:
            hex[0] = '0';
            break;
        case 1:
            hex[0] = '1';
            break;
        case 2:
            hex[0] = '2';
            break;
        case 3:
            hex[0] = '3';
            break;
        case 4:
            hex[0] = '4';
            break;
        case 5:
            hex[0] = '5';
            break;
        case 6:
            hex[0] = '6';
            break;
        case 7:
            hex[0] = '7';
            break;
        case 8:
            hex[0] = '8';
            break;
        case 9:
            hex[0] = '9';
            break;
        case 10:
            hex[0] = 'A';
            break;
        case 11:
            hex[0] = 'B';
            break;
        case 12:
            hex[0] = 'C';
            break;
        case 13:
            hex[0] = 'D';
            break;
        case 14:
            hex[0] = 'E';
            break;
        case 15:
            hex[0] = 'F';
            break;
    }

    // repeat for all the remaining RGB values
    switch (r_rem) {
        case 0:
            hex[1] = '0';
            break;
        case 1:
            hex[1] = '1';
            break;
        case 2:
            hex[1] = '2';
            break;
        case 3:
            hex[1] = '3';
            break;
        case 4:
            hex[1] = '4';
            break;
        case 5:
            hex[1] = '5';
            break;
        case 6:
            hex[1] = '6';
            break;
        case 7:
            hex[1] = '7';
            break;
        case 8:
            hex[1] = '8';
            break;
        case 9:
            hex[1] = '9';
            break;
        case 10:
            hex[1] = 'A';
            break;
        case 11:
            hex[1] = 'B';
            break;
        case 12:
            hex[1] = 'C';
            break;
        case 13:
            hex[1] = 'D';
            break;
        case 14:
            hex[1] = 'E';
            break;
        case 15:
            hex[1] = 'F';
            break;
    }

    // repeat for the other colors
    switch (g_hex) {
        case 0:
            hex[2] = '0';
            break;
        case 1:
            hex[2] = '1';
            break;
        case 2:
            hex[2] = '2';
            break;
        case 3:
            hex[2] = '3';
            break;
        case 4:
            hex[2] = '4';
            break;
        case 5:
            hex[2] = '5';
            break;
        case 6:
            hex[2] = '6';
            break;
        case 7:
            hex[2] = '7';
            break;
        case 8:
            hex[2] = '8';
            break;
        case 9:
            hex[2] = '9';
            break;
        case 10:
            hex[2] = 'A';
            break;
        case 11:
            hex[2] = 'B';
            break;
        case 12:
            hex[2] = 'C';
            break;
        case 13:
            hex[2] = 'D';
            break;
        case 14:
            hex[2] = 'E';
            break;
        case 15:
            hex[2] = 'F';
            break;
    }

    switch (g_rem) {
        case 0:
            hex[3] = '0';
            break;
        case 1:
            hex[3] = '1';
            break;
        case 2:
            hex[3] = '2';
            break;
        case 3:
            hex[3] = '3';
            break;
        case 4:
            hex[3] = '4';
            break;
        case 5:
            hex[3] = '5';
            break;
        case 6:
            hex[3] = '6';
            break;
        case 7:
            hex[3] = '7';
            break;
        case 8:
            hex[3] = '8';
            break;
        case 9:
            hex[3] = '9';
            break;
        case 10:
            hex[3] = 'A';
            break;
        case 11:
            hex[3] = 'B';
            break;
        case 12:
            hex[3] = 'C';
            break;
        case 13:
            hex[3] = 'D';
            break;
        case 14:
            hex[3] = 'E';
            break;
        case 15:
            hex[3] = 'F';
            break;
    }

    switch (b_hex) {
        case 0:
            hex[4] = '0';
            break;
        case 1:
            hex[4] = '1';
            break;
        case 2:
            hex[4] = '2';
            break;
        case 3:
            hex[4] = '3';
            break;
        case 4:
            hex[4] = '4';
            break;
        case 5:
            hex[4] = '5';
            break;
        case 6:
            hex[4] = '6';
            break;
        case 7:
            hex[4] = '7';
            break;
        case 8:
            hex[4] = '8';
            break;
        case 9:
            hex[4] = '9';
            break;
        case 10:
            hex[4] = 'A';
            break;
        case 11:
            hex[4] = 'B';
            break;
        case 12:
            hex[4] = 'C';
            break;
        case 13:
            hex[4] = 'D';
            break;
        case 14:
            hex[4] = 'E';
            break;
        case 15:
            hex[4] = 'F';
            break;
    }

    switch (b_rem) {
        case 0:
            hex[5] = '0';
            break;
        case 1:
            hex[5] = '1';
            break;
        case 2:
            hex[5] = '2';
            break;
        case 3:
            hex[5] = '3';
            break;
        case 4:
            hex[5] = '4';
            break;
        case 5:
            hex[5] = '5';
            break;
        case 6:
            hex[5] = '6';
            break;
        case 7:
            hex[5] = '7';
            break;
        case 8:
            hex[5] = '8';
            break;
        case 9:
            hex[5] = '9';
            break;
        case 10:
            hex[5] = 'A';
            break;
        case 11:
            hex[5] = 'B';
            break;
        case 12:
            hex[5] = 'C';
            break;
        case 13:
            hex[5] = 'D';
            break;
        case 14:
            hex[5] = 'E';
            break;
        case 15:
            hex[5] = 'F';
            break;
    }

    // add the null terminator to the HEX string
    hex[6] = '\0';

    // output the resulting HEX color code
    printf("The corresponding HEX color code is: #%s", hex);
}