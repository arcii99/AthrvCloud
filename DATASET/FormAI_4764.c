//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: authentic
#include <stdio.h>
#include <string.h>

void translate(char code[]) {
    int i = 0;
    while (code[i] != '\0') {
        switch (code[i]) {
            case '1':
                printf("U");
                break;
            case '2':
                printf("R");
                break;
            case '3':
                printf("G");
                break;
            case '4':
                printf("Y");
                break;
            case '5':
                printf("O");
                break;
            case '6':
                printf("T");
                break;
            case '7':
                printf("E");
                break;
            case '8':
                printf("F");
                break;
            case '9':
                printf("D");
                break;
            case '0':
                printf("N");
                break;
            default:
                printf("%c", code[i]);
                break;
        }
        i++;
    }
    printf("\n");
}

int main() {
    char code[] = "254766013078231";
    printf("Alien Language Code: %s\n", code);
    printf("Translated Code: ");
    translate(code);
    return 0;
}