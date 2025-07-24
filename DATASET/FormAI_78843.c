//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

void convertToMorse(char* message){
    printf("Morse Code: ");
    for(int i=0;i<strlen(message);i++){
        if(isalpha(message[i])){
            printf("%s",morse[toupper(message[i])-'A']);
        }
        else if(isdigit(message[i])){
            switch(message[i]){
                case '0': printf("-----"); break;
                case '1': printf(".----"); break;
                case '2': printf("..---"); break;
                case '3': printf("...--"); break;
                case '4': printf("....-"); break;
                case '5': printf("....."); break;
                case '6': printf("-...."); break;
                case '7': printf("--..."); break;
                case '8': printf("---.."); break;
                case '9': printf("----."); break;
            }
        }
        else if(message[i] == ' '){
            printf(" / ");
        }
        else{
            printf("%c",message[i]);
        }
    }
    printf("\n");
}

int main(){
    char message[100];
    printf("Enter the message you want to convert to Morse Code: ");
    fgets(message,100,stdin);
    message[strcspn(message, "\n")] = 0; //removing the newline character from the input
    convertToMorse(message);
    return 0;
}