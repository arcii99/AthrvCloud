//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void checkPalindrome(char *str) {

char cleanStr[strlen(str)];
int len = strlen(str);

int i, j = 0;
// Remove all non-alphanumeric characters and convert to lowercase
for (i = 0; i < len; i++) {
    if (isalnum(str[i])) {
        cleanStr[j++] = tolower(str[i]);
    }
}
cleanStr[j] = '\0';

// Check if the cleaned string is a palindrome
int start = 0;
int end = strlen(cleanStr) - 1;

while (start < end) {
    if (cleanStr[start++] != cleanStr[end--]) {
        printf("%s is not a palindrome.\n", str);
        return;
    }
}
printf("%s is a palindrome!\n", str);

}

int main() {

char userInput[50];

printf("Enter a word or phrase to check if it's a palindrome: ");
fgets(userInput, 50, stdin);
userInput[strcspn(userInput, "\n")] = 0;

checkPalindrome(userInput);

return 0;
}