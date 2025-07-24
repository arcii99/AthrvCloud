//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: expert-level
#include <stdio.h>
#include <string.h>

char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",     ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",  "..-", "...-", ".--", "-..-", "-.--", "--..", " "};

char *alpha[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " "};

char* textToMorse(char text[]) {
    int len=strlen(text);
    char *str = (char*) malloc((4*len+1) * sizeof(char));
    str[0]='\0';

    for(int i=0; i<len; i++) {
        for(int j=0; j<27; j++) {
            if(toupper(text[i]) == alpha[j][0]) {
                strcat(str, morse[j]);
                strcat(str, " ");
                break;
            }
        }
    }
    return str;
}

int main() {
    char s[]="I AM A MORSE CODE EXAMPLE";
    printf("Text: %s \n", s);

    char *result = textToMorse(s);
    printf("Morse Code: %s \n", result);
    free(result);

    return 0;
}