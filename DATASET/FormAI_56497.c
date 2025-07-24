//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: enthusiastic
#include<stdio.h>
#include<string.h>

char* c_translator(char sentence[]){
    char* ptr = strtok(sentence, " ");
    char* message;
    while(ptr != NULL){
        if(strcmp(ptr, "meow") == 0){
            strcat(message, "printf(\"Hello World!\\n\"); ");
        }else if(strcmp(ptr, "purr") == 0){
            strcat(message, "int ");
            ptr = strtok(NULL, " ");
            strcat(message, ptr);
            strcat(message, "; ");
        }else if(strcmp(ptr, "hiss") == 0){
            strcat(message, "if(");
            ptr = strtok(NULL, " ");
            strcat(message, ptr);
            strcat(message, "){ ");
        }else if(strcmp(ptr, "scratch") == 0){
            strcat(message, "else{ ");
        }else if(strcmp(ptr, "swat") == 0){
            strcat(message, "} ");
        }
        ptr = strtok(NULL, " ");
    }
    return message;
}

int main(){
    char sentence[1000];
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please meow your sentence:\n");
    fgets(sentence, 1000, stdin);
    char* message = c_translator(sentence);
    printf("Your meowed translation is:\n");
    printf("%s\n", message);
    return 0;
}