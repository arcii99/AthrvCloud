//FormAI DATASET v1.0 Category: Text processing ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    int vowels = 0, consonants = 0, words = 0;
    
    printf("Hark! What message would'st thou like to send?\n");
    fgets(text, sizeof(text), stdin);
    
    for (int i = 0; i < strlen(text); i++) {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            // count vowels and consonants
            if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' ||
                text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (text[i] == ' ' || text[i] == '\n') {
            // count words
            words++;
        }
    }
    
    // add last word if sentence doesn't end with space
    if (text[strlen(text) - 1] != ' ' && text[strlen(text) - 1] != '\n') {
        words++;
    }
    
    printf("Your message contains %d vowels, %d consonants, and %d words in total.\n", vowels, consonants, words);
    
    return 0;
}