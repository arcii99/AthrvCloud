//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: detailed
#include<stdio.h>

int main(){
    char str[100], translated[100];
    int i = 0;
    
    printf("Enter text in C Cat Language: ");
    fgets(str, 100, stdin);
    
    while(str[i] != '\0'){
        if(str[i] == 'm'){
            translated[i] = 'c';
        }
        else if(str[i] == 'e'){
            translated[i] = 'a';
        }
        else if(str[i] == 'o'){
            translated[i] = 't';
        }
        else{
            translated[i] = str[i];
        }
        i++;
    }
    
    printf("Translated text: %s", translated);
    
    return 0;
}