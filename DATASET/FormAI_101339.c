//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
    char word[100];     // Declare a character array to store the word
    int i, len, flag = 0;
    
    printf("Enter a word to check if it is a palindrome: ");
    scanf("%s", word);  // Read the word from user
    
    len = strlen(word); // Get the length of the word
    
    for(i=0;i<len;i++) {
        if(word[i] != word[len-i-1]) {  // Check if the first character matches the last character, and so on
            flag = 1;
            break;
        }
    }
    
    if(flag == 0) {
        printf("%s is a palindrome\n", word);  // If all the characters match, it is a palindrome
    } else {
        printf("%s is not a palindrome\n", word);  // Otherwise, it is not a palindrome
    }
    
    return 0;
}