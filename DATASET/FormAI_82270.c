//FormAI DATASET v1.0 Category: Text processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char text[200];
    printf("Hello there! I'm the Text Wizard!\n");
    printf("Type any text and I'll make it funnier: ");
    fgets(text, sizeof(text), stdin);

    //Adding exclamation points
    for(int i = 0; i < strlen(text); i++){
        if(text[i] == '.' || text[i] == '?'){
            text[i] = '!';
        }
    }

    //Replacing words
    char* word = strtok(text, " ");
    while(word != NULL){
        if(strcmp(word, "sad") == 0){
            strcpy(word, "happy");
        }
        if(strcmp(word, "boring") == 0){
            strcpy(word, "exciting");
        }
        if(strcmp(word, "normal") == 0){
            strcpy(word, "weird");
        }
        word = strtok(NULL, " ");
    }

    //Flipping text
    for(int i = strlen(text) - 2; i >= 0; i--){
        printf("%c", text[i]);
    }
    printf("\n");

    //Randomly capitalizing text
    for(int i = 0; i < strlen(text); i++){
        if(rand() % 2 == 1){
            text[i] = toupper(text[i]);
        }
    }
    printf("Here's your new text: %s", text);

    return 0;
}