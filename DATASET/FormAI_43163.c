//FormAI DATASET v1.0 Category: Word Count Tool ; Style: mathematical
#include <stdio.h>
#include <string.h>

// Function to count the total number of words in a given sentence
int countWords(char* sentence) {
    int count = 0, i;
    int len = strlen(sentence);

    // Loop through the sentence
    for(i=0; i<len; i++) {
        // If current character is a space, increment the word count
        if(sentence[i] == ' ') {
            count++;
        }
    }

    // Add 1 to the count to include the last word in the sentence
    count++;

    return count;
}

int main() {
    char sentence[1000];

    // Take input sentence from the user
    printf("Enter a sentence: ");
    gets(sentence);

    // Call the function to count words and print the result
    printf("Word count of the sentence is: %d", countWords(sentence));

    return 0;
}