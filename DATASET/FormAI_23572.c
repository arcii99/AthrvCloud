//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include<stdio.h>
#include<string.h>

//Function to convert text to Morse code
void textToMorse(char* text) {
    int i,j;
    char *morseCode[] = {"-----",".----","..---","...--","....-",".....",
                        "-....","--...","---..","----.",".-","-...","-.-.",
                        "-..",".","..-.","--.","....","..",".---","-.-",".-..",
                        "--","-.","---",".--.","--.-",".-.","...","-","..-",
                        "...-",".--","-..-","-.--","--..","/"};
    char alphabets[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ/";
    
    printf("\nMorse Code: ");
    for(i=0; i<strlen(text); i++) {
        if(text[i] == ' ') {
            printf(" / ");
        }
        else if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] - 32;
        }
        for(j=0; j<strlen(alphabets); j++) {
            if(text[i] == alphabets[j]) {
                printf("%s ", morseCode[j]);
                break;
            }
        }
    }
    printf("\n");
}

//Driver Code
int main() {
    char text[100];
    printf("Enter text to convert to Morse code: ");
    gets(text);
    printf("Text Entered: %s", text);
    
    textToMorse(text);
    
    return 0;
}