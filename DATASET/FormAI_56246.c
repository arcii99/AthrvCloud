//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: dynamic
#include<stdio.h>
#include<string.h>

//function to translate given word to cat language
void translate(char *word){
    int len = strlen(word);
    char result[1000];
    int i=0;
    for(;i<len;i++){
        char c = word[i];
        if(c=='C' || c=='c'){
            strcat(result,"meow");
        }else if(c=='A' || c=='a'){
            strcat(result,"purr");
        }else if(c=='T' || c=='t'){
            strcat(result,"hiss");
        }else{
            strcat(result,&c);
        }
    }
    printf("%s\n",result);
}

int main(){
    char word[1000];
    printf("Enter a word to translate to cat language: ");
    scanf("%s",word);
    translate(word);
    return 0;
}