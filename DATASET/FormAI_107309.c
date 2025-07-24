//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: satisfied
/* This program is a C language translator for cats. Meow! */

#include <stdio.h>
#include <string.h>

int main() {

    char input[100];
    int length, i;
    int vowel = 0;

    printf("Enter a sentence in English, and I will translate it into C Cat Language:\n");
    fgets(input, 100, stdin); // Can accept a maximum of 100 characters
    length = strlen(input);

    for (i = 0; i < length; ++i) {
        switch(input[i]) {
            case 'a':
                printf("meow");
                break;
            case 'e':
                printf("meow");
                break;
            case 'i':
                printf("meow");
                break;
            case 'o':
                printf("meow");
                break;
            case 'u':
                printf("meow");
                break;
            case ' ':
                printf(" ");
                break;
            case '.':
                printf(". Meow!");
                break;
            case ',':
                printf(", meow");
                break;
            case ';':
                printf("; meow");
                break;
            case ':':
                printf(": meow");
                break;
            default:
                printf("%c", input[i]);
        }

        // Counting the number of vowels in the input sentence
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
            ++vowel;
        }
    }

    // Printing the number of vowels in the input sentence
    printf("\n\nThe number of vowels in the sentence is %d\n", vowel);

    return 0;
}