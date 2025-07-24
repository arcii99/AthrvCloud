//FormAI DATASET v1.0 Category: Word Count Tool ; Style: active
#include <stdio.h>
#include <string.h>

// function to count the occurrences of a word in a string
int countOccurrences(char *str, char *word) {
    int count = 0;
    // split the string into words using delimiter space
    char *t = strtok(str, " ");
    // loop through all words in the string
    while (t != NULL) {
        // compare the word with the current word in the loop
        if (strcmp(t, word) == 0) {
            count++;
        }
        // get next word in the loop
        t = strtok(NULL, " ");
    }
    return count;
}

int main() {
    char string[] = "count the number of occurrences of a word in this string";
    char word[] = "the";
    // call the function to count the number of occurrences of the given word in the string
    int count = countOccurrences(string, word);
    printf("The word '%s' occurs %d times in the string.\n", word, count);
    return 0;
}