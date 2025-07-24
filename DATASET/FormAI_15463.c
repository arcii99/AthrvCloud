//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[1000];
    int count[26] = {0};
    int i, j;

    // Asking user for input
    printf("Hail and well met, good sir! Pray tell, what sentence wouldst thou like to analyze?\n");
    fgets(input, 1000, stdin);

    // Counting frequency of each letter
    for (i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (isalpha(c)) {
            // Converting letter to lowercase
            c = tolower(c);
            count[c - 'a']++;
        }
    }

    // Displaying results
    printf("\nVerily, the letter frequency of thine sentence is as follows:\n");
    for (i = 0; i < 26; i++) {
        char c = 'a' + i;
        printf("%c: ", c);
        for (j = 0; j < count[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Returning 0 to indicate successful execution of program
    return 0;
}