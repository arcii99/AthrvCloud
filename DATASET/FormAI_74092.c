//FormAI DATASET v1.0 Category: Word Count Tool ; Style: active
#include<stdio.h>
#include<string.h>

//function to count words in a sentence
int countWords(char sentence[], int length) {
    int count = 1;  //initialize count to 1 since at least one word is there
    for(int i=0; i<length; i++) {
        if(sentence[i] == ' ') {  //if space is found, increment count
            count++;
        }
    }
    return count;
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);  //get input from user

    int sentenceLength = strlen(sentence);

    int wordCount = countWords(sentence, sentenceLength);

    printf("\nNumber of words in the sentence: %d\n", wordCount);

    return 0;
}