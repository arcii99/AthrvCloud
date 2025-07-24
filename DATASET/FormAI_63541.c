//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void convert_to_hex(char input, char *hex);

int main(){
    char convert_again;
    do{
        printf("Enter a character to convert to hexadecimal: ");
        char input;
        scanf(" %c", &input);
        char *hexadecimal = (char*) malloc(sizeof(char) * 3);
        convert_to_hex(input, hexadecimal);
        printf("The hexadecimal equivalent of %c is %s\n", input, hexadecimal);
        free(hexadecimal);
        do{
            printf("Do you want to convert another character (Y/N)? ");
            scanf(" %c", &convert_again);
        } while(! (toupper(convert_again) == 'Y' || toupper(convert_again) == 'N'));
    } while(toupper(convert_again) == 'Y');
    return 0;
}

void convert_to_hex(char input, char *hex){
    int ascii = input;
    int quotient, remainder;
    quotient = ascii/16;
    remainder = ascii%16;
    if(quotient >= 0 && quotient <= 9){
        hex[0] = (char) (48 + quotient);
    } else {
        hex[0] = (char) (55 + quotient);
    }
    if(remainder >= 0 && remainder <= 9){
        hex[1] = (char) (48 + remainder);
    } else {
        hex[1] = (char) (55 + remainder);
    }
    hex[2] = '\0';
}