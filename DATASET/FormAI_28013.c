//FormAI DATASET v1.0 Category: Word Count Tool ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int wc = 1; // Initialize word count to 1 because first word doesn't have a space before it

    printf("Welcome to our awesome C Word Count Tool!\n\n");
    printf("Enter a sentence to count the words: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    // Traverse through the sentence character by character
    for(int i=0; sentence[i] != '\0'; i++) {
        if(sentence[i] == ' ') { // If a space is encountered, increment word count
            wc++;
        }
    }

    printf("\n************************************\n");
    printf("The sentence entered by you is:\n\n%s", sentence);
    printf("\n************************************\n");

    // Print word count
    printf("The number of words in the sentence is: %d\n", wc);
    printf("\nThank you for using our C Word Count Tool!\n\n");

    return 0;
}