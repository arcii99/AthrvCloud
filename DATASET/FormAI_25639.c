//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <string.h>

void alienLanguageTranslator(char*);

int main(){
    char input[100];
    printf("Enter a string in the Alien Language: ");
    fgets(input, 100, stdin);
    alienLanguageTranslator(input);
    return 0;
}

void alienLanguageTranslator(char *str){
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] >= 'a' && str[i] <= 'm'){
            printf("%c", str[i]+13);
        }
        else if (str[i] >= 'n' && str[i] <= 'z'){
            printf("%c", str[i]-13);
        }
        else{
            printf("%c", str[i]);
        }
    }
}