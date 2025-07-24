//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

void hexStrToInt(char *hex, int *intArr, int arrSize);
void hexConvert(int n, char *hex);


int main() {
    char hex[10] = "FF12B3"; //Initial hex string
    int intArr[3]; //Array to hold converted integers

    hexStrToInt(hex, intArr, sizeof(intArr)); //Convert hex string to int array

    for(int i=0; i<sizeof(intArr)/sizeof(intArr[0]); i++) {
        printf("Integer %d: %d\n", i+1, intArr[i]); //Print converted integers
    }

    return 0;
}

void hexStrToInt(char *hex, int *intArr, int arrSize) {
    int n = atoi(hex); //Convert hex string to decimal integer
    int i = 0;

    while(n > 0 && i < arrSize) {
        intArr[i] = n % 10; //Extract last digit of the integer
        n = n / 10; //Remove last digit from the integer
        i++;
    }

    printf("Hexadecimal string converted to integers!\n");
}

void hexConvert(int n, char *hex) {
    char hexDigits[] = "0123456789ABCDEF"; //Hexadecimal digits
    int remainder, quotient;
    int i = 0;

    while(n != 0) {
        remainder = n % 16; //Calculate remainder of division by 16
        quotient = n / 16; //Calculate quotient of division by 16
        hex[i] = hexDigits[remainder]; //Get corresponding hex digit
        i++;
        n = quotient;
    }

    hex[i] = '\0'; //Terminate hex string
    printf("Integer converted to hexadecimal!\n");
}