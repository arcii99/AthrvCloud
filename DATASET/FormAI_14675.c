//FormAI DATASET v1.0 Category: Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // set random seed

    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz"; // alphabet string
    char surreal_table[26][26]; // surreal substitution table

    // generate surreal substitution table
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            surreal_table[i][j] = alphabet[(rand() % 26)]; // randomly substitute letter with another letter
        }
    }

    // prompt user for input
    printf("Enter a message to surrealize: ");
    char input[100];
    fgets(input, 100, stdin);

    // surrealize message
    for (int i = 0; i < strlen(input); i++) {
        char c = tolower(input[i]);
        if (isalpha(c)) {
            int index = (int)(c - 'a');
            char surreal_c = surreal_table[index][rand() % 26]; // randomly select substitution from surreal table
            printf("%c", surreal_c);
        } else {
            printf("%c", c);
        }
    }

    return 0;
}