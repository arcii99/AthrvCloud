//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: unmistakable
#include <stdio.h>

int main() {
    char input[100];
    printf("Enter some text to generate ASCII art: ");
    fgets(input, 100, stdin);

    char *delimiter = " ";
    char *token;
    int ascii_value;

    printf("\nHere's your ASCII art:\n");

    token = strtok(input, delimiter);
    while(token != NULL) {
        for(int i = 0; token[i]; i++) {
            ascii_value = token[i];

            switch(ascii_value) {
                case 65 ... 90:    // capital letters
                    printf("  **  \n *  * \n *  * \n *****\n *  * \n *  * \n*    *\n\n");
                    break;

                case 97 ... 122:   // small letters
                    printf("  *** \n *   *\n *   *\n  *** \n *   *\n *   *\n*****\n\n");
                    break;

                case 48 ... 57:    // numbers
                    printf(" *****\n*    *\n*    *\n *****\n    *\n    *\n*****\n\n");
                    break;

                case 44:           // comma
                    printf("   \n   \n  ,\n  \n  \n  \n  \n\n");
                    break;

                case 46:           // period
                    printf("   \n   \n  .\n  \n  \n  \n  \n\n");
                    break;

                default:
                    printf("Unknown character.\n");
            }
        }
        token = strtok(NULL, delimiter);
    }

    return 0;
}