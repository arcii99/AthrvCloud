//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: mathematical
#include<stdio.h>
#include<string.h>

int main(){
    char myString[50];
    printf("Enter a sentence to translate to cat language: ");
    fgets(myString,sizeof(myString),stdin);

    for(int i=0;i<strlen(myString);i++){
        if(myString[i]=='c' || myString[i]=='C'){
            printf("meow");
        }
        else if(myString[i]=='a' || myString[i]=='A'){
            printf("purr");
        }
        else if(myString[i]=='t' || myString[i]=='T'){
            printf("hiss");
        }
        else{
            printf("%c",myString[i]);
        }
    }

    return 0;
}