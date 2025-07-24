//FormAI DATASET v1.0 Category: Text processing ; Style: detailed
#include <stdio.h>
#include <string.h>

int main()
{
    char text[1000];
    char *ptr;
    int i, length, vowels = 0, consonants = 0, digits = 0, spaces = 0;
    printf("Enter the text to be processed: ");
    fgets(text, 1000, stdin);

    length = strlen(text);
    ptr = text;

    for (i = 0; i < length; i++) {
        char ch = *(ptr + i);
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                ++vowels;
            } else {
                ++consonants;
            }
        } else if (ch >= '0' && ch <= '9') {
            ++digits;
        } else if (ch == ' ') {
            ++spaces;
        }
    }

    printf("\nNumber of vowels: %d", vowels);
    printf("\nNumber of consonants: %d", consonants);
    printf("\nNumber of digits: %d", digits);
    printf("\nNumber of spaces: %d", spaces);

    return 0;
}