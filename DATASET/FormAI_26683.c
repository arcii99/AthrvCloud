//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100];
    char morse[50][10] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/"};
    //morse code for alphabets and slash(/) for space
    int i, j, len;

    printf("Enter the text you want to convert to Morse code: ");
    fgets(text, 100, stdin); //read input from user including spaces
    len = strlen(text);

    for(i=0; i<len; i++) {
        if(text[i] == ' ') {  //if space, print slash(/)
            printf("/");
        }
        else if(isalpha(text[i])) {  //if alphabet, find its corresponding morse code and print
            j = tolower(text[i]) - 'a';
            printf("%s", morse[j]);
        }
    }
    return 0;
}