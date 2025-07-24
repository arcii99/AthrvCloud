//FormAI DATASET v1.0 Category: Word Count Tool ; Style: accurate
#include <stdio.h>
#include <string.h>

int wordCount(char* sentence);

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin); // getting input from user using fgets function
    int count = wordCount(sentence); // calling wordCount function to count the number of words in the sentence
    printf("Number of words in the sentence: %d", count);
    return 0;
}

int wordCount(char* sentence) {
    int count = 0, i=0;
    while(sentence[i] != '\0') {
        if(sentence[i] == ' ' && sentence[i+1] != ' ' && sentence[i+1] != '\0') { // checking if the current character is a space and the next character is not a space or a null character
            count++;
        }
        i++;
    }
    return count+1; // adding 1 to count as there will be one extra word after the last space
}