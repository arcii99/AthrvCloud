//FormAI DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

int decentralize(char* str, int len) {
    int i, j;
    for(i=0, j=0; i<len; i++) { // i: index of current character, j: index of next character
        if(str[i] != ' ') { // if current character is not a space
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0'; // add null character at the end
    return j; // return new length of string
}

int main() {
    char str[MAX_LEN];
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin); // read input string from user
    int len = strlen(str);
    if (str[len-1] == '\n') { // replace newline character at the end
        str[len-1] = '\0';
        len--;
    }
    printf("Original string: %s\n", str);
    int newlen = decentralize(str, len);
    printf("Decentralized string: %s\n", str);
    printf("New length: %d\n", newlen);
    return 0;
}