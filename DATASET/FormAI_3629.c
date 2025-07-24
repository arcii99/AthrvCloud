//FormAI DATASET v1.0 Category: Spell checking ; Style: detailed
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// function to check if a character is a letter
bool is_letter(char c) {
    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

// function to check if a word is spelled correctly
bool spell_check(char* word) {
    // iterate through each character in the word
    for (int i = 0; word[i] != '\0'; i++) {
        // if a character is not a letter, skip it
        if (!is_letter(word[i])) {
            continue;
        }
        
        // convert the letter to lowercase
        char c = tolower(word[i]);
        
        // check if the character is a vowel or consonant
        bool is_vowel = c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        
        // if the first letter is a consonant and the second letter is a vowel,
        // the word is likely misspelled (e.g. "fisrt" instead of "first")
        if (i == 0 && !is_vowel && is_letter(word[i+1]) && tolower(word[i+1]) == 'a') {
            return false;
        }
        
        // if a letter is repeated more than twice in a row, the word is likely
        // misspelled (e.g. "booooooook" instead of "book")
        if (i >= 2 && c == tolower(word[i-1]) && c == tolower(word[i-2])) {
            return false;
        }
        
        // if two identical adjacent letters are both vowels or both consonants,
        // the word is likely misspelled (e.g. "poolle" instead of "polle")
        if (i >= 1) {
            bool is_vowel_prev = tolower(word[i-1]) == 'a' || tolower(word[i-1]) == 'e' || tolower(word[i-1]) == 'i' || tolower(word[i-1]) == 'o' || tolower(word[i-1]) == 'u';
            if (is_vowel_prev && is_vowel) {
                return false;
            }
            if (!is_vowel_prev && !is_vowel) {
                return false;
            }
        }
    }
    
    // if we have made it this far, the word is likely spelled correctly
    return true;
}

int main() {
    // test the spell_check function
    printf("%d\n", spell_check("hello")); // true
    printf("%d\n", spell_check("wrogn")); // false
    printf("%d\n", spell_check("fisrt")); // false
    printf("%d\n", spell_check("booooooook")); // false
    printf("%d\n", spell_check("poolle")); // false
    printf("%d\n", spell_check("polle")); // true
    
    return 0;
}