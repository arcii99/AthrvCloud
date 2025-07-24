//FormAI DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include <stdio.h>
#include <ctype.h>

int main() {
    char inputString[1000];

    printf("Enter a string:\n");
    scanf("%[^\n]s", inputString);
    int count = 0;
    int wordCount = 0;
    int i = 0;
    while (inputString[i] != '\0') {
        if (isspace(inputString[i])) {
            count = 0;
        }
        else {
            count++;
            if (count == 1) {
                wordCount++;
            }
        }
        i++;
    }

    printf("Word Count: %d\n", wordCount);

    return 0;
}