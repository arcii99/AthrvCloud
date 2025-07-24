//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter your message in English: ");
    fgets(input, sizeof(input), stdin);
    char medieval[1000] = "\0";

    for (int i = 0; i < strlen(input); i++) {
        switch (input[i]) {
            case 'a':
            case 'A':
                strcat(medieval, "Aye ");
                break;
            case 'b':
            case 'B':
                strcat(medieval, "Be ");
                break;
            case 'c':
            case 'C':
                strcat(medieval, "Char ");
                break;
            case 'd':
            case 'D':
                strcat(medieval, "Dost ");
                break;
            case 'e':
            case 'E':
                strcat(medieval, "E'er ");
                break;
            case 'f':
            case 'F':
                strcat(medieval, "Forsooth ");
                break;
            case 'g':
            case 'G':
                strcat(medieval, "Gar ");
                break;
            case 'h':
            case 'H':
                strcat(medieval, "'Hark ");
                break;
            case 'i':
            case 'I':
                strcat(medieval, "I ");
                break;
            case 'j':
            case 'J':
                strcat(medieval, "Joust ");
                break;
            case 'k':
            case 'K':
                strcat(medieval, "Knavery ");
                break;
            case 'l':
            case 'L':
                strcat(medieval, "Leverage ");
                break;
            case 'm':
            case 'M':
                strcat(medieval, "Mark ");
                break;
            case 'n':
            case 'N':
                strcat(medieval, "Nay ");
                break;
            case 'o':
            case 'O':
                strcat(medieval, "On ");
                break;
            case 'p':
            case 'P':
                strcat(medieval, "Prithee ");
                break;
            case 'q':
            case 'Q':
                strcat(medieval, "Quash ");
                break;
            case 'r':
            case 'R':
                strcat(medieval, "Rapscallion ");
                break;
            case 's':
            case 'S':
                strcat(medieval, "Sirrah ");
                break;
            case 't':
            case 'T':
                strcat(medieval, "Thee ");
                break;
            case 'u':
            case 'U':
                strcat(medieval, "Urchin ");
                break;
            case 'v':
            case 'V':
                strcat(medieval, "Verily ");
                break;
            case 'w':
            case 'W':
                strcat(medieval, "Wherefore ");
                break;
            case 'x':
            case 'X':
                strcat(medieval, "Xanthippe ");
                break;
            case 'y':
            case 'Y':
                strcat(medieval, "Ye ");
                break;
            case 'z':
            case 'Z':
                strcat(medieval, "Zounds ");
                break;
            case ' ':
            case '\t':
            case '\n':
                strcat(medieval, " ");
                break;
            default:
                strcat(medieval, "??? ");
                break;
        }
    }

    printf("\nThine message in medieval style: %s\n", medieval);

    return 0;
}