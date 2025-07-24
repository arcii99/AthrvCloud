//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scalable
#include <stdio.h>
#include <string.h>

void convertToUpper(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

void convertToMorse(char* str) {
    char* morse[256] = {
        "._",   //A
        "_...", //B
        "_._.", //C
        "_..",  //D
        ".",    //E
        ".._.", //F
        "__.",  //G
        "....", //H
        "..",   //I
        ".___", //J
        "_._",  //K
        "._..", //L
        "__",   //M
        "_.",   //N
        "___",  //O
        ".__.", //P
        "__._", //Q
        "._.",  //R
        "...",  //S
        "_",    //T
        ".._",  //U
        "..._", //V
        ".__",  //W
        "_.._", //X
        "_.__", //Y
        "__..", //Z
        " ",    //space
        "_._._", //period
        "__..__", //comma
        "..__..", //question mark
        ".__._.", //at symbol
        "_____", //0
        ".____", //1
        "..___", //2
        "...__", //3
        "...._", //4
        ".....", //5
        "_....", //6
        "__...", //7
        "___..", //8
        "____.", //9
    };
    
    int i = 0;
    while (str[i]) {
        int ascii = (int) str[i];
        if (ascii >= 65 && ascii <= 90) { //alphabetical character
            printf("%s ", morse[ascii-65]); //print the corresponding morse code for the character
        }
        else if (ascii >= 48 && ascii <= 57) { //numerical character
            printf("%s ", morse[ascii-22]); //print the corresponding morse code for the character
        }
        else { //non-alphanumeric character
            switch(ascii) {
                case 32: //space
                    printf("/ ");
                    break;
                case 46: //period
                    printf("%s ", morse[26]);
                    break;
                case 44: //comma
                    printf("%s ", morse[27]);
                    break;
                case 63: //question mark
                    printf("%s ", morse[28]);
                    break;
                case 64: //at symbol
                    printf("%s ", morse[29]);
                    break;
                default:
                    break;
            }
        }
        i++;
    }
}

int main() {
    char input[256];
    printf("Enter text to convert to Morse code: ");
    fgets(input, 256, stdin); //get input from user
    convertToUpper(input); //convert input to all uppercase characters
    printf("Morse code: ");
    convertToMorse(input); //convert input to morse code and print
    printf("\n");
    return 0;
}