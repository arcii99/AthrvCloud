//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[1000];
    int count = 0;

    printf("Enter your text: ");
    fgets(text, 1000, stdin);

    for(int i = 0; text[i] != '\0'; i++) {
        if(isspace(text[i]) || ispunct(text[i])) {
            count++;
        }
    }

    printf("The number of words in your text is: %d", count+1);

    return 0;
}