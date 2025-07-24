//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Cyberpunk
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[512];
    int count_words = 0, count_c = 0, count_chars = 0, i;

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; i < strlen(str); i++) {
        if (isspace(str[i]))  // check if current character is a whitespace
            count_words++;

        if (str[i] == 'c' || str[i] == 'C')  // check if current character is a 'c'
            count_c++;

        if (!isspace(str[i]))  // check if current character is not a whitespace
            count_chars++;
    }

    printf("\nWord count: %d", count_words + 1);  // add 1 to include the last word
    printf("\n'C' count: %d", count_c);
    printf("\nCharacter count: %d", count_chars);

    return 0;
}