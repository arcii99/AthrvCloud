//FormAI DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    char s[256];
    int i, len;

    printf("Enter a string: ");
    fgets(s, 256, stdin);

    printf("Your original string: %s", s);

    len = strlen(s); // get length of string

    // loop through each character in the string
    for(i = 0; i < len; i++) {
        if(s[i] >= 65 && s[i] <= 90) { // if the character is uppercase
            s[i] += 32; // convert it to lowercase
        }
        else if(s[i] >= 97 && s[i] <= 122) { // if the character is lowercase
            s[i] -= 32; // convert it to uppercase
        }
    }

    printf("Your manipulated string: %s", s);

    return 0;
}