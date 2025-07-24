//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: imaginative
#include<stdio.h>
#include<string.h>

// function to convert text to morse code
char* textToMorse(char* text) {
    char* morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
                       "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
                       "-.--", "--.."};
    char* morseCode = "";
    int textLength = strlen(text);
    for(int i=0; i<textLength; i++) {
        if(text[i] >= 'a' && text[i] <= 'z')
            morseCode = strcat(morseCode, morse[text[i]-'a']);
        else if(text[i] >= 'A' && text[i] <= 'Z')
            morseCode = strcat(morseCode, morse[text[i]-'A']);
        else if(text[i] == ' ')
            morseCode = strcat(morseCode, "  ");
        else
            morseCode = strcat(morseCode, "Invalid Input!(Only A-Z or a-z are allowed)");
        morseCode = strcat(morseCode, " ");
    }
    return morseCode;
}

// main function
int main() {
    char text[100];
    printf("Enter the plain text: ");
    scanf("%[^\n]%*c", text);
    char* morse = textToMorse(text);
    printf("%s\n", morse);
    return 0;
}