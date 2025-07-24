//FormAI DATASET v1.0 Category: Binary Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char binary[1000]; //The binary number to be converted
    int decimal = 0; //The decimal equivalent
    int i = 0, j = 0; //Loop iterators

    printf("Enter a binary number: ");
    scanf("%s", binary); //Get the binary number from the user

    //Loop through the binary number from right to left
    for(i = strlen(binary) - 1; i >= 0; i--) {
        //If the current bit is a '1', add the corresponding power of 2 to the decimal equivalent
        if(binary[i] == '1') {
            decimal += (int)pow(2, j);
        }
        //Increment the power of 2 we're using
        j++;
    }

    printf("The decimal equivalent of %s is %d\n", binary, decimal); //Print the result

    return 0;
}