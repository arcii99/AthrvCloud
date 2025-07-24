//FormAI DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define WORD_LEN 100

void checkSpelling(char words[][WORD_LEN], int size, char dictionary[][WORD_LEN], int dictSize) {
    int found = 0;
    
    // loop through each word in the words array
    for(int i=0; i<size; i++) {
        found = 0;
        
        // loop through each word in the dictionary
        for(int j=0; j<dictSize; j++) {
            // compare the words ignoring case
            if(strcasecmp(words[i], dictionary[j]) == 0) {
                found = 1;
                break;
            }
        }
        
        // display misspelled words
        if(!found) {
            printf("%s is misspelled\n", words[i]);
        }
    }
}

int main() {
    char words1[5][WORD_LEN] = {"Hello", "world", "This", "is", "dog"};
    char dict1[5][WORD_LEN] = {"hello", "world", "this", "is", "a"};
    
    checkSpelling(words1, 5, dict1, 5);
    
    char words2[5][WORD_LEN] = {"How", "r", "u", "2day", "?"};
    char dict2[7][WORD_LEN] = {"How", "are", "you", "today", "doing", "anything", "interesting"};
    
    checkSpelling(words2, 5, dict2, 7);
    
    return 0;
}