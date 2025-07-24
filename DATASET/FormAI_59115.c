//FormAI DATASET v1.0 Category: Text Summarizer ; Style: detailed
#include<stdio.h>
#include<string.h>
#define MAX 100

char* summarize(char* text,int len){

    char summary[MAX] = ""; //to store the summary of the text
    int i = 0;

    //loop to find the end of the sentence
    while(i<len){

        //to check for the presence of a sentence and its end
        if(text[i] == '.' || text[i] == '?' || text[i] == '!'){ 
            summary[strlen(summary)] = text[i]; //adding the end of the sentence in the summary
            summary[strlen(summary)] = '\n'; //adding a newline character in the summary
        }
        i++;
    }
    summary[strlen(summary)] = '\0';//adding null character to the end of the summary
    return summary;
}

int main(){
    char text[MAX];
    printf("Enter the text to summarize: ");
    fgets(text,MAX,stdin); //inputting the text to summarize
    int len = strlen(text);
    char* summary = summarize(text,len);
    printf("Summary:\n%s",summary); //displaying the summary
    return 0;
}