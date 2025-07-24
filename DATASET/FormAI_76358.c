//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function that returns ASCII art of given text
char* text_to_ascii(char* text) {
    int len = strlen(text);
    char* art = (char*) malloc(5 * len * sizeof(char));
    int k = 0;
    for(int i = 0; i < len; i++) {
        //convert character to ASCII art
        switch(text[i]) {
            case 'A':
                art[k++] = "  /\\ \n /  \\ \n/____\\";
                break;
            case 'B':
                art[k++] = " ____ \n|  _ \\ \n| |_) |\n|  _ < \n|_| \\_\\";
                break;
            case 'C':
                art[k++] = "  ____\n / ___|\n| |    \n| |___ \n \\____|";
                break;
            //add more cases for other letters
            default:
                art[k++] = "     \n     \n     \n     \n     "; //default blank space
        }
        art[k++] = "\n"; //add newline character to separate letters
    }
    art[k] = '\0'; //add null terminating character to end the string
    return art;
}

int main() {
    char* text = "ABC"; //sample text
    char* ascii_art = text_to_ascii(text); //convert text to ASCII art
    printf("%s", ascii_art); //print ASCII art
    free(ascii_art); //free dynamically allocated memory
    return 0;
}