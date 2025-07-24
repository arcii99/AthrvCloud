//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main() {
    char text[50];
    int i, j;

    printf("Enter text to convert to ASCII art: ");
    scanf("%s", text);

    // loop through each character of the input text
    for(i = 0; i < strlen(text); i++) {
        if(text[i] == ' ') {
            for(j = 0; j < 5; j++) {
                printf(" ");
            }
        }
        else {
            // convert each character to its ASCII code
            int code = (int) text[i];

            // loop through each row of the ASCII art
            for(j = 0; j < 5; j++) {
                // use switch statement to print the ASCII art based on the code
                switch(code) {
                    case 65:
                        printf("  /\\  \n /  \\ \n/    \\\n");
                        break;
                    case 66:
                        printf(" ____ \n| __ )\n|  _ \\ \n| |_) |\n|____/\n");
                        break;
                    case 67:
                        printf("  ____ \n / ___|\n| |    \n| |___ \n \\____|\n");
                        break;
                    // add more cases for other characters
                    default:
                        printf("not recognized");
                        break;
                }
            }
        }
    }

    return 0;
}