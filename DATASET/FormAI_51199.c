//FormAI DATASET v1.0 Category: Spell checking ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[100];
    int correct = 1;
    
    printf("Enter a word: ");
    scanf("%s", word);
    
    // Check for non-alphabetic characters
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            printf("Error: Word contains non-alphabetic character.\n");
            correct = 0;
            break;
        }
    }
    
    if (correct) {
        // Check for capitalization errors
        int first_letter_upper = isupper(word[0]);
        int all_lower = 1;
        for (int i = 1; i < strlen(word); i++) {
            if (!islower(word[i])) {
                all_lower = 0;
                break;
            }
        }
        
        if (first_letter_upper && all_lower) {
            printf("Capitalization error: Only first letter should be capitalized.\n");
            correct = 0;
        } else if (!first_letter_upper && !all_lower) {
            printf("Capitalization error: First letter should be capitalized.\n");
            correct = 0;
        }
    }
    
    if (correct) {
        printf("No spelling errors found.\n");
    }
    
    return 0;
}