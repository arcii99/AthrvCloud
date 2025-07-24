//FormAI DATASET v1.0 Category: Text processing ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[1000], bold[1000];
    int i, j = 0, boldFound = 0;

    printf("Enter some text:\n");
    fgets(text, sizeof(text), stdin);

    for(i = 0; i < strlen(text); i++) {
        if(text[i] == '*' && !boldFound) {
            boldFound = 1;
            continue;
        }

        if(text[i] == '*' && boldFound) {
            boldFound = 0;
            bold[j++] = '\0';

            printf("\033[1m%s\033[0m", bold);
            j = 0;  // reset for next bold section
            continue;
        }

        if(boldFound) {
            bold[j++] = text[i]; // add to bold section
            continue;
        }

        printf("%c", text[i]); // print non-bold characters
    }

    printf("\n");

    return 0;
}