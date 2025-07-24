//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Welcome to my User Input Sanitizer program!");

    printf("\n\nPlease enter some text that I can sanitize:\n");
    fgets(input, 1000, stdin);

    // let's replace all the vowels with the letter "u"
    for (int i = 0; i < strlen(input); i++) {
        char current_char = input[i];
        if (current_char == 'a' || current_char == 'e' || current_char == 'i' || current_char == 'o' || current_char == 'u' || current_char == 'A' || current_char == 'E' || current_char == 'I' || current_char == 'O' || current_char == 'U') {
            input[i] = 'u';
        }
    }

    printf("\n\nHere is your sanitized text: %s", input);
    printf("\n\nDo you want to run the sanitizer again? Y/N\n");

    char answer[10];
    fgets(answer, 10, stdin);
    if (answer[0] == 'Y' || answer[0] == 'y') {
        printf("\n\nGreat! Let's go again!\n");
        main();
    }
    else {
        printf("\n\nBye bye and remember, always sanitize your user input! :)");
    }

    return 0;
}