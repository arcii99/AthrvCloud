//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: mathematical
#include <stdio.h>

int main() {
    int cipher[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    char alien_alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'};
    char message[100]; // assume no message will exceed 100 characters
    printf("Enter your message in the alien language: ");
    fgets(message, 100, stdin);
    int i = 0;
    while (message[i] != '\0') {
        if (message[i] != ' ') { // ignore spaces
            int index = -1;
            for (int j = 0; j < 16; j++) {
                if (alien_alphabet[j] == message[i]) {
                    index = j;
                    break;
                }
            }
            if (index == -1) {
                printf("Invalid character in message: %c\n", message[i]);
                return 1; // exit program with error
            }
            printf("%d ", cipher[index]);
        }
        i++;
    }
    printf("\n");
    return 0; // exit program normally
}