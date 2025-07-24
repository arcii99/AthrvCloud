//FormAI DATASET v1.0 Category: Text Summarizer ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char text[500];
    char summary[100];
    int count = 0, index = 0;

    printf("Welcome to the Medieval Text Summarizer!\n");
    printf("Please enter the text you want summarized:\n");
    fgets(text, sizeof(text), stdin);

    for(int i=0; i<strlen(text); i++){
        if(isalpha(text[i])){
            count++;
        }
        if(text[i] == '.' || text[i] == '?' || text[i] == '!'){
            if(count > 10){
                summary[index++] = text[i];
                summary[index++] = ' ';
            }
            count = 0;
        }
    }

    printf("Here is the summary of your text:\n");
    printf("%s\n", summary);

    return 0;
}