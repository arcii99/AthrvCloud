//FormAI DATASET v1.0 Category: String manipulation ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char inputStr[100], outputStr[100];
    int i, j, len;

    printf("Enter a string: ");
    scanf("%s", inputStr);

    len = strlen(inputStr);
    for (i = 0, j = 0; i < len; i += 2, j += 1) {
        outputStr[j] = inputStr[i];
    }
    outputStr[j] = '\0';

    printf("Output string: %s\n", outputStr);
    return 0;
}