//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input_string[1000];
    char *token;
    int frequency[26] = {0};
    int i, j;

    printf("Enter a string: ");
    fgets(input_string, 1000, stdin);

    // Convert the string to lowercase
    for(i = 0; input_string[i]; i++){
        input_string[i] = tolower(input_string[i]);
    }

    // Tokenize the string and count the frequency of each word
    token = strtok(input_string, " ,.-\n");
    while(token != NULL){
        for(i = 0; token[i]; i++){
            frequency[token[i] - 'a']++;
        }
        token = strtok(NULL, " ,.-\n");
    }

    // Print the frequency of each word
    printf("\nFrequency of each character:\n");
    for(i = 0; i < 26; i++){
        printf("%c: ", i + 'a');
        for(j = 0; j < frequency[i]; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}