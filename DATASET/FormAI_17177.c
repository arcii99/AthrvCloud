//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Please enter a sentence to be translated into Alien language: ");
    fgets(input, 100, stdin);
    int n = strlen(input);

    printf("Your original sentence: %s\n", input);

    for (int i = 0; i < n; i++) {
        if (input[i] == ' ') {
            printf(" ");
        } else {
            int ascii_value = (int)input[i];
            int alien_value = (ascii_value % 5) + 1;
            switch (alien_value) {
                case 1:
                    printf("Z");
                    break;
                case 2:
                    printf("T");
                    break;
                case 3:
                    printf("P");
                    break;
                case 4:
                    printf("L");
                    break;
                case 5:
                    printf("K");
                    break;
            }
        }
    }

    printf("\n");
    return 0;
}