//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000
#define MAX_SENTENCES 100

struct Sentence {
    char content[MAX_STRING_LENGTH];
    int length;
};

int main() {
    char input[MAX_STRING_LENGTH];
    char *ptr = input;
    struct Sentence sentences[MAX_SENTENCES];
    int sentence_count = 0;
    
    printf("Welcome to the Cyberpunk Text Summarizer.\n");
    printf("Please input your text and press enter:\n");
    
    fgets(input, MAX_STRING_LENGTH, stdin);
    
    while (*ptr) {
        if (*ptr == '.' || *ptr == '?' || *ptr == '!') {
            sentence_count++;
            ptr++;
        }
        else {
            ptr++;
        }
    }
    
    ptr = input;
    
    for (int i = 0; i < sentence_count; i++) {
        int length = 0;
        char *start = ptr;
        while (*ptr != '.' && *ptr != '?' && *ptr != '!' && *ptr != '\0') {
            ptr++;
            length++;
        }
        
        if (length > 0) {
            strncpy(sentences[i].content, start, length);
            sentences[i].length = length;
        }
        ptr++; 
    }
    
    printf("Here is your summarized text:\n");
    
    for (int i = 0; i < sentence_count; i++) {
        int word_count = 0;
        int uppercase_count = 0;
        int lowercase_count = 0;
        int digit_count = 0;
        int special_count = 0;
        char *ptr = sentences[i].content;
        
        while (*ptr) {
            if (isalpha(*ptr)) {
                if (isupper(*ptr)) {
                    uppercase_count++;
                }
                else {
                    lowercase_count++;
                }
                word_count++;
            }
            else if (isdigit(*ptr)) {
                digit_count++;
            }
            else if (!isspace(*ptr)) {
                special_count++;
            }    
            ptr++;
        }
        
        if (word_count >= 10 && uppercase_count > lowercase_count && digit_count == 0 && special_count == 0) {
            printf("%s.\n", sentences[i].content);
        }       
    }       
    return 0;
}