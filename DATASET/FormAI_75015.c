//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: innovative
#include <stdio.h>
#include <string.h>

char alien_language_1[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '-', '.'};
char alien_language_2[] = {'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', '-', '.'};

char* translate_to_alien_language(char* message) {
    char* translated_message = malloc(sizeof(char) * strlen(message));
    for (int i = 0; i < strlen(message); i++) {
        int index;
        for (int j = 0; j < 27; j++) {
            if (alien_language_1[j] == message[i]) {
                index = j;
                break;
            }
        }
        translated_message[i] = alien_language_2[index];
    }
    return translated_message;
}

int main() {
    printf("Enter a message to be translated: ");
    char message[1024];
    fgets(message, 1024, stdin);
    printf("Translated message: %s", translate_to_alien_language(message));
    return 0;
}