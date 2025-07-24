//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: genious
#include<stdio.h>
#include<string.h>

//function to translate C Cat Language to English
void translate(char* code){
    char* word;
    word = strtok(code, " ");
    while(word != NULL){
        //checking for C Cat keywords
        if(strcmp(word, "meow") == 0){
            printf("int ");
        }
        else if(strcmp(word, "purr") == 0){
            printf("char ");
        }
        else if(strcmp(word, "hiss") == 0){
            printf("float ");
        }
        else if(strcmp(word, "growl") == 0){
            printf("double ");
        }
        else if(strcmp(word, "yowl") == 0){
            printf("void ");
        }
        else if(strcmp(word, "scratch") == 0){
            printf("(");
        }
        else if(strcmp(word, "lick") == 0){
            printf(")");
        }
        else if(strcmp(word, "mew") == 0){
            printf("{\n");
        }
        else if(strcmp(word, "pounce") == 0){
            printf("}\n");
        }
        else if(strcmp(word, "nap") == 0){
            printf("return ");
        }
        else if(strcmp(word, "chase") == 0){
            printf("for");
        }
        else if(strcmp(word, "jump") == 0){
            printf("if");
        }
        else if(strcmp(word, "sleep") == 0){
            printf("while");
        }
        else{
            printf("%s ", word);
        }
        word = strtok(NULL, " "); //move to the next word
    }
}

int main(){
    char code[1000]; //maximum 1000 characters code
    printf("Enter C Cat Language Code:\n");
    fgets(code, sizeof(code), stdin); //get input from user
    printf("\nEnglish Translation:\n");
    translate(code); //translate and print the output
    return 0;
}