//FormAI DATASET v1.0 Category: Text processing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to remove the white spaces from a string */
char* remove_white_spaces(char *str) {
    int count = 0;
    for(int i = 0; str[i]; i++) {
        if(str[i] != ' ') 
            str[count++] = str[i];
    }
    str[count] = '\0';
    return str;
}

int main() {
    char input[1000];
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    printf("Original sentence: %s", input);

    /* Removing the white spaces */
    char *removed = remove_white_spaces(input);
    printf("Sentence without spaces: %s", removed);

    /* Counting the number of characters */
    int len_without_spaces = strlen(removed);
    printf("Length of sentence without spaces: %d\n", len_without_spaces);

    /* Reversing the sentence */
    char reversed[1000];
    int len = strlen(removed);
    for(int i = 0; i < len; i++) {
        reversed[i] = removed[len - i - 1];
    }
    reversed[len] = '\0';
    printf("Reversed sentence: %s", reversed);

    /* Converting to uppercase */
    for(int i = 0; i < len; i++) {
        if(reversed[i] >= 'a' && reversed[i] <= 'z') 
            reversed[i] -= 32;
    }
    printf("Uppercase sentence: %s", reversed);

    return 0;
}