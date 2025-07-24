//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* blacklist_characters = "'\"!;|`$";

void sanitize_input(char *input) {

    char *clean_input = malloc(strlen(input)+1); /* allocate space for clean input */
    if(clean_input == NULL) {
        perror("Error: could not allocate space for clean input");
        exit(EXIT_FAILURE);
    }

    int counter = 0;
    for(int i=0; input[i] != '\0'; i++) {
        if(strchr(blacklist_characters, input[i]) == NULL) { /* Check if the current character is not blacklisted */
            clean_input[counter++] = input[i]; /* Append the current character to the clean input array */
        }
    }
    clean_input[counter] = '\0'; /* Add null terminator to the end of the clean input string */

    strcpy(input, clean_input); /* Copy the clean input string back to the original input buffer */
    free(clean_input); /* Free the memory allocated for the clean input string */
}

int main() {
    char input_buffer[256];

    printf("Enter your name: ");
    fgets(input_buffer, 256, stdin);
    sanitize_input(input_buffer);
    printf("Hello, %s!\n", input_buffer);

    printf("Enter your address: ");
    fgets(input_buffer, 256, stdin);
    sanitize_input(input_buffer);
    printf("Your address is: %s\n", input_buffer);
    
    return 0;
}