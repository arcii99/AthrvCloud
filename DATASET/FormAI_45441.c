//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
#include <stdio.h>
#include <string.h>

void printChar(char c) {
    switch(c) {
        case 'A':
        case 'a':
            printf("  ,-" "\n");
            printf(" / \\ " "\n");
            printf("(_ |" "\n");
            break;
        case 'B':
        case 'b':
            printf("====" "\n");
            printf("|__|" "\n");
            printf("|__|" "\n");
            break;
        case 'C':
        case 'c':
            printf("   ," "\n");
            printf("  / " "\n");
            printf(" (_" "\n");
            break;
        case 'D':
        case 'd':
            printf("====" "\n");
            printf("|  |" "\n");
            printf("|__|" "\n");
            break;
        case 'E':
        case 'e':
            printf("====" "\n");
            printf("|___" "\n");
            printf("|___" "\n");
            break;
        case 'F':
        case 'f':
            printf("====" "\n");
            printf("|___" "\n");
            printf("|" "\n");
            break;
        case 'G':
        case 'g':
            printf(" ___" "\n");
            printf("/ (_" "\n");
            printf("\\__)" "\n");
            break;
        case 'H':
        case 'h':
            printf("|  |" "\n");
            printf("|__|" "\n");
            printf("|  |" "\n");
            break;
        case 'I':
        case 'i':
            printf("===" "\n");
            printf(" | " "\n");
            printf("===" "\n");
            break;
        case 'J':
        case 'j':
            printf("      ," "\n");
            printf("      |" "\n");
            printf("\\__/|" "\n");
            break;
        case 'K':
        case 'k':
            printf("| / " "\n");
            printf("|/" "\n");
            printf("| \\ " "\n");
            break;
        case 'L':
        case 'l':
            printf("|" "\n");
            printf("|" "\n");
            printf("|___" "\n");
            break;
        case 'M':
        case 'm':
            printf("|\\/|" "\n");
            printf("|  |" "\n");
            printf("|  |" "\n");
            break;
        case 'N':
        case 'n':
            printf("|\\ |" "\n");
            printf("| \\|" "\n");
            printf("|  |" "\n");
            break;
        case 'O':
        case 'o':
            printf(" ___ " "\n");
            printf("/   \\" "\n");
            printf("\\___/" "\n");
            break;
        case 'P':
        case 'p':
            printf("====" "\n");
            printf("|__/" "\n");
            printf("|" "\n");
            break;
        case 'Q':
        case 'q':
            printf(" ___ " "\n");
            printf("/   \\" "\n");
            printf("\\_\\_|" "\n");
            break;
        case 'R':
        case 'r':
            printf("====" "\n");
            printf("|__/" "\n");
            printf("| \\" "\n");
            break;
        case 'S':
        case 's':
            printf(" ___" "\n");
            printf("/___|" "\n");
            printf("\\___/" "\n");
            break;
        case 'T':
        case 't':
            printf("===" "\n");
            printf(" | " "\n");
            printf(" | " "\n");
            break;
        case 'U':
        case 'u':
            printf("|  |" "\n");
            printf("|  |" "\n");
            printf("\\__/" "\n");
            break;
        case 'V':
        case 'v':
            printf("\\  /" "\n");
            printf(" \\/ " "\n");
            printf("  | " "\n");
            break;
        case 'W':
        case 'w':
            printf("|  |" "\n");
            printf("|/\\|" "\n");
            printf("|  |" "\n");
            break;
        case 'X':
        case 'x':
            printf("\\_/ " "\n");
            printf("/ \\" "\n");
            printf("\\_/" "\n");
            break;
        case 'Y':
        case 'y':
            printf("\\  /" "\n");
            printf(" \\/ " "\n");
            printf(" /  " "\n");
            break;
        case 'Z':
        case 'z':
            printf("___" "\n");
            printf("  / " "\n");
            printf(" /__" "\n");
            break;
        default:
            printf("    [?]" "\n");
    }
}

void printAsciiArt(char* text) {
    int n = strlen(text);
    for(int i = 0; i < n; i++) {
        printChar(text[i]);
    }
}

int main() {
    char* text = "ASCII Art";
    printAsciiArt(text);
    return 0;
}