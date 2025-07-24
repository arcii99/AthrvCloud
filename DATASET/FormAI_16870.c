//FormAI DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {

    // declare variables
    char mainString[MAX_STRING_LENGTH];
    char subString[MAX_STRING_LENGTH];
    char replaceString[MAX_STRING_LENGTH];
    char newString[MAX_STRING_LENGTH];
    int replaceCount = 0;

    // get user input for main string
    printf("Enter main string: ");
    fgets(mainString, MAX_STRING_LENGTH, stdin);
    mainString[strcspn(mainString, "\n")] = '\0';

    // get user input for substring to replace
    printf("\nEnter sub string to replace: ");
    fgets(subString, MAX_STRING_LENGTH, stdin);
    subString[strcspn(subString, "\n")] = '\0';

    // get user input for replace string
    printf("\nEnter replace string: ");
    fgets(replaceString, MAX_STRING_LENGTH, stdin);
    replaceString[strcspn(replaceString, "\n")] = '\0';

    // find and replace substring in main string
    int mainStringLength = strlen(mainString);
    int subStringLength = strlen(subString);
    int replaceStringLength = strlen(replaceString);
    int startIndex = -1;

    for (int i = 0; i < mainStringLength; i++) {
        if (mainString[i] == subString[0]) {
            int j;
            for (j = 0; j < subStringLength; j++) {
                if (mainString[i + j] != subString[j])
                    break;
            }
            if (j == subStringLength) {
                startIndex = i;
                replaceCount++;
                for (j = 0; j < replaceStringLength; j++) {
                    newString[i + j] = replaceString[j];
                }
                i += subStringLength - 1;
            }
        }
        else {
            newString[i] = mainString[i];
        }
    }
    newString[mainStringLength + replaceCount * (replaceStringLength - subStringLength)] = '\0';

    // output results
    printf("\nMain string: %s", mainString);
    printf("\nSub string: %s", subString);
    printf("\nReplace string: %s", replaceString);
    printf("\nNew string: %s", newString);
    printf("\nNumber of replacements: %d", replaceCount);

    return 0;
}