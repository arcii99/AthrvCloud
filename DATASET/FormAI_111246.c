//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char message[100];
    char translation[100];
    int input_len, i, j, paranoia_level;

    printf("Welcome to the Alien Language Translator. \n");
    printf("Please enter the message you would like to translate: \n");

    fgets(message, sizeof(message), stdin);

    printf("Enter paranoia level (1-10): ");
    scanf("%d", &paranoia_level);

    switch (paranoia_level) {
        case 1:
            printf("Translating at paranoia level 1...\n");
            break;
        case 2:
            printf("Translating at paranoia level 2...\n");
            break;
        case 3:
            printf("Translating at paranoia level 3...\n");
            break;
        case 4:
            printf("Translating at paranoia level 4...\n");
            break;
        case 5:
            printf("Translating at paranoia level 5...\n");
            break;
        case 6:
            printf("Translating at paranoia level 6...\n");
            break;
        case 7:
            printf("Translating at paranoia level 7...\n");
            break;
        case 8:
            printf("Translating at paranoia level 8...\n");
            break;
        case 9:
            printf("Translating at paranoia level 9...\n");
            break;
        case 10:
            printf("Translating at paranoia level 10...\n");
            break;
        default:
            printf("Paranoia level not valid.");
            return 0;
    }

    input_len = strlen(message);

    for (i = 0; i < input_len; i++) {

        switch (message[i]) {

            case 'A':
            case 'a':
                for (j = 0; j < paranoia_level; j++) {
                    strcat(translation, "**");
                }
                strcat(translation, " ");
                break;

            case 'B':
            case 'b':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "**");
                }
                strcat(translation, ". ");
                break;

            case 'C':
            case 'c':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "**");
                }
                strcat(translation, "|\\/");
                break;

            case 'D':
            case 'd':
                for (j = 0; j < paranoia_level; j++) {
                    strcat(translation, "|#");
                }
                strcat(translation, " ");
                break;

            case 'E':
            case 'e':
                 for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "**");
                }
                strcat(translation, "...");
                break;

            case 'F':
            case 'f':
                for (j = 0; j < paranoia_level; j++) {
                    strcat(translation, "}");
                }
                strcat(translation, " ");
                break;

            case 'G':
            case 'g':
                for (j = 0; j < paranoia_level; j++) {
                    strcat(translation, "6");
                }
                strcat(translation, " ");
                break;

            case 'H':
            case 'h':
                 for (j = 0; j < paranoia_level; j++) {
                    strcat(translation, "#");
                }
                strcat(translation, " ");
                break;

            case 'I':
            case 'i':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "..");
                }
                strcat(translation, "|");
                break;

            case 'J':
            case 'j':
                 for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "..");
                }
                strcat(translation, "_/");
                break;

            case 'K':
            case 'k':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "|<");
                }
                strcat(translation, " ");
                break;

            case 'L':
            case 'l':
                for (j = 0; j < paranoia_level; j++) {
                    strcat(translation, "|_");
                }
                strcat(translation, " ");
                break;

            case 'M':
            case 'm':
                 for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "/\\\\");
                }
                strcat(translation, " ");
                break;

            case 'N':
            case 'n':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "|\\|");
                }
                strcat(translation, " ");
                break;

            case 'O':
            case 'o':
                for (j = 0; j < paranoia_level; j++) {
                    strcat(translation, "0");
                }
                strcat(translation, " ");
                break;

            case 'P':
            case 'p':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "|*");
                }
                strcat(translation, "|");
                break;

            case 'Q':
            case 'q':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "|_\\/\\");
                }
                strcat(translation, " ");
                break;

            case 'R':
            case 'r':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "|^");
                }
                strcat(translation, "\\");
                break;

            case 'S':
            case 's':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "~");
                }
                strcat(translation, " ");
                break;

            case 'T':
            case 't':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "--");
                }
                strcat(translation, "'");
                break;

            case 'U':
            case 'u':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "| |");
                }
                strcat(translation, " ");
                break;

            case 'V':
            case 'v':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "\\/");
                }
                strcat(translation, "\\/");
                break;

            case 'W':
            case 'w':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "|/\\|/");
                }
                strcat(translation, " ");
                break;

            case 'X':
            case 'x':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "\\\\/");
                }
                strcat(translation, "/");
                break;

            case 'Y':
            case 'y':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "\\_/");
                }
                strcat(translation, " ");
                break;

            case 'Z':
            case 'z':
                for (j = 0; j < paranoia_level / 2; j++) {
                    strcat(translation, "/\\");
                }
                strcat(translation, "..");
                break;

            default:
                strcat(translation, " ");
                break;
        }
    }

    printf("\nTranslation: %s", translation);

    return 0;
}