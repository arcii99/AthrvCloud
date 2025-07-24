//FormAI DATASET v1.0 Category: Text processing ; Style: standalone
#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 1000

void remove_punc(char* s, int len);
void to_lower(char* s, int len);
int count_words(char* s, int len);

int main() {
    char str[MAX_LEN];
    printf("Enter a string:\n");
    fgets(str, MAX_LEN, stdin); // read input string from user
    int len = strlen(str);

    // remove punctuation from string
    remove_punc(str, len);

    // convert string to lowercase
    to_lower(str, len);

    // count number of words in string
    int num_words = count_words(str, len);

    printf("The string has %d words.\n", num_words);

    return 0;
}

// function to remove punctuation from a string
void remove_punc(char* s, int len) {
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        if (!ispunct(s[i])) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

// function to convert a string to lowercase
void to_lower(char* s, int len) {
    int i;
    for (i = 0; i < len; i++) {
        s[i] = tolower(s[i]);
    }
}

// function to count the number of words in a string
int count_words(char* s, int len) {
    int count = 1; // assume there is at least one word
    int i;
    for (i = 0; i < len; i++) {
        if (isspace(s[i])) {
            count++;
        }
    }
    return count;
}