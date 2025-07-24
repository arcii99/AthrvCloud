//FormAI DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100];
    char dictionary[100][100] = { "apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon" };
    int dictionary_size = 10;
    
    printf("Enter your text: ");
    fgets(text, 100, stdin);
    
    int i, j, k, l;
    char word[100];
    int errors = 0;
    
    for (i = 0; i <= strlen(text); i++) {
        if (isalpha(text[i])) {
            j = i;
            k = 0;
            while (isalpha(text[j])) {
                word[k] = text[j];
                k++;
                j++;
            }
            word[k] = '\0';
            int found = 0;
            for (l = 0; l < dictionary_size; l++) {
                if (strcmp(word, dictionary[l]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("%s is not in the dictionary\n", word);
                errors++;
            }
            i = j;
        }
    }
    
    if (errors == 0) {
        printf("There are no spelling errors\n");
    } else if (errors == 1) {
        printf("There is 1 spelling error\n");
    } else {
        printf("There are %d spelling errors\n", errors);
    }
    
    return 0;
}