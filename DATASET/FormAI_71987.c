//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {
    char alien[1000]; // Define the maximum length of the alien language input
    char english[1000]; // Define the maximum length of the translated English output
    int length, i;

    printf("Enter the alien language to translate: "); 
    scanf("%s", alien); // Getting the alien language input from the user

    length = strlen(alien);

    // Translating the alien language to English
    for(i=0; i<length; i++) {
        if(alien[i] == '.') // The dot represents the letter 'A'
            english[i] = 'A';
        else if(alien[i] == '-') // The line represents the letter 'E'
            english[i] = 'E';
    }
    
    english[i] = '\0'; // Add a null character to the end of the translated string

    printf("The translated English language is: %s\n", english);

    return 0;
}