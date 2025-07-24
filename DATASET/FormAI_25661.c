//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    int i, j, length;
    
    printf("Enter the text you want to translate in the Cat Language:\n");
    fgets(text, sizeof(text), stdin); // Read input string from user
    
    length = strlen(text);
    
    // Replace all vowels with "meow"
    for (i = 0; i < length; i++) {
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u') {
            text[i] = 'm';
            strcat(text, "eow");
            length += 2;
        }
    }
    
    // Replace all spaces with "purrs"
    for (j = 0; j < length; j++) {
        if (text[j] == ' ') {
            text[j] = 'p';
            strcat(text, "urrs");
            length += 3;
        }
    }
    
    printf("\nTranslated text: %s\n", text); // Print the translated text
    
    return 0;
}