//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter Alien Language: ");
    fgets(input, sizeof(input), stdin);

    int translated = 0;
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        switch(input[i]) {
            case 'O':
                printf("Ka");
                translated = 1;
                break;
            case 'V':
                printf("Da");
                translated = 1;
                break;
            case 'X':
                printf("Tu");
                translated = 1;
                break;
            case 'F':
                if (input[i+1] == 'D') {
                    printf("Mi");
                    translated = 1;
                    i++;
                }
                break;
            default:
                printf("%c", input[i]);
        }
    }

    if (!translated) {
        printf("Translation not found.");
    }

    return 0;
}