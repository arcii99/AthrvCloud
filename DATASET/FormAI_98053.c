//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: invasive
#include <stdio.h>
#include <string.h>

void toMorseCode(char *input);

int main(){
    printf("*****************\n");
    printf("* Morse Cod-e-r *\n");
    printf("*****************\n\n");

    char input[1000];
    printf("Enter Text to Convert to Morse Code:\n");
    fgets(input, 1000, stdin);

    toMorseCode(input);

    return 0;
}

void toMorseCode(char *input){
    char *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/"};
    char *alphaBets[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " "};

    int i, j;
    for(i = 0; i < strlen(input); i++){
        char *currentChar = input[i];
        for(j = 0; j < 27; j++){
            if(strcmp(currentChar, alphaBets[j]) == 0){
                printf("%s ", morseCode[j]);
                break;
            }
        }
    }
    printf("\n\n");
}