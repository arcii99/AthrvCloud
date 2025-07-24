//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Function to convert text to Morse code
char* textToMorseCode(char* text){
    char* morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                          "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
                          ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
                          "-..-", "-.--", "--..", ".----", "..---", "...--", "....-",
                          ".....", "-....", "--...", "---..", "----.", "-----"};
    char* output = (char*)malloc(sizeof(char)*1000);
    output[0] = '\0';
    int length = strlen(text);
    for(int i=0; i< length; i++){
        if(text[i] == ' '){
            strcat(output, "/ ");
        }else{
            strcat(output, morse_code[toupper(text[i]) - 'A']);
            strcat(output, " ");
        }
    }
    return output;
}

int main(){
    char text[1000];
    printf("Enter the text to be converted to Morse code:\n");
    fgets(text, 1000, stdin);
    text[strlen(text)-1] = '\0';
    char* morse_code = textToMorseCode(text);
    printf("Morse code representation:\n");
    printf("%s", morse_code);
    free(morse_code);
    return 0;
}