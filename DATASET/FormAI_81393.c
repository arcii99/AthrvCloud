//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: complete
#include <stdio.h>
#include <string.h>

#define MAX_LEN 80
#define ROWS 5

void printASCII(char ch);

int main() {
    char text[MAX_LEN];
    int len, i, j;
    printf("Enter some text to convert to ASCII art: ");
    fgets(text, MAX_LEN, stdin);
    len = strlen(text) - 1;
    printf("\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < len; j++) {
            printASCII(text[j]);
        }
        printf("\n");
    }
    return 0;
}

void printASCII(char ch) {
    int ascii = (int)ch;
    switch(ascii) {
        case 32:    // Space
            printf("     ");
            break;
        case 33:    // !
            printf(" _!_ ");
            break;
        case 34:    // "
            printf("(_\"_)");
            break;
        case 35:    // #
            printf("|# #|");
            break;
        case 36:    // $
            printf("|$$$|");
            break;
        case 37:    // %
            printf("\\%/\\/");
            break;
        case 38:    // &
            printf("/~\\_/~\\");
            break;
        case 39:    // '
            printf("(_)  ");
            break;
        case 40:    // (
            printf("(_(,_)");
            break;
        case 41:    // )
            printf("(_o_)");
            break;
        case 42:    // *
            printf("*'*'*");
            break;
        case 43:    // +
            printf("------+------");
            break;
        case 44:    // ,
            printf(" ,''' ");
            break;
        case 45:    // -
            printf("------");
            break;
        case 46:    // .
            printf(" '''' ");
            break;
        case 47:    // /
            printf("\\    /");
            break;
        case 48:    // 0
            printf(" _0_ ");
            break;
        case 49:    // 1
            printf("  /|  ");
            break;
        case 50:    // 2
            printf(" |_/  ");
            break;
        case 51:    // 3
            printf(" |_|  ");
            break;
        case 52:    // 4
            printf("  |~| ");
            break;
        case 53:    // 5
            printf("  |__ ");
            break;
        case 54:    // 6
            printf("  /_/ ");
            break;
        case 55:    // 7
            printf(" |__  ");
            break;
        case 56:    // 8
            printf(" |_|  ");
            break;
        case 57:    // 9
            printf("  _|_ ");
            break;
        case 58:    // :
            printf(" |::| ");
            break;
        case 59:    // ;
            printf("/:::/ ");
            break;
        case 60:    // <
            printf("  \\  ");
            break;
        case 61:    // =
            printf("======");
            break;
        case 62:    // >
            printf("  /  ");
            break;
        case 63:    // ?
            printf(" _|_\\ ");
            break;
        default:
            printf("      ");
            break;
    }
}