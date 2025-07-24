//FormAI DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 1000 // Maximum word length
#define SIZE 65536 // Hash table size

char* strip_punct(char* s) // Remove all punctuations except apostrophes
{
    char* p = s;
    while(*p) {
        if(isalpha(*p) || *p == '\'') {
            p++;
        } else {
            memmove(p, p+1, strlen(p));
        }
    }
    return s;
}

int hash(unsigned char* s) // Function to hash a word to an index in the hash table
{
    int h = 0;
    while (*s) {
        h = (h << 5) - h + *s++;
    }
    return h % SIZE;
}

int main()
{
    // Declaration of variables
    FILE* fp; // File pointer
    char line[N], word[N]; // Strings to store line and individual words
    int i, j, k, len, idx; // Loop variables and hash index

    char* dict[SIZE]; // Hash table array
    memset(dict, 0, sizeof(dict)); // Initialize all elements to NULL

    // Open dictionary file
    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error opening dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    // Read dictionary file and add every word to the hash table
    while (fgets(line, N, fp) != NULL) {
        len = strlen(line);
        if (line[len-1] == '\n') { // Remove newline character at the end of the line
            line[len-1] = '\0';
        }
        strcpy(word, strip_punct(line)); // Remove all punctuations from the word and copy it to "word" variable
        idx = hash(word); // Hash the word to an index in the hash table
        dict[idx] = strdup(word); // Add the word to the hash table
    }
    fclose(fp);

    // Open input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file.\n");
        exit(EXIT_FAILURE);
    }

    // Read input file and check every word against the dictionary
    while (fgets(line, N, fp) != NULL) {
        len = strlen(line);
        if (line[len-1] == '\n') { // Remove newline character at the end of the line
            line[len-1] = '\0';
        }
        i = 0;
        while (line[i] != '\0') {
            j = i; // Store the starting index of a word
            while (isalpha(line[i]) || line[i] == '\'') { // Move to the next character if the current character is a letter or apostrophe
                i++;
            }
            k = i-1; // Store the ending index of a word
            if (k >= j) { // If at least one letter found
                strncpy(word, line+j, k-j+1); // Copy the word to "word" variable
                word[k-j+1] = '\0';
                idx = hash(word); // Hash the word to an index in the hash table
                if (dict[idx] != NULL && strcmp(dict[idx], word) != 0) { // If the word is not in the dictionary
                    printf("%s", line); // Print the line
                    for (int x = 0; x < k+1; x++) { // Print the word with ^ under the misspelled letter
                        if (x < j || x > k) {
                            printf(" ");
                        } else {
                            printf("^");
                        }
                    }
                    printf("\n");
                }
            }
            i++; // Move to the next character
        }
    }
    fclose(fp);

    // Free all memory used by the hash table
    for (i = 0; i < SIZE; i++) {
        free(dict[i]);
    }

    return 0;
}