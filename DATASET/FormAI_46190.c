//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    char text[50];
    char ascii[14][100];
    int i, j, k, len;

    printf("Enter some text to convert to ASCII art:\n");
    scanf("%[^\n]%*c", text);
    len = strlen(text);

    for (i = 0; i < 14; i++) {
        for (j = 0; j < len; j++) {
            if (text[j] >= 'a' && text[j] <= 'z') {
                k = text[j] - 'a';
            } else if (text[j] >= 'A' && text[j] <= 'Z') {
                k = text[j] - 'A';
            } else {
                k = 26;
            }
            switch (i) {
                case 0:
                    strcpy(ascii[i], "   /\\");
                    break;
                case 1:
                    strcpy(ascii[i], "  /  \\\n");
                    if (j == len - 1) {
                        strcat(ascii[i], "<   ^  >");
                    } else {
                        strcat(ascii[i], "|   ^  |");
                    }
                    break;
                case 2:
                    strcpy(ascii[i], " /    \\\n");
                    if (j == len - 1) {
                        strcat(ascii[i], "|  ==  |");
                    } else {
                        strcat(ascii[i], "|   O  |");
                    }
                    break;
                case 3:
                    strcpy(ascii[i], "/      \\");
                    break;
                case 4:
                    if (j == len - 1) {
                        strcat(ascii[i], "|      |\n");
                    } else {
                        strcat(ascii[i], "|   U  |\n");
                    }
                    break;
                case 5:
                    strcpy(ascii[i], "|      |\n");
                    break;
                case 6:
                    strcpy(ascii[i], "|      |\n");
                    break;
                case 7:
                    strcpy(ascii[i], "|      |\n");
                    break;
                case 8:
                    strcpy(ascii[i], "|______|\n");
                    break;
                case 9:
                    switch (k) {
                        case 0:
                            strcat(ascii[i], " /\\\n");
                            strcat(ascii[i], "/  \\\n");
                            strcat(ascii[i], "\\  /\n");
                            strcat(ascii[i], " \\/ ");
                            break;
                        case 1:
                            strcat(ascii[i], " /\\\n");
                            strcat(ascii[i], "/__\\");
                            break;
                        case 2:
                            strcat(ascii[i], "/\\/\\/\n");
                            strcat(ascii[i], "\\/\\/ ");
                            break;
                        case 3:
                            strcat(ascii[i], "/----\\\n");
                            strcat(ascii[i], "\\____/");
                            break;
                        case 4:
                            strcat(ascii[i], "/    \\\n");
                            strcat(ascii[i], "| (_) |\n");
                            strcat(ascii[i], "\\___/ ");
                            break;
                        case 5:
                            strcat(ascii[i], "/---\\n");
                            strcat(ascii[i], "||||");
                            break;
                        case 6:
                            strcat(ascii[i], "/\\   /\n");
                            strcat(ascii[i], "\\ \\ / /\n");
                            strcat(ascii[i], " \\ V / \n");
                            strcat(ascii[i], "  \\_/  ");
                            break;
                        case 7:
                            strcat(ascii[i], "/----\\\n");
                            strcat(ascii[i], "     /_)\n");
                            strcat(ascii[i], "    /   ");
                            break;
                        case 8:
                            strcat(ascii[i], " /\\\n");
                            strcat(ascii[i], "/__\\n");
                            strcat(ascii[i], "\\  /\n");
                            strcat(ascii[i], " \\/ ");
                            break;
                        case 9:
                            strcat(ascii[i], " /\\\n");
                            strcat(ascii[i], "/__\\n");
                            strcat(ascii[i], "\\__/n");
                            strcat(ascii[i], "+");
                            break;
                        case 26:
                            strcat(ascii[i], "     \n");
                            break;
                    }
                    break;
                case 10:
                    switch (k) {
                        case 0:
                            strcat(ascii[i], "/  \\");
                            break;
                        case 1:
                            strcat(ascii[i], "\\  /\n");
                            strcat(ascii[i], " \\/ ");
                            break;
                        case 2:
                            strcat(ascii[i], "   /\\\n");
                            strcat(ascii[i], "  /  \\\n");
                            strcat(ascii[i], " / /\\ \\\n");
                            strcat(ascii[i], " \\/__\\/");
                            break;
                        case 3:
                            strcat(ascii[i], "__\n");
                            strcat(ascii[i], "  /_/\\\n");
                            strcat(ascii[i], " \\_\_\\\n");
                            break;
                        case 4:
                            strcat(ascii[i], "\\___/\n");
                            strcat(ascii[i], "/   \\\n");
                            strcat(ascii[i], "\\_o_/ ");
                            break;
                        case 5:
                            strcat(ascii[i], " |  |\n");
                            strcat(ascii[i], "/    \\\n");
                            strcat(ascii[i], "\\____/\n");
                            break;
                        case 6:
                            strcat(ascii[i], "__   __\n");
                            strcat(ascii[i], "\\ \\ / /\n");
                            strcat(ascii[i], " \\ V /\n");
                            strcat(ascii[i], "  \\_/ ");
                            break;
                        case 7:
                            strcat(ascii[i], "__\n");
                            strcat(ascii[i], "\\ /\n");
                            strcat(ascii[i], " | \\\n");
                            strcat(ascii[i], "/_/ ");
                            break;
                        case 8:
                            strcat(ascii[i], "/__\\\n");
                            strcat(ascii[i], "\\  /\n");
                            strcat(ascii[i], " \\/ ");
                            break;
                        case 9:
                            strcat(ascii[i], " |  |\n");
                            strcat(ascii[i], " |  |\n");
                            strcat(ascii[i], " |_/\n");
                            strcat(ascii[i], " /__\\");
                            break;
                        case 26:
                            strcat(ascii[i], "     \n");
                            break;
                    }
                    break;
                case 11:
                    switch (k) {
                        case 0:
                            strcat(ascii[i], "\\  /");
                            break;
                        case 1:
                            strcat(ascii[i], "   /\\\n");
                            strcat(ascii[i], "  /  \\\n");
                            strcat(ascii[i], " / /__\\\n");
                            strcat(ascii[i], " \\____/");
                            break;
                        case 2:
                            strcat(ascii[i], "  /\\\n");
                            strcat(ascii[i], " /  \\\n");
                            strcat(ascii[i], "//\\/\n");
                            strcat(ascii[i], "\\/  ");
                            break;
                        case 3:
                            strcat(ascii[i], "  __/\\\n");
                            strcat(ascii[i], "   /_/\n");
                            strcat(ascii[i], "  /  \\\n");
                            strcat(ascii[i], "  \\__/");
                            break;
                        case 4:
                            strcat(ascii[i], " _  _\n");
                            strcat(ascii[i], "| || |\n");
                            strcat(ascii[i], "| || |\n");
                            strcat(ascii[i], "|_||_|");
                            break;
                        case 5:
                            strcat(ascii[i], "  /\\\n");
                            strcat(ascii[i], "/|~~|\\\n");
                            strcat(ascii[i], "\\\\/\\//\n");
                            strcat(ascii[i], " \\/__/");
                            break;
                        case 6:
                            strcat(ascii[i], " __   __\n");
                            strcat(ascii[i], "/ /\\ / /\n");
                            strcat(ascii[i], "\\/  \\_\n");
                            strcat(ascii[i], "     (_) ");
                            break;
                        case 7:
                            strcat(ascii[i], " __\n");
                            strcat(ascii[i], "/  |\n");
                            strcat(ascii[i], "|_ \\\n");
                            strcat(ascii[i], "|__/ ");
                            break;
                        case 8:
                            strcat(ascii[i], "/__\\\n");
                            strcat(ascii[i], "|  |\n");
                            strcat(ascii[i], "|__| ");
                            break;
                        case 9:
                            strcat(ascii[i], ",~~~~.\n");
                            strcat(ascii[i], "\\_00_/");
                            strcat(ascii[i], " ||\n");
                            strcat(ascii[i], " |''|");
                            break;
                        case 26:
                            strcat(ascii[i], "     \n");
                            break;
                    }
                    break;
                case 12:
                    switch (k) {
                        case 0:
                            strcat(ascii[i], " \\/ ");
                            break;
                        case 1:
                            strcat(ascii[i], " /__/\\\n");
                            strcat(ascii[i], " \\/__/");
                            break;
                        case 2:
                            strcat(ascii[i], "  /\\/\n");
                            strcat(ascii[i], " /  \\\n");
                            strcat(ascii[i], "/__/\\/\n");
                            strcat(ascii[i], "\\__\\/ ");
                            break;
                        case 3:
                            strcat(ascii[i], " /~~~~\\\n");
                            strcat(ascii[i], "/_/  \\\n");
                            strcat(ascii[i], "\\ \\__/\\\n");
                            strcat(ascii[i], " \\____/");
                            break;
                        case 4:
                            strcat(ascii[i], "  ___\n");
                            strcat(ascii[i], " | o )\n");
                            strcat(ascii[i], " | o \\\n");
                            strcat(ascii[i], " |___/");
                            break;
                        case 5:
                            strcat(ascii[i], "  /\\\n");
                            strcat(ascii[i], " /~~\\\n");
                            strcat(ascii[i], " \\__/\\\n");
                            strcat(ascii[i], "    \\/ ");
                            break;
                        case 6:
                            strcat(ascii[i], " __   __\n");
                            strcat(ascii[i], "/ /_\\ /_\\\n");
                            strcat(ascii[i], "\\ \\_/ \\_/\n");
                            strcat(ascii[i], " \\___/   ");
                            break;
                        case 7:
                            strcat(ascii[i], "__\n");
                            strcat(ascii[i], "\\ |\n");
                            strcat(ascii[i], " \\|\n");
                            strcat(ascii[i], " /| ");
                            break;
                        case 8:
                            strcat(ascii[i], " /__\\\n");
                            strcat(ascii[i], "|__|\n");
                            strcat(ascii[i], "|__| ");
                            break;
                        case 9:
                            strcat(ascii[i], " \\_/\n");
                            strcat(ascii[i], "(oo)\n");
                            strcat(ascii[i], " ||\n");
                            strcat(ascii[i], "===");
                            break;
                        case 26:
                            strcat(ascii[i], "     \n");
                            break;
                    }
                    break;
                case 13:
                    switch (k) {
                        case 0:
                            strcat(ascii[i], "    ");
                            break;
                        case 1:
                            strcat(ascii[i], " /__/\n");
                            strcat(ascii[i], " \\__\\");
                            break;
                        case 2:
                            strcat(ascii[i], "  \\/\n");
                            strcat(ascii[i], " /  \\\n");
                            strcat(ascii[i], "/__/\\\n");
                            strcat(ascii[i], "\\__\\/");
                            break;
                        case 3:
                            strcat(ascii[i], " /$$$$$$\\\n");
                            strcat(ascii[i], "|$|_____\\$\n");
                            strcat(ascii[i], "|$$$$$$$$\n");
                            strcat(ascii[i], "\\________/");
                            break;
                        case 4:
                            strcat(ascii[i], "  ___\n");
                            strcat(ascii[i], " /   \\\n");
                            strcat(ascii[i], "| (_) |\n");
                            strcat(ascii[i], " \\___/");
                            break;
                        case 5:
                            strcat(ascii[i], "    /\\\n");
                            strcat(ascii[i], "   /~~\\\n");
                            strcat(ascii[i], "  /_/\\_\\\n");
                            strcat(ascii[i], " /_/\\_\\");
                            break;
                        case 6:
                            strcat(ascii[i], " ____ ___\n");
                            strcat(ascii[i], "/__\\/__/\\\n");
                            strcat(ascii[i], "\\__\\__\\/\n");
                            strcat(ascii[i], "        ");
                            break;
                        case 7:
                            strcat(ascii[i], " __\n");
                            strcat(ascii[i], "|_/\n");
                            strcat(ascii[i], " |\n");
                            strcat(ascii[i], "|_\\ ");
                            break;
                        case 8:
                            strcat(ascii[i], "     \n");
                            strcat(ascii[i], "|__|\n");
                            strcat(ascii[i], " |__|");
                            break;
                        case 9:
                            strcat(ascii[i], " \\/\n");
                            strcat(ascii[i], " **\n");
                            strcat(ascii[i], "||\n");
                            strcat(ascii[i], "  ==  ");
                            break;
                        case 26:
                            strcat(ascii[i], "     \n");
                            break;
                    }
                    break;
            }
            strcat(ascii[i], " ");
        }
    }

    for (i = 0; i < 14; i++) {
        printf("%s\n", ascii[i]);
    }

    return 0;
}