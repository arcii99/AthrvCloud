//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    printf("Hey there! Let's convert your text to Morse code!\n");
    printf("Enter the text you want to convert: ");
    fgets(message, 1000, stdin);
    message[strcspn(message, "\n")] = 0;
    printf("You entered: %s\n", message);
    printf("Converting...\n");
    for (int i = 0; i < strlen(message); i++) {
        switch (message[i]) {
            case 'a': printf(".-\t"); break;
            case 'b': printf("-...\t"); break;
            case 'c': printf("-.-.\t"); break;
            case 'd': printf("-..\t"); break;
            case 'e': printf(".\t"); break;
            case 'f': printf("..-.\t"); break;
            case 'g': printf("--.\t"); break;
            case 'h': printf("....\t"); break;
            case 'i': printf("..\t"); break;
            case 'j': printf(".---\t"); break;
            case 'k': printf("-.-\t"); break;
            case 'l': printf(".-..\t"); break;
            case 'm': printf("--\t"); break;
            case 'n': printf("-.\t"); break;
            case 'o': printf("---\t"); break;
            case 'p': printf(".--.\t"); break;
            case 'q': printf("--.-\t"); break;
            case 'r': printf(".-.\t"); break;
            case 's': printf("...\t"); break;
            case 't': printf("-\t"); break;
            case 'u': printf("..-\t"); break;
            case 'v': printf("...-\t"); break;
            case 'w': printf(".--\t"); break;
            case 'x': printf("-..-\t"); break;
            case 'y': printf("-.--\t"); break;
            case 'z': printf("--..\t"); break;
            case '1': printf(".----\t"); break;
            case '2': printf("..---\t"); break;
            case '3': printf("...--\t"); break;
            case '4': printf("....-\t"); break;
            case '5': printf(".....\t"); break;
            case '6': printf("-....\t"); break;
            case '7': printf("--...\t"); break;
            case '8': printf("---..\t"); break;
            case '9': printf("----.\t"); break;
            case '0': printf("-----\t"); break;
            case ' ': printf("   \t"); break;
            default: printf("Unknown character: %c\t", message[i]); break;
        }
    }
    printf("\nDone!");
    return 0;
}