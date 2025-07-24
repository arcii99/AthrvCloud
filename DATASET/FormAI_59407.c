//FormAI DATASET v1.0 Category: Text Summarizer ; Style: visionary
#include<stdio.h>
#include<string.h>

int main()
{
    char text[30], summary[10];
    int length, summaryLength, i, j = 0, k = 0;

    printf("Enter the text to summarize: ");
    scanf("%s", text);

    length = strlen(text);

    printf("\nEnter the length of summary (less than %d): ", length+1);
    scanf("%d", &summaryLength);

    while(text[i] != '\0') {

        //skip spaces
        while(text[i] == ' ' || text[i] == '\t' || text[i] == '\n') {
            i++;
        }

        //copying non-space character
        if(j < summaryLength) {
            summary[k] = text[i];
            k++;
        }
        j++;
        i++;
    }

    summary[k] = '\0';  //end the summary string with null character

    printf("\nSummary: %s\n\n", summary);

    return 0;
}