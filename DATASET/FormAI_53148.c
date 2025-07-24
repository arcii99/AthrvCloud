//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: light-weight
#include <stdio.h>
#include <string.h>

// Function to translate English to C Cat language
void engToCCat(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        // If the character is 'c', replace it with 'meow'
        if (str[i] == 'c') {
            printf("meow ");
        }
        // If the character is 'at', replace it with 'purr'
        else if (i < len-1 && str[i] == 'a' && str[i+1] == 't') {
            printf("purr ");
            i++;
        }
        else {
            printf("%c", str[i]);
        }
    }
}

int main() {
    char str[100];
    printf("Enter a sentence in English to translate to C Cat language:\n");
    fgets(str, 100, stdin);
    engToCCat(str);
    printf("\n");
    return 0;
}