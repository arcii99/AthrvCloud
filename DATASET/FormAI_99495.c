//FormAI DATASET v1.0 Category: String manipulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

char* lowercase(char* str) {
    int i;
    for(i = 0; str[i]; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    return str;
}

char* remove_spaces(char* str) {
    int i, j = 0;
    for(i = 0; str[i]; i++) {
        if(str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    return str;
}

char* reverse(char* str) {
    int len = strlen(str);
    int i;
    for(i = 0; i < len/2; i++) {
        char c = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = c;
    }
    return str;
}

int main() {
    char str[MAX_LEN];
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);

    // Convert the string to lowercase
    printf("\nLowercase: %s", lowercase(str));

    // Remove the spaces from the string
    printf("\nNo Spaces: %s", remove_spaces(str));

    // Reverse the string
    printf("\nReversed: %s", reverse(str));

    return 0;
}