//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate a given string in Alien Language
void translate(char* str, int n) {
    int freq[26] = {0};   // frequency array to store frequency of each character

    // calculate the frequency of each character in the given string
    for (int i = 0; i < n; i++) {
        freq[str[i] - 'a']++;
    }

    // generate the alien language translation
    char alienLang[26] = {0};
    for (int i = 0; i < 26; i++) {
        int maxFreq = 0;
        char maxChar;

        // find the character with maximum frequency
        for (int j = 0; j < 26; j++) {
            if (freq[j] > maxFreq) {
                maxFreq = freq[j];
                maxChar = 'a' + j;
            }
        }

        // add the maximum frequency character to the alien language translation
        alienLang[i] = maxChar;
        freq[maxChar - 'a'] = 0;
    }

    // display the alien language translation and the original string
    printf("The Alien Language Translation for \"%s\" is:\n", str);
    printf("%s\n", alienLang);
}

int main() {
    char str[101];

    printf("Enter a string in Alien Language (lowercase letters only, max length 100): ");
    scanf("%s", str);

    int n = strlen(str);
    translate(str, n);

    return 0;
}