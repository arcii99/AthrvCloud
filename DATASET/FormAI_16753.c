//FormAI DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 200

int read_line(char str[], int n);
void to_lowercase(char str[]);
int is_word(char ch);
int compare(const void* p1, const void* p2);

int main() {
    char dictionary[MAX_LINE_LENGTH][MAX_WORD_LENGTH];
    int dict_size = 0;
    
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    
    // read in dictionary
    printf("Enter dictionary words, one word per line.\n");
    printf("Enter blank line to terminate.\n");
    while (1) {
        printf("Word [%d]: ", dict_size+1);
        read_line(dictionary[dict_size], MAX_WORD_LENGTH);
        if (dictionary[dict_size][0] == '\0') {
            break;
        }
        dict_size++;
    }
    
    // sort dictionary in ascending order
    qsort(dictionary, dict_size, MAX_WORD_LENGTH, compare);
    
    // read in paragraph to check
    printf("\nEnter a paragraph to be checked:\n");
    while (1) {
        read_line(word, MAX_WORD_LENGTH);
        
        if (word[0] == '\0') {
            break;
        }
        
        // convert word to lowercase
        to_lowercase(word);
        
        // check if word is in dictionary
        int found = 0;
        int low = 0;
        int high = dict_size - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int cmp = strcmp(word, dictionary[mid]);
            if (cmp == 0) {
                found = 1;
                break;
            } else if (cmp < 0) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // print result
        printf("%s", found ? word : "*");
        word_count++;
        if (word_count % 20 == 0) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    
    return 0;
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}

void to_lowercase(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_word(char ch) {
    return isalpha(ch) || ch == '\'';
}

int compare(const void* p1, const void* p2) {
    return strcmp((char*) p1, (char*) p2);
}