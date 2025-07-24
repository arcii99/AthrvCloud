//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <stdio.h>
#include <string.h>

/*
 * This program is a C Alien Language Translator
 * It can translate sentences from the C alien language into English language
 * and vice versa using a custom character mapping.
 * 
 * Here's how the mapping works:
 * 
 * C Alien Language:    A   B   C   D   E   F   G   H   I   J   K   L   M   N   O   P   Q   R   S   T   U   V   W   X   Y   Z
 * English Language:    !   #   @   $   %   ^   &   *   (   )   -   =   +   [   ]   {   }   ;   :   "   '   <   >   ,   .   /   ?
 * 
 * Note: Only uppercase English alphabets are supported in the mapping.
 * 
 * To use the translator, call the translate() function with the input string and its length.
 */

char translate_char(char c, int is_english) {
    if (is_english) {  // translating from English to C Alien Language
        switch(c) {
            case '!': return 'A';
            case '#': return 'B';
            case '@': return 'C';
            case '$': return 'D';
            case '%': return 'E';
            case '^': return 'F';
            case '&': return 'G';
            case '*': return 'H';
            case '(': return 'I';
            case ')': return 'J';
            case '-': return 'K';
            case '=': return 'L';
            case '+': return 'M';
            case '[': return 'N';
            case ']': return 'O';
            case '{': return 'P';
            case '}': return 'Q';
            case ';': return 'R';
            case ':': return 'S';
            case '"': return 'T';
            case '\'': return 'U';
            case '<': return 'V';
            case '>': return 'W';
            case ',': return 'X';
            case '.': return 'Y';
            case '/': return 'Z';
            case '?': return ' ';
            default: return c; // for all other characters
        }
    } else {  // translating from C Alien Language to English
        switch(c) {
            case 'A': return '!';
            case 'B': return '#';
            case 'C': return '@';
            case 'D': return '$';
            case 'E': return '%';
            case 'F': return '^';
            case 'G': return '&';
            case 'H': return '*';
            case 'I': return '(';
            case 'J': return ')';
            case 'K': return '-';
            case 'L': return '=';
            case 'M': return '+';
            case 'N': return '[';
            case 'O': return ']';
            case 'P': return '{';
            case 'Q': return '}';
            case 'R': return ';';
            case 'S': return ':';
            case 'T': return '"';
            case 'U': return '\'';
            case 'V': return '<';
            case 'W': return '>';
            case 'X': return ',';
            case 'Y': return '.';
            case 'Z': return '/';
            case ' ': return '?';
            default: return c; // for all other characters
        }
    }
}

void translate(char* input, int len, char* output, int is_english) {
    for (int i = 0; i < len; i++) {
        output[i] = translate_char(input[i], is_english);
    }
}

// Test function to demonstrate the translator
void test_translator() {
    char input[] = "C ALIEN LANGUAGE";
    int len = strlen(input);
    char output[len];
    
    printf("Original sentence: %s\n", input);
    
    // Translating from C Alien Language to English
    translate(input, len, output, 0);
    printf("Translated to English: %s\n", output);
    
    // Translating back to C Alien Language
    translate(output, len, input, 1); // In-place translation
    printf("Translated back to C Alien Language: %s\n", input);
}

int main() {
    test_translator();
    return 0;
}