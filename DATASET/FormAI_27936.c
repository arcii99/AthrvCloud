//FormAI DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 50

char inputString[MAX_STRING_LENGTH];
char outputString[MAX_STRING_LENGTH];

int main() {
    printf("Enter a string: ");
    scanf("%s", inputString);

    int stringLength = strlen(inputString);
    int vowelCount = 0;
    int consonantCount = 0;

    for (int i = 0; i < stringLength; i++) {
        char currentChar = inputString[i];

        if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u' || currentChar == 'A' || currentChar == 'E' || currentChar == 'I' || currentChar == 'O' || currentChar == 'U') {
            vowelCount++;
        } else if ((currentChar >= 'a' && currentChar <= 'z') || (currentChar >= 'A' && currentChar <= 'Z')) {
            consonantCount++;
        }
    }

    if (vowelCount > consonantCount) {
        printf("The string '%s' has more vowels.\n", inputString);
    } else if (vowelCount < consonantCount) {
        printf("The string '%s' has more consonants.\n", inputString);
    } else {
        printf("The string '%s' has an equal number of vowels and consonants.\n", inputString);
    }

    int currentIndex = 0;

    for (int i = stringLength - 1; i >= 0; i--) {
        outputString[currentIndex] = inputString[i];
        currentIndex++;
    }

    printf("The reversed string of '%s' is '%s'.\n", inputString, outputString);

    return 0;
}