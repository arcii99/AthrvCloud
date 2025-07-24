//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: artistic
#include <stdio.h>
#include <string.h>

#define MAX_MORSE_LENGTH 20

void convert(char *text);

int main(){

    char text[100];

    printf("Enter Text to Convert to Morse Code\n");
    gets(text);
    convert(text);

    return 0;
}

void convert(char *text){

    int i, j;
    char morse_[27][MAX_MORSE_LENGTH] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "};
    char alpha_[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ "};

    printf("Morse Code: \n");

    for(i=0; i<strlen(text); i++){
        for(j=0; j<27; j++){
            if(text[i]==alpha_[j]){
                printf("%s ", morse_[j]);
            }
        }
    }
}