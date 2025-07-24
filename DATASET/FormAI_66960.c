//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

// Function to translate an input C-string in Alien language
void translateAL(char* str) {
    // Mapping of alien letters with equivalent English letters
    char letters[27] = "#ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char englishLetters[27] = " !ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // Check if input string contains a valid sequence of Alien words
    for (int i=0; i<strlen(str); i++) {
        // Get current letter and its position in the mapping array
        char current = str[i];
        int index = -1;
        for (int j=0; j<27; j++) {
            if (letters[j] == current) {
                index = j;
                break;
            }
        }
        
        // If current letter is not found in the mapping array, break the loop
        if (index == -1) {
            printf("\nInvalid Alien word found! Aborting translation...\n");
            return;
        }
    }
    
    // Translate each Alien word to English
    int wordStart = 0;
    int wordEnd = 0;
    for (int i=0; i<strlen(str); i++) {
        // Get current letter and its position in the mapping array
        char current = str[i];
        int index = -1;
        for (int j=0; j<27; j++) {
            if (letters[j] == current) {
                index = j;
                break;
            }
        }
        
        // If current letter is not found in the mapping array, translate the current word
        if (index == -1) {
            int wordLength = wordEnd - wordStart;
            char word[wordLength + 1];
            strncpy(word, &str[wordStart], wordLength);
            word[wordLength] = '\0';
            
            // Translate the current word from Alien to English
            for (int j=0; j<strlen(word); j++) {
                char letter = word[j];
                int letterIndex = -1;
                for (int k=0; k<27; k++) {
                    if (letters[k] == letter) {
                        letterIndex = k;
                        break;
                    }
                }
                
                printf("%c", englishLetters[letterIndex]);
            }
            
            // Reset the word start and end indices
            wordStart = i + 1;
            wordEnd = i + 1;
            
            // Print a space after each word
            printf(" ");
        }
        else {
            wordEnd++;
        }
    }
}

// Driver code
int main() {
    char alienStr[] = "#BACAA#DAB";
    
    printf("Alien string: %s\n", alienStr);
    printf("Translated string: ");
    translateAL(alienStr);
    
    return 0;
}