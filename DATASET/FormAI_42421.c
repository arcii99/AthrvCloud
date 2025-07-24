//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: genious
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", 
                      ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
                      ".--", "-..-", "-.--", "--..", "/", ".----", "..---", "...--", "....-", 
                      ".....", "-....", "--...", "---..", "----.", "-----"};

char morse_letter(char* code){
    int i;
    for(i = 0; i < 36; ++i)
        if(!strcmp(code, morse_code[i]))
            return i + 'A';
    return '-';
}

char char_to_morse(char* code){
    char letter;
    printf("\n%c -> ", *code);
    if(isalpha(*code)){
        if(isupper(*code))
            *code = tolower(*code);
        letter = *code - 'a';
        printf("%s", morse_code[letter]);
    }
    else if(isdigit(*code)){
        letter = *code - '0' + 26;
        printf("%s", morse_code[letter]);
    }
    else if(*code == ' '){
        printf("%s", morse_code[36]);
    }
    else{
        printf("Invalid input!");
        return '-';
    }
    return morse_letter(code);
}

void text_to_morse(char* text){
    int i, len = strlen(text);
    printf("Original text: %s\n",text);
    printf("Morse code: ");
    for(i = 0; i < len; ++i){
        if(char_to_morse(&text[i]) == '-')
            return;
        if(text[i] != ' ')
            printf(" ");
    }
}

int main(){
    char text[100];
    printf("Enter text for conversion to Morse code: ");
    fgets(text, sizeof(text), stdin);
    text_to_morse(text);
    return 0;
}