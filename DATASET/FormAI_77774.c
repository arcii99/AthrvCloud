//FormAI DATASET v1.0 Category: Text processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Allocate memory for text input
    char *text_input = malloc(sizeof(char) * 1000);

    // Check if the memory allocation was successful
    if(text_input == NULL) {
        printf("Memory allocation unsuccessful");
        exit(1);
    }

    // Read text input from user
    printf("Enter some text: ");
    fgets(text_input, 1000, stdin);

    // Remove newline character from text input
    text_input[strcspn(text_input, "\n")] = 0;

    // Calculate length of text input
    int text_length = strlen(text_input);

    // Convert text input to lowercase
    for(int i = 0; i < text_length; i++) {
        text_input[i] = tolower(text_input[i]);
    }

    // Count frequency of vowels in text input
    int a_count = 0, e_count = 0, i_count = 0, o_count = 0, u_count = 0;
    for(int i = 0; i < text_length; i++) {
        switch(text_input[i]) {
            case 'a': a_count++; break;
            case 'e': e_count++; break;
            case 'i': i_count++; break;
            case 'o': o_count++; break;
            case 'u': u_count++; break;
        }
    }

    // Display results
    printf("\nText entered: %s\n", text_input);
    printf("Number of vowels:\nA: %d\nE: %d\nI: %d\nO: %d\nU: %d\n", a_count, e_count, i_count, o_count, u_count);

    // Deallocate text input memory
    free(text_input);

    return 0;
}