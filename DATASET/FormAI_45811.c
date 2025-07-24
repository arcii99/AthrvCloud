//FormAI DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

/* Count and display the number of vowels appearing in an input text */
int main() {
    char input_text[MAX_LENGTH];
    int vowel_count = 0;

    printf("Enter some text: ");
    fgets(input_text, MAX_LENGTH, stdin);

    for (int i = 0; i < strlen(input_text); i++) {
        char current_char = tolower(input_text[i]);  // Convert letter to lower case

        if (current_char == 'a' || current_char == 'e' || current_char == 'i' || current_char == 'o' || current_char == 'u') {
            vowel_count++;
        }
    }

    if (vowel_count == 1) {
        printf("There is 1 vowel in the text.\n");
    } else {
        printf("There are %d vowels in the text.\n", vowel_count);
    }

    return 0;
}