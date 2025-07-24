//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: careful
#include <stdio.h>
#include <string.h>

// Function to translate C Cat Language to English
void cCatTranslator(char str[]) {
    // Define the dictionary for C Cat Language
    char ccatDict[26][2] = {
        {'a', 'e'}, {'b', 'p'}, {'c', 'k'}, {'d', 't'},
        {'e', 'i'}, {'f', 'r'}, {'g', 'q'}, {'h', 'x'},
        {'i', 'u'}, {'j', 'z'}, {'k', 'c'}, {'l', 'v'},
        {'m', 'w'}, {'n', 'y'}, {'o', 'a'}, {'p', 'b'},
        {'q', 'g'}, {'r', 'f'}, {'s', 'l'}, {'t', 'd'},
        {'u', 'i'}, {'v', 'o'}, {'w', 'm'}, {'x', 'h'},
        {'y', 'n'}, {'z', 'j'}
    };
    
    int len = strlen(str);
    int i, j;
    
    for (i = 0; i < len; i++) {
        char ccatChar = str[i];
        int found = 0;
        for (j = 0; j < 26; j++) {
            if (ccatDict[j][0] == ccatChar) {
                putchar(ccatDict[j][1]);
                found = 1;
                break;
            }
        }
        if (!found) {
            putchar(ccatChar);
        }
    }
}

int main() {
    char ccatStr[100];
    printf("Enter a sentence in C Cat Language: ");
    fgets(ccatStr, 100, stdin);
    
    printf("Translated to English: ");
    cCatTranslator(ccatStr);
    
    return 0;
}