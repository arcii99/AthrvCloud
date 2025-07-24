//FormAI DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(){
    char sentence[1000];
    int wordCount = 0, charCount = 0;
    double avgLength;
    printf("Enter the sentence: ");
    fgets(sentence, 1000, stdin); //Taking input from user
    //Removing newline character from the sentence
    int len = strlen(sentence);
    if(sentence[len-1] == '\n'){
        sentence[len-1] = '\0';
    }
    //Counting words and characters in the sentence
    for(int i=0; i<len; i++){
        if(isspace(sentence[i]) || sentence[i] == '\0'){
            wordCount++;
        }
        else{
            charCount++;
        }
    }
    //Calculating average word length
    avgLength = (double)charCount/(double)wordCount;
    printf("\nNumber of words: %d\n", wordCount);
    printf("Number of characters: %d\n", charCount);
    printf("Average word length: %.2lf\n", avgLength);
    return 0;
}