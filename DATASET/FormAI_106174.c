//FormAI DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_to_uppercase(char *string) {
    int i = 0;
    while(string[i]) {
        string[i] = toupper(string[i]);
        i++;
    }
}

void replace_word(char *string, char *old_word, char *new_word) {
    char *word_position = strstr(string, old_word);
    if (word_position == NULL) {
        printf("Could not find '%s' in string\n", old_word);
    }
    else {
        size_t old_length = strlen(old_word);
        size_t new_length = strlen(new_word);
        size_t tail_length = strlen(word_position + old_length);
        memmove(word_position + new_length, word_position + old_length, tail_length + 1);
        memcpy(word_position, new_word, new_length);
    }
}

int main() {
    char string[100] = "Hello, world! This is a test string.";
    char word_to_replace[20] = "test";
    char new_word[20] = "example";
    
    printf("Original string: %s\n", string);
    convert_to_uppercase(string);
    printf("String in uppercase: %s\n", string);
    replace_word(string, word_to_replace, new_word);
    printf("String with '%s' replaced by '%s': %s\n", word_to_replace, new_word, string);

    return 0;
}