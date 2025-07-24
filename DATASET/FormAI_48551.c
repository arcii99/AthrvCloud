//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    char input[100];
    printf("Enter the alien language to be translated:\n");
    fgets(input, 100, stdin);

    // Transform all letters to lowercase
    for(int i=0;i<strlen(input);i++){
        input[i] = tolower(input[i]);
    }

    // Tokenize the input string and store in an array
    char *token = strtok(input, " ");
    char *tokens[50];
    int idx = 0;
    while(token!=NULL){
        tokens[idx++] = token;
        token = strtok(NULL, " ");
    }

    // Create a lexicon of alien words and their corresponding translations
    char lexicon[50][30] = {
        {"abatuk"}, {"hello"},
        {"krilvint"}, {"goodbye"},
        {"hsktvrak"}, {"how are you?"},
        {"nksikask"}, {"thank you"},
        {"kriltask"}, {"please"},
        {"sevlvaxt"}, {"sorry"}
        // More translations can be added here
    };

    // Translate each token using the lexicon
    for(int i=0;i<idx;i++){
        char *alien = tokens[i];
        int found = 0;
        for(int j=0;j<50;j+=2){
            if(strcmp(alien, lexicon[j])==0){
                printf("%s ", lexicon[j+1]);
                found = 1;
                break;
            }
        }
        if(found==0){
            printf("%s ", alien);
        }
    }
    printf("\n");

    return 0;
}