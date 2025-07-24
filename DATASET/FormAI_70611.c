//FormAI DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int check_spelling(char word[]) {
    char dict[100][20] = {"hello","world","program","spellcheck","snippets","example","unique","style","Claude","Shannon","instructions","minimum","lines","creative","compile","runs","errors"}; // dictionary of words
    int dict_size = 17;
    for(int i=0; i<dict_size; i++) {
        if(strcmp(dict[i], word) == 0) { // check if word matches with a dictionary word
            return 1; // word found in dictionary
        }
    }
    return 0; // word not found in dictionary
}

int main() {
    char text[1000];
    printf("Enter the text to be spell checked:\n");
    fgets(text, 1000, stdin); // read input text
    int len = strlen(text);
    if(text[len-1] == '\n') { // remove newline character from input text
        text[len-1] = '\0';
    }
    char word[20];
    char output[1000] = "";
    int i=0, j=0, is_word=0;
    while(text[i] != '\0') {
        if(isalpha(text[i])) { // check if character is alphabetic
            word[j++] = tolower(text[i]); // convert character to lowercase and add to word
            is_word = 1; // set flag for word
        }
        else {
            if(is_word) { // check if previous characters form a word
                word[j] = '\0'; // add null terminator to word
                if(check_spelling(word)) { // check spelling of word
                    strcat(output, word); // add word to output string
                }
                else {
                    char suggestions[100] = ""; // string for storing suggestions
                    printf("The spelling of '%s' is incorrect. Suggestions: ", word);
                    for(int k=0; k<strlen(word); k++) {
                        char temp = word[k];
                        for(char ch='a'; ch<='z'; ch++) { // loop through all alphabets
                            word[k] = ch; // replace character with an alphabet
                            if(check_spelling(word)) { // check spelling of modified word
                                if(strlen(suggestions) > 0) {
                                    strcat(suggestions, ", ");
                                }
                                strcat(suggestions, word); // add word to suggestions
                            }
                        }
                        word[k] = temp; // revert back to original character
                    }
                    if(strlen(suggestions) > 0) {
                        printf("%s\n", suggestions);
                    }
                    else { // no suggestions found
                        printf("None\n");
                    }
                }
                strcat(output, " "); // add space after word
                j = 0; // reset index for word
                is_word = 0; // reset flag for word
            }
            else { // character is not alphabetic and does not form a word
                strcat(output, &text[i]); // add character to output string
            }
        }
        i++;
    }
    if(is_word) { // check if last word was pending
        word[j] = '\0'; // add null terminator to word
        if(check_spelling(word)) { // check spelling of word
            strcat(output, word); // add word to output string
        }
        else {
            char suggestions[100] = ""; // string for storing suggestions
            printf("The spelling of '%s' is incorrect. Suggestions: ", word);
            for(int k=0; k<strlen(word); k++) {
                char temp = word[k];
                for(char ch='a'; ch<='z'; ch++) { // loop through all alphabets
                    word[k] = ch; // replace character with an alphabet
                    if(check_spelling(word)) { // check spelling of modified word
                        if(strlen(suggestions) > 0) {
                            strcat(suggestions, ", ");
                        }
                        strcat(suggestions, word); // add word to suggestions
                    }
                }
                word[k] = temp; // revert back to original character
            }
            if(strlen(suggestions) > 0) {
                printf("%s\n", suggestions);
            }
            else { // no suggestions found
                printf("None\n");
            }
        }
        strcat(output, " "); // add space after word
    }
    printf("Corrected text:\n%s\n", output); // print corrected text
    return 0;
}