//FormAI DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000] = "The game is afoot! Come, Watson, come! The drawing-room awaits us.";

    // Find length of sentence
    int length = strlen(sentence);

    // Count number of spaces in sentence
    int num_spaces = 0;
    for(int i=0; i<length; i++) {
        if(sentence[i] == ' ') {
            num_spaces++;
        }
    }

    // Allocate array of pointers for words in sentence
    char *words[num_spaces+1];

    // Tokenize sentence into words
    char *token = strtok(sentence, " ");
    int i = 0;
    while(token != NULL) {
        words[i++] = token;
        token = strtok(NULL, " ");
    }

    // Find the longest and shortest words in sentence
    char *longest_word = words[0];
    char *shortest_word = words[0];
    for(int j=0; j<i; j++) {
        if(strlen(words[j]) > strlen(longest_word)) {
            longest_word = words[j];
        }
        if(strlen(words[j]) < strlen(shortest_word)) {
            shortest_word = words[j];
        }
    }

    // Print out analysis
    printf("The sentence is: %s\n", sentence);
    printf("There are %d words in the sentence.\n", i);
    printf("The longest word is: %s\n", longest_word);
    printf("The shortest word is: %s\n", shortest_word);

    // Replace "Watson" with "Sherlock" in sentence
    char search_word[] = "Watson";
    char replacement[] = "Sherlock";
    char *ptr = strstr(sentence, search_word);
    while(ptr != NULL) {
        int index = ptr - sentence;
        memmove(sentence+index+strlen(replacement), sentence+index+strlen(search_word), length-index-strlen(search_word)+1);
        memcpy(sentence+index, replacement, strlen(replacement));
        ptr = strstr(sentence, search_word);
    }

    // Print out final sentence
    printf("\nThe final sentence is: %s\n", sentence);

    return 0;
}