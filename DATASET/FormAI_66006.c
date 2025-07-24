//FormAI DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50];

    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    printf("\nConcatenation of both strings: ");
    strcat(str1, str2);
    printf("%s", str1);

    printf("\nLength of string 1: %d", strlen(str1));

    printf("\nCopying string 1 into string 2: ");
    strcpy(str2, str1);
    printf("%s", str2);

    printf("\nReversing string 1: ");
    int length = strlen(str1);
    for (int i = 0; i < length / 2; i++) {
        char temp = str1[i];
        str1[i] = str1[length - i - 1];
        str1[length - i - 1] = temp;
    }
    printf("%s", str1);

    printf("\nSubstring of string 2: ");
    printf("%s", &str2[2]);

    printf("\nComparing both strings: ");
    int result = strcmp(str1, str2);
    if (result == 0)
        printf("Strings are equal");
    else if (result > 0)
        printf("String 1 is greater");
    else if (result < 0)
        printf("String 2 is greater");

    return 0;
}