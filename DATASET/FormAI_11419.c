//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Donald Knuth
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1000];
    int wordCount = 0;
    int uniqueCount = 0;
    int count[26] = {0};

    printf("Enter a sentence: ");
    fgets(str, 1000, stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            int index = tolower(str[i]) - 'a';
            count[index]++;
            if (count[index] == 1) { // new unique character
                uniqueCount++;
            }
        } else if (isspace(str[i])) {
            wordCount++;
        }
    }

    printf("\nWord count: %d\n", wordCount + 1); // add one for last word
    printf("Unique character count: %d\n", uniqueCount);

    return 0;
}