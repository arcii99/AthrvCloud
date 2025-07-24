//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <string.h>

// Function to translate the alien language
void translate(char sentence[]) {

    // Dictionary of the alien language
    char dictionary[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    // Array to store the translation
    char translation[strlen(sentence)];

    // Iterating over each character of the sentence
    for(int i=0; i<strlen(sentence); i++) {

        // Keeping track of the character index in the dictionary
        int index = -1;

        // Searching for the character in the dictionary
        for(int j=0; j<26; j++) {
            if(sentence[i] == dictionary[j]) {
                index = j;
                break;
            }
        }

        // If character is in the dictionary, adding its translation to the result
        if(index >= 0) {
            translation[i] = dictionary[25 - index];
        }
        // If character is not in the dictionary, adding it as it is to the result
        else {
            translation[i] = sentence[i];
        }

    }

    // Printing the translated sentence
    printf("Translated sentence: %s\n", translation);

}

// Main function to take input and call the translate function
int main() {

    // Taking input from the user
    char inputSentence[100];
    printf("Enter the sentence in the alien language: ");
    scanf("%[^\n]%*c", inputSentence);

    // Calling the translate function to translate the sentence
    translate(inputSentence);

    return 0;
}