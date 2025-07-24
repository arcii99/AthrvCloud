//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int i, len;
    printf("Enter a sentence in C Cat language:\n");
    fgets(input, 100, stdin);
    len = strlen(input);
    printf("\nTranslation in English:\n");

    for (i = 0; i < len; i++) {
        // Meow means "I"
        if (input[i] == 'm' && input[i + 1] == 'e' && input[i + 2] == 'o' && input[i + 3] == 'w') {
            printf("I");
            i += 3;
        }
        // Purr means "You"
        else if (input[i] == 'p' && input[i + 1] == 'u' && input[i + 2] == 'r' && input[i + 3] == 'r') {
            printf("You");
            i += 3;
        }
        // Hiss means "No"
        else if (input[i] == 'h' && input[i + 1] == 'i' && input[i + 2] == 's' && input[i + 3] == 's') {
            printf("No");
            i += 3;
        }
        // Growl means "Yes"
        else if (input[i] == 'g' && input[i + 1] == 'r' && input[i + 2] == 'o' && input[i + 3] == 'w' && input[i + 4] == 'l') {
            printf("Yes");
            i += 4;
        }
        // Yowl means "Please"
        else if (input[i] == 'y' && input[i + 1] == 'o' && input[i + 2] == 'w' && input[i + 3] == 'l') {
            printf("Please");
            i += 3;
        }
        // Snarl means "Why"
        else if (input[i] == 's' && input[i + 1] == 'n' && input[i + 2] == 'a' && input[i + 3] == 'r' && input[i + 4] == 'l') {
            printf("Why");
            i += 4;
        }
        // Whisker means "Friend"
        else if (input[i] == 'w' && input[i + 1] == 'h' && input[i + 2] == 'i' && input[i + 3] == 's' && input[i + 4] == 'k' && input[i + 5] == 'e' && input[i + 6] == 'r') {
            printf("Friend");
            i += 6;
        }
        // Claw means "Love"
        else if (input[i] == 'c' && input[i + 1] == 'l' && input[i + 2] == 'a' && input[i + 3] == 'w') {
            printf("Love");
            i += 3;
        }
        // Paw means "Goodbye"
        else if (input[i] == 'p' && input[i + 1] == 'a' && input[i + 2] == 'w') {
            printf("Goodbye");
            i += 2;
        }
        else {
            printf("%c", input[i]);
        }
    }
    return 0;
}