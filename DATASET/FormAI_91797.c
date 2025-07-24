//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char input[MAX_LEN], output[MAX_LEN];
    printf("Enter text to convert to ASCII art:\n");
    fgets(input, MAX_LEN, stdin);

    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (c >= 97 && c <= 122) { // lowercase letters
            sprintf(output + strlen(output), " _ \n");
            sprintf(output + strlen(output), "/ \\ \n");
            sprintf(output + strlen(output), "\\_/ \n");
        } else if (c >= 65 && c <= 90) { // uppercase letters
            sprintf(output + strlen(output), " _  _ \n");
            sprintf(output + strlen(output), "| || |\n");
            sprintf(output + strlen(output), "|_||_|\n");
        } else if (c >= 48 && c <= 57) { // numbers
            switch (c) {
                case '0':
                    sprintf(output + strlen(output), " ___ \n");
                    sprintf(output + strlen(output), "|   |\n");
                    sprintf(output + strlen(output), "|_|_|\n");
                    break;
                case '1':
                    sprintf(output + strlen(output), "  | \n");
                    sprintf(output + strlen(output), "  | \n");
                    sprintf(output + strlen(output), "  | \n");
                    break;
                case '2':
                    sprintf(output + strlen(output), " ___ \n");
                    sprintf(output + strlen(output), "  _|\n");
                    sprintf(output + strlen(output), " |__\n");
                    break;
                case '3':
                    sprintf(output + strlen(output), " ___ \n");
                    sprintf(output + strlen(output), "  _|\n");
                    sprintf(output + strlen(output), " ___|\n");
                    break;
                case '4':
                    sprintf(output + strlen(output), "   |\n");
                    sprintf(output + strlen(output), " |_| \n");
                    sprintf(output + strlen(output), "   |\n");
                    break;
                case '5':
                    sprintf(output + strlen(output), " ___\n");
                    sprintf(output + strlen(output), "|__ \n");
                    sprintf(output + strlen(output), " ___|\n");
                    break;
                case '6':
                    sprintf(output + strlen(output), " ___\n");
                    sprintf(output + strlen(output), "|__ \n");
                    sprintf(output + strlen(output), "|___|\n");
                    break;
                case '7':
                    sprintf(output + strlen(output), " ___\n");
                    sprintf(output + strlen(output), "   /\n");
                    sprintf(output + strlen(output), "  /\n");
                    break;
                case '8':
                    sprintf(output + strlen(output), " ___ \n");
                    sprintf(output + strlen(output), "|___|\n");
                    sprintf(output + strlen(output), "|___|\n");
                    break;
                case '9':
                    sprintf(output + strlen(output), " ___ \n");
                    sprintf(output + strlen(output), "|___|\n");
                    sprintf(output + strlen(output), "    |\n");
                    break;
            }
        } else if (c == ' ') { // space
            sprintf(output + strlen(output), "  \n");
        } else if (c == '\n') { // new line
            sprintf(output + strlen(output), "\n");
        } else { // unknown character
            sprintf(output + strlen(output), "?\n");
        }
    }

    printf("\nASCII art:\n%s", output);

    return 0;
}