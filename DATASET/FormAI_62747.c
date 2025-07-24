//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: grateful
#include <stdio.h>

int main() {
    char text[100];
    int i, j;
    
    printf("Enter the text you wish to convert into ASCII art:\n");
    scanf("%[^\n]", text);
    
    for (i = 0; text[i] != '\0'; i++) {
        printf(" ");
        for (j = 1; j <= 5; j++) {
            switch (text[i]) {
                case 'A':
                    printf("  *  \n * * \n*****\n*   *\n*   *\n");
                    break;
                case 'B':
                    printf("**** \n*   *\n**** \n*   *\n**** \n");
                    break;
                case 'C':
                    printf(" *** \n*   *\n*    \n*    \n *** \n");
                    break;
                case 'D':
                    printf("**** \n*   *\n*   *\n*   *\n**** \n");
                    break;
                case 'E':
                    printf("*****\n*    \n*****\n*    \n*****\n");
                    break;
                case 'F':
                    printf("*****\n*    \n*****\n*    \n*    \n");
                    break;
                case 'G':
                    printf(" *** \n*   *\n*  **\n*   *\n *** \n");
                    break;
                case 'H':
                    printf("*   *\n*   *\n*****\n*   *\n*   *\n");
                    break;
                case 'I':
                    printf("*****\n  *  \n  *  \n  *  \n*****\n");
                    break;
                case 'J':
                    printf("    *\n    *\n    *\n*   *\n *** \n");
                    break;
                default:
                    printf("*\n");
                    break;
            }
        }
    }
    
    return 0;
}