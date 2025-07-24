//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: shape shifting
#include <stdio.h>
#include <string.h>

void printMorse(char c) {
    switch (c) {
        case 'a': printf(".- "); break;
        case 'b': printf("-... "); break;
        case 'c': printf("-.-. "); break;
        case 'd': printf("-.. "); break;
        case 'e': printf(". "); break;
        case 'f': printf("..-. "); break;
        case 'g': printf("--. "); break;
        case 'h': printf(".... "); break;
        case 'i': printf(".. "); break;
        case 'j': printf(".--- "); break;
        case 'k': printf("-.- "); break;
        case 'l': printf(".-.. "); break;
        case 'm': printf("-- "); break;
        case 'n': printf("-. "); break;
        case 'o': printf("--- "); break;
        case 'p': printf(".--. "); break;
        case 'q': printf("--.- "); break;
        case 'r': printf(".-. "); break;
        case 's': printf("... "); break;
        case 't': printf("- "); break;
        case 'u': printf("..- "); break;
        case 'v': printf("...- "); break;
        case 'w': printf(".-- "); break;
        case 'x': printf("-..- "); break;
        case 'y': printf("-.-- "); break;
        case 'z': printf("--.. "); break;
        case '0': printf("----- "); break;
        case '1': printf(".---- "); break;
        case '2': printf("..--- "); break;
        case '3': printf("...-- "); break;
        case '4': printf("....- "); break;
        case '5': printf("..... "); break;
        case '6': printf("-.... "); break;
        case '7': printf("--... "); break;
        case '8': printf("---.. "); break;
        case '9': printf("----. "); break;
    }
}

void printShapeshiftMorse(char c) {
    switch (c) {
        case 'a': printf("_..--.._ "); break;
        case 'b': printf("_.-.--._ "); break;
        case 'c': printf("_.-..-._ "); break;
        case 'd': printf("_-..--._ "); break;
        case 'e': printf("_.-__._ "); break;
        case 'f': printf("_..-._._ "); break;
        case 'g': printf("_..---.__ "); break;
        case 'h': printf("_..._._. "); break;
        case 'i': printf("_.__._._ "); break;
        case 'j': printf("_.-.._._ "); break;
        case 'k': printf("_.._.-.__ "); break;
        case 'l': printf("_..-___ "); break;
        case 'm': printf("_.-._.___ "); break;
        case 'n': printf("_.__.-.__ "); break;
        case 'o': printf("_--.--.-- "); break;
        case 'p': printf("_.-___.- "); break;
        case 'q': printf("_--.__._ "); break;
        case 'r': printf("_._.-.__ "); break;
        case 's': printf("_.-.._._ "); break;
        case 't': printf("_.___._ "); break;
        case 'u': printf("_.__.- "); break;
        case 'v': printf("_...__. "); break;
        case 'w': printf("_._-.__ "); break;
        case 'x': printf("_.--.._. "); break;
        case 'y': printf("_..--._. "); break;
        case 'z': printf("_.__.--_ "); break;
        case '0': printf("_.-__._.__._ "); break;
        case '1': printf("_.__.__.__ "); break;
        case '2': printf("_._.__.__ "); break;
        case '3': printf("_.._.__.__ "); break;
        case '4': printf("_..._.__ "); break;
        case '5': printf("_....__ "); break;
        case '6': printf("_-...._._ "); break;
        case '7': printf("_--..._ "); break;
        case '8': printf("_---.._ "); break;
        case '9': printf("_----._ "); break;
    }
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    printf("\nOriginal Morse Code Conversion:\n");
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            printMorse(str[i]);
        } else {
            printf(" ");
        }
    }
    printf("\n\nShapeshift Morse Code Conversion:\n");
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            printShapeshiftMorse(str[i]);
        } else {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}