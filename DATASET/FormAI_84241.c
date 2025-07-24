//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Claude Shannon
//A C program to convert hexadecimal numbers into decimal numbers
#include <stdio.h>
#include <string.h>
#include <math.h>

//Function to convert hexadecimal to decimal
int hex2dec(char hex[]) {
    int len = strlen(hex);
    int base = 1;
    int decimal = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base = base * 16;
        }
    }
    return decimal;
}

//Main function
int main() {

    //Input the hexadecimal number from the user
    char hex[20];
    printf("Enter the hexadecimal number: ");
    scanf("%s", &hex);

    //Convert hexadecimal to decimal
    int decimal = hex2dec(hex);

    //Print the results
    printf("Decimal number is: %d", decimal);
    return 0;
}

//End of the program