//FormAI DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10 // maximum number of words considered as spam
#define MAX_WORD_LENGTH 20 // maximum length of a single word
#define MAX_INPUT_LENGTH 100 // maximum length of input string

char spamWords[MAX_SPAM_WORDS][MAX_WORD_LENGTH] = {"free", "offer", "click", "buy", "discount"}; // preset array of spam words

int main() {
    printf("Welcome to the Spam Detection System!\n\n");

    char input[MAX_INPUT_LENGTH]; // container to hold user's input
    int spamCount = 0; // variable to keep track of spam word count

    printf("Please enter your message:\n");

    fgets(input, MAX_INPUT_LENGTH, stdin); // gets the input from the user

    // loop through the array of spam words
    for(int i = 0; i < MAX_SPAM_WORDS; i++) {
        char *spamWord = spamWords[i]; // gets the current spam word in the loop
        int wordLength = strlen(spamWord); // gets the length of the current spam word
        
        char *match = strstr(input, spamWord); // search for the current spam word in the user's input

        // keep searching for the current spam word as long as there is a match
        while (match != NULL) {

            spamCount++; // increment the spam count
            input[match - input] = '.'; // replace the detected spam word with a dot

            match = strstr(match + wordLength, spamWord); // update the match by searching for the current spam word again
        }
    }

    printf("\nSpam detection result for the input \"%s\":\n", input);
    if(spamCount > 0) {
        printf("This message contains %d spam words!", spamCount);
    } else {
        printf("This message does not contain any spam words. It's spam free!");
    }
    printf("\n");

    return 0;
}