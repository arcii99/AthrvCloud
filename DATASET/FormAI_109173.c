//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: thoughtful
// This program accepts user input in the form of a string,
// then converts that string to Morse code and outputs the result.

#include<stdio.h>
#include<string.h>

void toMorse(char s[], char output[]);

int main(){
    char input[1000], output[2000];
    printf("Enter text to convert to Morse code: ");
    scanf("%[^\n]", input);
    toMorse(input, output);
    printf("Morse code output: %s", output);
    return 0;
}

void toMorse(char s[], char output[]){
    char* Morse[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", 
                       "....", "..", ".---", "-.-", ".-..", "--", "-.", 
                       "---", ".--.", "--.-", ".-.", "...", "-", "..-", 
                       "...-", ".--", "-..-", "-.--", "--..", ".----", 
                       "..---", "...--", "....-", ".....", "-....", "--...", 
                       "---..", "----.", "-----"};
    char* alphabet = "abcdefghijklmnopqrstuvwxyz0123456789";
    int length = strlen(s);
    for (int i = 0; i < length; i++){
        char c = s[i];
        if (c == ' '){
            strcat(output, " ");
        } else {
            for(int j = 0; j < 36; j++){
                if (c == alphabet[j]){
                    strcat(output, Morse[j]);
                    strcat(output, " ");
                    break;
                }
            }
        }
    }
}