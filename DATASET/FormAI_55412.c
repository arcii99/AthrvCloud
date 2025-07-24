//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void morse_conversion(char *text, char *morse_code){
    int i=0, j=0;
    char *morse_table[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", NULL};
    char *alpha_table = "abcdefghijklmnopqrstuvwxyz ";
    for(i=0; i<strlen(text); i++){
        for(j=0; j<strlen(alpha_table); j++){
            if (tolower(text[i])==alpha_table[j]){
                strcat(morse_code, morse_table[j]);
                strcat(morse_code, " ");
                break;
            }
        }
    }
}

int main(){
    char text[50];
    printf("Enter the text to be converted to morse code: ");
    scanf("%[^\n]", text);
    getchar();
    char *morse_code = (char*)malloc(500*sizeof(char));
    strcpy(morse_code, "");
    morse_conversion(text, morse_code);
    printf("Morse Code: %s\n", morse_code);
    free(morse_code);

    return 0;
}