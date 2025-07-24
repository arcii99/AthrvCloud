//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: dynamic
#include <stdio.h>
#include <ctype.h>

// function to get word frequency
void wordFreqCounter(char* str) {
    int freq[26] = {0}; // initialize frequency array with 0
    char word[100]; // initialize a word to store input string
    int i = 0, j = 0; // initialize counters for word and frequency array
    
    // loop through the input string
    while(str[i] != '\0') {
        // get each character and convert it to lower case
        char ch = tolower(str[i]);
        
        // if the character is an alphabet, add it to the word
        if(isalpha(ch)) {
            word[j++] = ch;
        }
        // if the character is a space or punctuation, terminate the word and reset the counter
        else if(j != 0) {
            word[j] = '\0'; // add null character at the end of the word
            freq[word[0] - 'a']++; // increment the frequency count of the first letter
            j = 0; // reset the counter for next word
        }
        i++; // move to the next character
    }
    
    // check if there are any remaining words in the string
    if(j != 0) {
        word[j] = '\0'; // add null character at the end of the word
        freq[word[0] - 'a']++; // increment the frequency count of the first letter
    }
    
    // print the frequency count for each word starting with 'a'
    printf("Word frequency count:\n");
    for(int k=0; k<26; k++) {
        if(freq[k] > 0) {
            printf("%c - %d\n", k+'a', freq[k]);
        }
    }
}

int main() {
    char str[1000];
    printf("Enter a string:\n");
    fgets(str, 1000, stdin); // read input from user
    wordFreqCounter(str); // call function to get word frequency
    return 0;
}