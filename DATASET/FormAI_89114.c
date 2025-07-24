//FormAI DATASET v1.0 Category: Text Summarizer ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Global Variable
char summary[1000]=""; 

//Function to generate summary
void summarize(char* text){
    printf("Summarizing the Text...\n");
    char *token = strtok(text, " ");
    int length=0;
    while (token != NULL) {
        length=strlen(summary);
        if(length+strlen(token)>=950) break;
        strncat(summary,token,strlen(token));
        strncat(summary," ",1);
        token = strtok(NULL, " ");
    }
}

int main(){

    //Variable Declaration
    char text[10000];

    //Taking user inputs
    printf("Enter the text to be summarized:");
    fgets(text,sizeof(text),stdin);

    //Generating summary and storing in global variable
    summarize(text);

    //Printing the summary
    printf("The summarized text is:\n%s",summary);

    return 0;
}