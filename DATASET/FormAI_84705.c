//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: invasive
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    int freq[26] = {0}, i, total = 0;

    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; i < strlen(text); i++) {
        if (text[i] >= 'a' && text[i] <= 'z')
            freq[text[i] - 'a']++;
        else if (text[i] >= 'A' && text[i] <= 'Z')
            freq[text[i] - 'A']++;
    }

    printf("\nFrequency of each letter in the text:\n");

    for (i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            printf("%c = %d\n", i + 'a', freq[i]);
            total += freq[i];
        }
    }

    printf("\nTotal number of letters in the text: %d", total);

    return 0;
}