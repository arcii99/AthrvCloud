//FormAI DATASET v1.0 Category: Text processing ; Style: expert-level
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// function to remove spaces and non-alphabetic characters from a string
void remove_spaces_and_nonalphabetic_chars(char *str) {
    int len = strlen(str);
    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(str[i])) { // if character is alphabetic
            str[j++] = tolower(str[i]); // convert to lowercase and add to new string
        }
    }
    str[j] = '\0'; // add terminating null character
}

int main() {
    char str[100];

    // get input from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // remove spaces and non-alphabetic characters
    remove_spaces_and_nonalphabetic_chars(str);

    // print output
    printf("Processed string: %s\n", str);

    return 0;
}