//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <string.h>

// Define the mapping of alien characters to their translations
const char* alien_chars = "abcd";
const char* translations[] = {"foo", "bar", "baz", "qux"};

int main() {
    // Read in the input string from the user
    char input[1024];
    printf("Enter the alien text to translate: ");
    fgets(input, sizeof(input), stdin);

    // Loop through each character in the input string
    for(int i=0; i<strlen(input); i++) {
        char current_char = input[i];

        // Find the index of the current character in the alien character set
        int char_index = -1;
        for(int j=0; j<strlen(alien_chars); j++) {
            if(current_char == alien_chars[j]) {
                char_index = j;
                break;
            }
        }

        // If the current character is in the set, print its translation
        if(char_index != -1) {
            printf("%s", translations[char_index]);
        }
        // If the current character is not in the set, print a question mark
        else {
            printf("?");
        }
    }

    // Print a newline at the end of the output
    printf("\n");

    return 0;
}