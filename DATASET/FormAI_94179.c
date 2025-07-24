//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: introspective
#include<stdio.h>
#include<string.h>

//function to convert a character to morse code
void charToMorse(char ch) {
    switch(ch) {
        case 'a':
        case 'A':
            printf(". -");
            break;
        case 'b':
        case 'B':
            printf("- . . .");
            break;
        case 'c':
        case 'C':
            printf("- . - .");
            break;
        //more cases for other characters omitted for brevity...
        default:
            printf(" ");
    }
}

//function to convert a string to morse code
void stringToMorse(char str[]) {
    int i, len;
    len = strlen(str);
    for(i=0; i<len; i++) {
        charToMorse(str[i]);
        printf(" "); //add a space between each character
    }
}

int main() {
    char input[100];
    printf("Enter a string to convert to Morse code: ");
    scanf("%[^\n]", input); //read the entire line including spaces
    printf("Morse code: ");
    stringToMorse(input);
    return 0;
}