//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include<stdio.h>

void decToHex(int num) { // function to convert decimal to hexadecimal
    char hex[100]; // an array to store the hexadecimal number
    int i = 0;
    while (num != 0) {
        int temp = 0;
        temp = num % 16; // get the remainder
        if(temp < 10) {
            hex[i] = temp + 48; // if temp is less than 10, add 48 to get the ASCII value of the corresponding digit
        } else {
            hex[i] = temp + 55; // if temp is greater than 10, add 55 to get the ASCII value of the corresponding alphabet
        }
        i++;
        num /= 16;
    }
    printf("Hexadecimal value is: ");
    // print the hexadecimal number in reverse order
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
  
    decToHex(num); // call the function to convert decimal to hexadecimal
  
    return 0; // end of program
}