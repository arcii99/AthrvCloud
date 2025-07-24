//FormAI DATASET v1.0 Category: Text processing ; Style: optimized
//A program that takes input string and counts the number of vowels and consonants and displays them.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char str[100];
    int i, vowels = 0, consonants = 0;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    for(i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i])) {
            switch(tolower(str[i])) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowels++;
                    break;
                default:
                    consonants++;
                    break;
            }
        }
    }

    printf("Number of Vowels in the string: %d\n", vowels);
    printf("Number of Consonants in the string: %d\n", consonants);

    return 0;
}