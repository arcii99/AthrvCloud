//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void convertToMorseCode(char *);

int main(){
    char input[100];
    printf("Enter the text to convert to morse code:\n");
    fgets(input, 100, stdin);
    convertToMorseCode(input);
    return 0;    
}

void convertToMorseCode(char *input){
    char morseCode[36][7] = {".-","-...","-.-.","-..",".","..-.","--.",
        "....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",
        ".-.","...","-","..-","...-",".--","-..-","-.--","--..",
        ".----","..---","...--","....-",".....","-....","--...","---..",
        "----.","-----"};
    char *code;
    int length = strlen(input);
    printf("Morse Code:\n");
    for(int i=0; i<length; i++){
        if(input[i] == ' '){
            printf(" / ");
        }else if(input[i] >= 'a' && input[i] <= 'z'){
            code = morseCode[input[i]-'a'];
            printf("%s ", code);
        }else if(input[i] >= 'A' && input[i] <= 'Z'){
            code = morseCode[input[i]-'A'];
            printf("%s ", code);
        }else if(input[i] >= '0' && input[i] <= '9'){
            code = morseCode[input[i]-'0'+26];
            printf("%s ", code);
        }else{
            printf("??? ");
        }        
    }    
}