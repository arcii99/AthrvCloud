//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: invasive
#include<stdio.h>
#include<string.h>

char * to_morse_code(char);

char * morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
    "-.--", "--.."
};

int main(){
    char text[255], morse[255];
    int i, j;
    
    printf("Please enter the text to be converted into Morse Code: ");
    scanf("%[^\n]", text);
    
    for(i=0,j=0; i<strlen(text); i++){
        if(text[i] == ' '){
            morse[j] = '/';
            j++;
            morse[j] = ' ';
        } else {
            char * code = to_morse_code(text[i]);
            strcpy(&morse[j], code);
            j += strlen(code);
        }
        j++;
    }
    morse[j] = '\0';
    
    printf("Morse Code is as follows: \n%s", morse);
    
    return 0;
}

char * to_morse_code(char c) {
    return morse_code[tolower(c) - 'a'];
}