//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Dennis Ritchie
/* Program to convert text to Morse code */
#include<stdio.h>

int main(){
char text[100], ch, morsecode[27][5] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "};
int i = 0, j = 0;

printf("Enter text to be converted to Morse code:\n");
scanf("%[^\n]", text);

printf("The Morse code for the given text is:\n");

while(text[i] != '\0'){
    ch = text[i];
    if(ch >= 'a' && ch <= 'z'){
        j = ch - 'a';
        printf("%s ", morsecode[j]);
    }
    else if(ch >= 'A' && ch <= 'Z'){
        j = ch - 'A';
        printf("%s ", morsecode[j]);
    }
    else if(ch == ' '){
        printf(" ");
    }
    i++;
}

return 0;
}