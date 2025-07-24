//FormAI DATASET v1.0 Category: Spell checking ; Style: accurate
#include <stdio.h>
#include <string.h>

int main() {
    char dict[100][100] = {"apple", "banana", "orange", "mango", "peach", "grape", "pear", "kiwi"};
    int dict_size = 8; // Number of words in the dictionary
    
    char input[100];
    printf("Enter a word: ");
    scanf("%s", input);
    
    int found = 0; // Variable to check if the word is found in the dictionary
    
    // Loop through each word in the dictionary and check if the input matches
    for(int i = 0; i < dict_size; i++) {
        if(strcmp(dict[i], input) == 0) {
            printf("%s is spelled correctly.\n", input);
            found = 1;
            break;
        }
    }
    
    // If the word is not found in the dictionary, try to suggest corrections
    if(!found) {
        printf("%s is spelled incorrectly.\n", input);
        
        // Loop through each word in the dictionary and compare with the input
        for(int i = 0; i < dict_size; i++) {
            int diff = 0; // Variable to count the number of differences between the input and the dictionary word
            
            // Loop through each character in both the input and dictionary word
            for(int j = 0; j < strlen(input) && j < strlen(dict[i]); j++) {
                if(input[j] != dict[i][j]) {
                    diff++;
                }
            }
            
            // If the number of differences is less than 2, suggest the word as correction
            if(diff < 2) {
                printf("Did you mean %s?\n", dict[i]);
            }
        }
    }
    
    return 0;
}