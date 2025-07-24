//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to hexadecimal
char* decToHex(int decimal){
    char* hexadecimal = (char*)malloc(50*sizeof(char)); // Allocating memory for hexadecimal string
    int i = 0;

    while(decimal>0){
        int remainder = decimal % 16;
        if(remainder<10){
            hexadecimal[i] = remainder + 48;
            i++;
        }else{
            hexadecimal[i] = remainder + 55;
            i++;
        }
        decimal /= 16;
    }
    hexadecimal[i] = '\0'; // Adding string terminator
    return hexadecimal;
}

int main(){
    int decimal;
    char* hexadecimal;
    printf("Enter decimal number to convert to hexadecimal: ");
    scanf("%d",&decimal);

    hexadecimal = decToHex(decimal);

    printf("Hexadecimal of %d is %s.\n",decimal,hexadecimal);
    free(hexadecimal); // Freeing up memory allocated for hexadecimal string
    return 0;
}