//FormAI DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100]; // declare a character array to hold the sentence
    int count = 0; // keep track of the number of words in the sentence
    char *token; // declare a pointer to hold each word in the sentence
    
    // ask user to enter a sentence
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin); // use fgets to read the sentence from stdin
    
    // use strtok to split the sentence into individual words
    token = strtok(sentence, " ");
    while(token != NULL) {
        count++;
        printf("%d: %s\n", count, token);
        token = strtok(NULL, " ");
    }
    
    // use strstr to find a specific word in the sentence
    char *result = strstr(sentence, "example");
    if(result != NULL) {
        printf("The word 'example' was found in the sentence.\n");
    } else {
        printf("The word 'example' was not found in the sentence.\n");
    }
    
    // use strncpy to copy a part of the sentence into a new string
    char newSentence[50];
    strncpy(newSentence, sentence, 15); // copy the first 15 characters of the sentence
    printf("The first 15 characters of the sentence are: %s\n", newSentence);
    
    // use strncat to concatenate two strings with a limit on the number of characters
    char greeting[30] = "Hello, ";
    strncat(greeting, "world!", 6); // concatenate "world!" with a limit of 6 characters
    printf("%s\n", greeting);
    
    return 0;
}