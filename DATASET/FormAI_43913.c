//FormAI DATASET v1.0 Category: Text processing ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], ch;
    int length, count = 0;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    printf("Enter a character: ");
    scanf("%c", &ch);
    
    length = strlen(str);

    // loop through each character of string
    for(int i=0; i<length; i++) {
        
        // check if character matches our input
        if (str[i] == ch) {
            count++;

            // change character to uppercase
            str[i] = toupper(str[i]);
        }
    }

    printf("Number of times '%c' appears: %d\n", ch, count);
    printf("Modified string: %s", str);

    return 0;
}