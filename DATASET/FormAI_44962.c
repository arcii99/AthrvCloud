//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Alan Touring
#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Function to check if the given character is a valid C Alien Language character
int isValidChar(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return 1;
    }
    return 0;
}

//Function to translate C Alien Language to English
void translate(char* str){
    int length = strlen(str);
    int i;
    for(i=0; i<length; i++){
        char c = tolower(str[i]);
        if(c == 'c' && i+1<length){
            char nextC = tolower(str[i+1]);
            if(nextC == 'w'){
                printf("%c", 'a');
                i++;
            }
            else if(nextC == 'x'){
                printf("%c", 'e');
                i++;
            }
            else if(nextC == 'z'){
                printf("%c", 'i');
                i++;
            }
            else{
                printf("%c", c);
            }
        }
        else if(isValidChar(c)){
            printf("%c", c);
        }
    }
}

int main(){
    printf("Enter a string in C Alien Language: \n");
    char str[100];
    fgets(str, 100, stdin);
    printf("C Alien Language Translation: ");
    translate(str);
    printf("\n");
    return 0;
}