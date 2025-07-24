//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: minimalist
#include <stdio.h>
#include <string.h>

char *cat_translator(char word[]) {
    char cat_language[] = "";
    int length = strlen(word);
    int index;

    for (index = 0; index < length; index++) {
        switch (word[index]) {
            case 'a':
                strcat(cat_language, "nya ");
                break;
            case 'b':
                strcat(cat_language, "pur ");
                break;
            case 'c':
                strcat(cat_language, "meow ");
                break;
            case 'd':
                strcat(cat_language, "mew ");
                break;
            case 'e':
                strcat(cat_language, "hiss ");
                break;
            case 'f':
                strcat(cat_language, "purr ");
                break;
            case 'g':
                strcat(cat_language, "miaow ");
                break;
            case 'h':
                strcat(cat_language, "pounce ");
                break;
            case 'i':
                strcat(cat_language, "claw ");
                break;
            case 'j':
                strcat(cat_language, "whisker ");
                break;
            case 'k':
                strcat(cat_language, "scratch ");
                break;
            case 'l':
                strcat(cat_language, "cuddle ");
                break;
            case 'm':
                strcat(cat_language, "nip ");
                break;
            case 'n':
                strcat(cat_language, "lick ");
                break;
            case 'o':
                strcat(cat_language, "yowl ");
                break;
            case 'p':
                strcat(cat_language, "snuggle ");
                break;
            case 'q':
                strcat(cat_language, "curl ");
                break;
            case 'r':
                strcat(cat_language, "tail ");
                break;
            case 's':
                strcat(cat_language, "nap ");
                break;
            case 't':
                strcat(cat_language, "paw ");
                break;
            case 'u':
                strcat(cat_language, "furry ");
                break;
            case 'v':
                strcat(cat_language, "whisker ");
                break;
            case 'w':
                strcat(cat_language, "stretch ");
                break;
            case 'x':
                strcat(cat_language, "tangle ");
                break;
            case 'y':
                strcat(cat_language, "mewl ");
                break;
            case 'z':
                strcat(cat_language, "furball ");
                break;
            default:
                strcat(cat_language, "");
                break;
        }
    }
    return cat_language;
}

int main() {
    char input[100];
    printf("Enter a word to translate to Cat Language: ");
    fgets(input, 100, stdin);
    printf("Translation: %s\n", cat_translator(input));
    return 0;
}