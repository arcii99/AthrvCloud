//FormAI DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main() {
    char word[50];
    printf("Enter a word: ");
    scanf("%s", word);

    int length = strlen(word);
    int i;

    for (i = 0; i < length; i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            word[i] = word[i] - 32;
        }
    }

    printf("The capitalized word is: %s\n", word);

    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    int num_vowels = sizeof(vowels) / sizeof(vowels[0]);

    int vowel_count = 0;
    for (i = 0; i < length; i++) {
        char c = word[i];
        int j;
        for (j = 0; j < num_vowels; j++) {
            if (c == vowels[j]) {
                vowel_count++;
            }
        }
    }

    printf("Number of vowels: %d\n", vowel_count);

    int num_consonants = length - vowel_count;
    printf("Number of consonants: %d\n", num_consonants);

    if (vowel_count > num_consonants) {
        printf("There are more vowels than consonants\n");
    } else if (num_consonants > vowel_count) {
        printf("There are more consonants than vowels\n");
    } else {
        printf("There are an equal number of vowels and consonants\n");
    }

    return 0;
}