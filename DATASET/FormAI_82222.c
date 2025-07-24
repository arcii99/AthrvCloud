//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char alienLanguage[100], translated[100];
    int i, length;

    // Get the alien language input from the user
    printf("Please enter the alien language: ");
    scanf("%s", alienLanguage);

    // Translate the alien language to human language
    length = strlen(alienLanguage);
    for(i=0; i<length; i++) {
        if(alienLanguage[i] == '1') {
            translated[i] = 'A';
        } else if(alienLanguage[i] == '2') {
            translated[i] = 'B';
        } else if(alienLanguage[i] == '3') {
            translated[i] = 'C';
        } else if(alienLanguage[i] == '4') {
            translated[i] = 'D';
        } else if(alienLanguage[i] == '5') {
            translated[i] = 'E';
        } else if(alienLanguage[i] == '6') {
            translated[i] = 'F';
        } else if(alienLanguage[i] == '7') {
            translated[i] = 'G';
        } else if(alienLanguage[i] == '8') {
            translated[i] = 'H';
        } else if(alienLanguage[i] == '9') {
            translated[i] = 'I';
        } else if(alienLanguage[i] == '0') {
            translated[i] = 'J';
        } else {
            translated[i] = alienLanguage[i];
        }
    }
    translated[length] = '\0';

    // Print out the translated language
    printf("The human equivalent is: %s\n", translated);

    return 0;
}