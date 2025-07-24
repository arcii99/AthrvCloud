//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: futuristic
#include <stdio.h>
#include <string.h>

// Define alien language characters from A to F
const char* alien_chars[] = {"A", "B", "C", "D", "E", "F"};

// Define the equivalent English words for each alien character
const char* english_words[] = {"Hello", "World", "I", "am", "a", "chatbot"};

// Function to translate a single alien character to English
char* translate_single_char(char* alien_char) {
    for(int i=0; i<6; i++) {
        if(strcmp(alien_chars[i], alien_char) == 0) {
            return english_words[i];
        }
    }
    return "Unknown alien character";
}

// Function to translate a string of alien characters to English
void translate_to_english(char* alien_string) {
    int len = strlen(alien_string);
    char translated_string[100] = "";
    for(int i=0; i<len/2; i++) {
        char* alien_char = (char*) malloc(sizeof(char) * 2);
        strncpy(alien_char, &alien_string[2*i], 2);
        alien_char[2] = '\0';
        char* english_word = translate_single_char(alien_char);
        strcat(translated_string, english_word);
        strcat(translated_string, " ");
    }
    printf("Alien: %s\nEnglish: %s\n", alien_string, translated_string);
}

int main() {
    // Test the translation function with some example inputs
    char* input1 = "ECBEFF";
    char* input2 = "ADAFBDBECCDDEEFF";
    char* input3 = "DDBBDABA";
    translate_to_english(input1);
    translate_to_english(input2);
    translate_to_english(input3);
    return 0;
}