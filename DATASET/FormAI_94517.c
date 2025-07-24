//FormAI DATASET v1.0 Category: Text processing ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to check for forbidden words
int forbiddenWords(char *string){
    char *forbidden[] = {"witch", "hell", "devil", "sorcery", "necromancy"};
    int i;
    for(i=0; i<5; i++){
        if(strstr(string, forbidden[i])){
            return 1; // forbidden word found
        }
    }
    return 0; // forbidden word not found
}

int main(){
    char text[1000];
    printf("Enter text to be processed: ");
    scanf("%[^\n]",text);
    printf("\n");

    int length=strlen(text);
    int i;
    int flag=1;

    // loop through each character and convert to lower case
    for (i=0; i<length; i++){
        text[i]=tolower(text[i]);
    }

    // loop through each word to check for forbidden words
    char *token;
    token=strtok(text," ");
    while (token!=NULL){
        flag=forbiddenWords(token);
        if(flag){
            printf("A forbidden word has been detected in the text. The accused will be brought to trial!\n");
            exit(0);
        }
        token=strtok(NULL," ");
    }

    printf("No forbidden words have been detected in the text. The accused may carry on.\n");

   return 0;
}