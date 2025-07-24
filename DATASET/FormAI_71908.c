//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[1000], c, current_word[1000];
    int word_count = 0, word_length = 0, letter_count = 0;

    printf("Enter a sentence: ");
    scanf("%[^\n]", sentence);

    int freq[26] = {0}; // array to keep track of the frequency of each letter

    for (int i = 0; sentence[i] != '\0'; i++) {
        c = sentence[i];

        if (isalpha(c)) { // if the current character is a letter
            current_word[word_length] = tolower(c);
            word_length++; // increment word length
            letter_count++; // increment letter count for overall frequency calculation
        }

        if (isspace(c) || sentence[i+1] == '\0') { // if current character is space or end of sentence
            current_word[word_length] = '\0'; // terminate current_word string
            word_length = 0; // reset word length

            if (strlen(current_word) > 0) { // if current_word is not an empty string
                word_count++; // increment word count

                for (int j = 0; current_word[j] != '\0'; j++) {
                    int index = current_word[j] - 'a';
                    freq[index]++; // increment frequency of current letter
                }
            }
        }
    }

    // output word frequency information
    printf("Word count: %d\n", word_count);
    printf("Average word length: %.2f\n", (float)letter_count / word_count);
    printf("Letter frequency:\n");

    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, freq[i]);
    }

    return 0;
}