//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main() {
    char alienLang[6][10] = {
        {'a', '*'}, {'b', '@'}, {'c', '$'}, {'d', '#'}, {'e', '!'}
    };
    char inputStr[100], outputStr[100] = "", tempStr[2];
    int i, j, k, flag, len;

    printf("Enter a string in Alien language: ");
    scanf("%[^\n]s", inputStr);
    len = strlen(inputStr);

    for(i = 0; i < len; i++) {
        flag = 0;
        for(j = 0; j < 5; j++) {
            if(alienLang[j][0] == inputStr[i]) {
                tempStr[0] = alienLang[j][1];
                tempStr[1] = '\0';
                strcat(outputStr, tempStr);
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            tempStr[0] = inputStr[i];
            tempStr[1] = '\0';
            strcat(outputStr, tempStr);
        }
    }

    printf("The translated string is: %s", outputStr);
    return 0;
}