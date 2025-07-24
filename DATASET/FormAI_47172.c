//FormAI DATASET v1.0 Category: Word Count Tool ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char sentence[100];
    int wordcount = 0;
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin); //read the sentence from user input

    for(int i=0; sentence[i]!='\0'; i++) //loop through each character in the sentence
    {
        if(sentence[i] == ' ' && sentence[i+1] != ' ') //if a space is detected and the next character is not a space (to avoid multiple spaces between words)
        {
            wordcount++; //increment word count if a space is detected
        }
    }
    //If the sentence does not end with a space then atleast one word is present after the last space in the sentence
    if(sentence[strlen(sentence)-2] != ' ')
    {
        wordcount++; //increment the word count for the final word in the sentence
    }
    printf("The sentence contains %d words\n", wordcount);
    return 0;
}