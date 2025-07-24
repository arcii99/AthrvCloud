//FormAI DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char message[MAX_LENGTH];
    int i, j, length;
    int letter_count[26] = {0};

    printf("Enter message: ");
    fgets(message, MAX_LENGTH, stdin);

    length = strlen(message);

    // Convert all characters to lowercase
    for (i = 0; i < length; i++) {
        message[i] = tolower(message[i]);
    }

    // Count the number of occurrences of each letter
    for (i = 0; i < length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            letter_count[message[i] - 'a']++;
        }
    }

    // Print the frequency of each letter
    printf("Letter frequencies: \n");
    for (i = 0; i < 26; i++) {
        printf("%c: ", i + 'a');
        for (j = 0; j < letter_count[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Translate message to post-apocalyptic style
    printf("Translated message: ");
    for (i = 0; i < length; i++) {
        if (message[i] == 'e') {
            printf("3");
        } else if (message[i] == 'o') {
            printf("0");
        } else {
            printf("%c", message[i]);
        }
    }
    printf("\n");

    return 0;
}