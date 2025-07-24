//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: medieval
#include <stdio.h>
#include <string.h>

int checkPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    printf("Greetings traveler!\n");
    printf("Pray tell, what word would thee like to check for palindromic properties?\n");
    scanf("%s", str);

    if (checkPalindrome(str)) {
        printf("Verily, '%s' is a palindrome. Well done!\n", str);
    } else {
        printf("Alack! '%s' is not a palindrome. Try again, good sir!\n", str);
    }

    printf("Farewell, traveler!\n");
    return 0;
}