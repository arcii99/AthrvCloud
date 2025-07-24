//FormAI DATASET v1.0 Category: Text processing ; Style: imaginative
#include <stdio.h>
#include <string.h>

//define a function to count number of words in a given sentence
int count_words(char sentence[]) {
    int count = 0;
    int i = 0;

    while(sentence[i] != '\0') {
        if(sentence[i] == ' ') {  //if space character is found
            count++;  //increment word count
        }
        i++;
    }

    return count+1;  //return the final word count
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);  //read the sentence entered by user

    //remove trailing newline character from the sentence
    if(sentence[strlen(sentence)-1] == '\n') {
        sentence[strlen(sentence)-1] = '\0';
    }

    printf("\nEntered sentence: %s\n", sentence);

    //call the count_words function and print the final word count
    int word_count = count_words(sentence);
    printf("Total words in the sentence: %d\n", word_count);

    return 0;
}