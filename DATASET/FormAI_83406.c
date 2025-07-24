//FormAI DATASET v1.0 Category: Text processing ; Style: cheerful
/* Wow, hello there! Welcome to my text processing program!
 * This program is going to be your best friend! It will help you process any text you like!
 * So just sit back, relax, and let's start processing! */

#include <stdio.h>

int main() {
    char text[1000], processed_text[1000];
    int i, j, k, words = 0;

    printf("Hi! What text would you like to process today? ");
    fgets(text, sizeof(text), stdin);

    // Counting number of words in the text
    for(i = 0; text[i] != '\0'; i++) {
        if(text[i] == ' ' && text[i+1] != ' ') {
            words++;
        }
    }

    // Processing the text
    for(i = 0, k = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            processed_text[k++] = text[i];
            processed_text[k++] = ' ';
        } else {
            processed_text[k++] = text[i];
        }
    }

    // Printing the processed text
    printf("\nWoohoo! Your text has been successfully processed! Here it is:\n");
    printf("%s\n", processed_text);

    // Printing the number of words in the text
    printf("\nAnd guess what? Your text has %d words in it! Cool, right? :)\n", words);

    return 0;
}

/* Tadaaa!! That's the end of the program! 
 * Wasn't that fun? I hope you enjoyed processing your text with me!
 * Don't hesitate to come back whenever you need some text processing done!
 * Bye for now! */