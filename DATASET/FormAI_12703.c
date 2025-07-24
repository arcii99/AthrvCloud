//FormAI DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    char word[20];
    int count_word = 0, count_vowel = 0, count_consonant = 0;
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);
    printf("Enter a word: ");
    scanf("%s", word);

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        if (strcmp(token, word) == 0) {
            count_word++;
        }
        for (int i = 0; i < strlen(token); i++) {
            if (token[i] == 'a' || token[i] == 'e' || token[i] == 'i' || token[i] == 'o' || token[i] == 'u' || 
                token[i] == 'A' || token[i] == 'E' || token[i] == 'I' || token[i] == 'O' || token[i] == 'U') {
                count_vowel++;
            } else if ((token[i] >= 'a' && token[i] <= 'z') || (token[i] >= 'A' && token[i] <= 'Z')) {
                count_consonant++;
            }
        }
        token = strtok(NULL, " ");
    }

    printf("\nThe word '%s' appeared %d times.\n", word, count_word);
    printf("The sentence contains %d vowels and %d consonants.\n", count_vowel, count_consonant);

    return 0;
}