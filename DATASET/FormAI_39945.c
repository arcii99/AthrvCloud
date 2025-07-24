//FormAI DATASET v1.0 Category: Text Summarizer ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char passage[1000];
    printf("Enter the text:\n");
    fgets(passage,sizeof(passage),stdin);
    int length = strlen(passage);
    if (passage[length-1] == '\n') {
        passage[length-1] = '\0'; // remove new line character
    }

    char *token = strtok(passage, " "); // get the first token
    int sum = 0;
    int count = 0;
    while (token != NULL) {
        sum += strlen(token); // add the length of each token
        count++; // increment the count of tokens
        token = strtok(NULL, " "); // get the next token
    }
    double avg = (double)sum/count; // calculate the average token length

    printf("The average token length is: %f\n",avg);
    printf("\n");

    printf("The summary of the text is:\n");

    strtok(passage, "."); // get the first sentence
    int sentence_num = 1;
    while (token != NULL && sentence_num <= 3) {
        printf("%s.\n",token); // print the sentence
        sentence_num++;
        token = strtok(NULL, ".");
    }

    return 0;
}