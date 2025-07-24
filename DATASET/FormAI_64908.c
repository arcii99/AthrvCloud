//FormAI DATASET v1.0 Category: Text Summarizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* summarize(char* text, int textLength, int summaryLength){

    if (textLength < 1){
        printf("No Text Found. Try again buddy!");
        return NULL;
    }
    if (summaryLength < 1){
        printf("Summary length too short. Try again buddy!");
        return NULL;
    }

    int i, j, k, summaryIndex = 0, count=0, foundThe = 0;

    char* summary = (char*) malloc(summaryLength * sizeof(char));

    for (i = 0; i < summaryLength; i++){
        if (text[i] != ' ') {
            j = i;
            break;
        }
    }

    for (; i < textLength; i++){
        if (text[i] == ' ' && text[i+1] != ' '){
            count += 1;
            if (count == 1){
                k = i+1;
                if (text[i+1] == 't' && text[i+2] == 'h' && text[i+3] == 'e' && foundThe == 0){
                    foundThe = 1;
                }
            }
        }
        if (i - j >= 3 && count >= 4){
            if (foundThe == 1){
                for (; k <= i; k++){
                    summary[summaryIndex] = text[k];
                    summaryIndex += 1;
                }
                summary[summaryIndex] = ' ';
                summaryIndex += 1;
                foundThe = 0;
            }
            count = 0;
            j = i+1;
            if (summaryIndex >= summaryLength-3){
                break;
            }
        }
    }
    summary = realloc(summary, strlen(summary)+1);
    return summary;
}

int main(){

    printf("Enter the Text: ");
    char myText[1000];
    fgets(myText, sizeof(myText), stdin);

    int textLength = strlen(myText), summaryLength, len;
    printf("Enter the length of Summary: ");
    scanf("%d",&summaryLength);

    char* summaryText = summarize(myText, textLength, summaryLength);

    if (summaryText != NULL){
        len = strlen(summaryText);
        if (len < summaryLength/2){
            printf("Seriously, This is your summary! : %s", summaryText);
        } else {
            printf("Voilà, Your Summary: %s...", summaryText);
        }
    }
    return 0;
}