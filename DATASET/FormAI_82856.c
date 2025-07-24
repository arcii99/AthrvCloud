//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToMorse(char text[], int length){
    char *morse[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
        ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", " "
    };
    char *alpha[] = {
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q",
        "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " ", " "
    };
    int i = 0, j;
    char c;
    while (text[i]){
        c = toupper(text[i]);
        for (j = 0; j < 27; ++j){
            if (alpha[j][0] == c){
                printf("%s ", morse[j]);
            }
        }
        ++i;
    }
    printf("\n");
}

int main(){
    char text[200];
    int length;
    printf("Enter Text: ");
    fgets(text, sizeof(text), stdin);
    length = strlen(text);
    if (text[length-1] == '\n'){
        text[length-1] = '\0';
        --length;
    }
    convertToMorse(text, length);
    return 0;
}