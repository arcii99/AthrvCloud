//FormAI DATASET v1.0 Category: Text Summarizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    char summary[1000];
    int i,j=0;
    int length, summaryLength=0;

    printf("Enter the text you want to summarize:\n");
    fgets(input,1000,stdin);
    
    length = strlen(input);

    if (length <= 100) {
        printf("Text is too short to summarize.");
        return 0;
    }

    for(i=0; i < length; i++) {
        if(input[i] == ' ') {
            summary[j] = input[i];
            summaryLength++;
            while(input[i] == ' '){
                i++;
            }
            i--;
        }
        else {
            summary[j] = input[i];
            summaryLength++;
        }

        if(summaryLength >= 75){
            break;
        }

        j++;
    }

    summary[j] = '\0';

    printf("\nSummary:\n%s",summary);

    return 0;
}