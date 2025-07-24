//FormAI DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Function to count the number of vowels in a string */
int countVowels(char* str) {
    int count = 0;
    while(*str) {
        if (tolower(*str) == 'a' || tolower(*str) == 'e' || tolower(*str) == 'i' || tolower(*str) == 'o' || tolower(*str) == 'u')
            count++;
        str++;
    }
    return count;
}

int main() {
    char input[100];
    char output[100];
    /* Get input from user */
    printf("Enter a string: ");
    scanf("%[^\n]s", input);

    /* Count the number of vowels in the string */
    int vowelCount = countVowels(input);

    /* Reverse the string */
    int len = strlen(input);
    int i, j;
    for (i = len - 1, j = 0; i >= 0; i--, j++)
        output[j] = input[i];
    output[j] = '\0';

    /* Convert all characters to uppercase */
    for (i = 0; output[i] != '\0'; i++)
        output[i] = toupper(output[i]);

    /* Print the output */
    printf("Your input string: %s\n", input);
    printf("Number of vowels in the string: %d\n", vowelCount);
    printf("Reversed string in all uppercase: %s\n", output);

    return 0;
}