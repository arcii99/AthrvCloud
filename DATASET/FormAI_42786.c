//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: detailed
#include<stdio.h>
#include<string.h>

//takes input from the user
void takeInput(char* input){
    printf("Enter a phrase in cat language: ");
    fgets(input, 100, stdin);
}

//translates the cat language to English
void catTranslator(char* input){
    int i;
    for(i=0; input[i]!='\0'; i++){
        switch(input[i]){
            case 'M': printf("Meow");
                    break;
            case 'P': printf("Purr");
                    break;
            case 'H': printf("Hiss");
                    break;
            case 'C': printf("Chirp");
                    break;
            case 'B': printf("Bird");
                    break;
            case 'F': printf("Fur");
                    break;
            case 'L': printf("Litter");
                    break;
            case 'T': printf("Treat");
                    break;
            case 'W': printf("Water");
                    break;
            case 'U': printf("Mouse");
                    break;
            case 'S': printf("Scratch");
                    break;
            case 'O': printf("Food");
                    break;
            default: printf("%c", input[i]);
                    break;      
        }
    }
}

int main(){
    char input[100];
    takeInput(input);
    catTranslator(input);
    return 0;
}