//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: automated
#include <stdio.h>

int main() {
    char input[100];
    int i, j;
    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);
    printf("\nASCII Art:\n");
    for (i = 0; input[i] != '\0'; i++) {
        for (j = 0; j < 9; j++) {
            switch(input[i]) {
                case 'A':
                    printf(" **  \n*  * \n**** \n*  * \n*  *\n");
                    break;
                case 'B':
                    printf("**** \n*  * \n**** \n*  * \n****\n");
                    break;
                case 'C':
                    printf("**** \n*    \n*    \n*    \n****\n");
                    break;
                case 'D':
                    printf("**** \n*  * \n*  * \n*  * \n****\n");
                    break;
                case 'E':
                    printf("**** \n*    \n**** \n*    \n****\n");
                    break;
                case 'F':
                    printf("**** \n*    \n**** \n*    \n*   \n");
                    break;
                case 'G':
                    printf("**** \n*    \n***  \n*  * \n****\n");
                    break;
                case 'H':
                    printf("*  * \n*  * \n**** \n*  * \n*  *\n");
                    break;
                case 'I':
                    printf("**** \n *   \n *   \n *   \n****\n");
                    break;
                case 'J':
                    printf("**** \n   * \n   * \n*  * \n*** \n");
                    break;
                case 'K':
                    printf("*  * \n* *  \n**   \n* *  \n*  *\n");
                    break;
                case 'L':
                    printf("*    \n*    \n*    \n*    \n****\n");
                    break;
                case 'M':
                    printf("*  * \n** * \n* ** \n*  * \n*  *\n");
                    break;
                case 'N':
                    printf("*  * \n**  * \n* * * \n*  ** \n*   *\n");
                    break;
                case 'O':
                    printf("**** \n*  * \n*  * \n*  * \n****\n");
                    break;
                case 'P':
                    printf("**** \n*  * \n**** \n*    \n*    \n");
                    break;
                case 'Q':
                    printf("**** \n*  * \n*  * \n* ** \n**** \n");
                    break;
                case 'R':
                    printf("**** \n*  * \n***  \n* *  \n*  *\n");
                    break;
                case 'S':
                    printf("**** \n*    \n**** \n    * \n****\n");
                    break;
                case 'T':
                    printf("**** \n *   \n *   \n *   \n *   \n");
                    break;
                case 'U':
                    printf("*  * \n*  * \n*  * \n*  * \n****\n");
                    break;
                case 'V':
                    printf("*  * \n*  * \n*  * \n * * \n  *\n");
                    break;
                case 'W':
                    printf("*  * \n*  * \n* * * \n* ** \n*  *\n");
                    break;
                case 'X':
                    printf("*  * \n * * \n  *  \n * * \n*  *\n");
                    break;
                case 'Y':
                    printf("*  * \n * * \n  *  \n  *  \n  *  \n");
                    break;
                case 'Z':
                    printf("**** \n   * \n  *  \n *   \n****\n");
                    break;
                case ' ':
                    printf("   \n   \n   \n   \n   \n");
                    break;
                case '\n':
                    printf("\n");
                    break;
                default:
                    printf("    \n    \n    \n    \n    \n");
            }
        }
    }
    return 0;
}