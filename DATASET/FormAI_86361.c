//FormAI DATASET v1.0 Category: String manipulation ; Style: modular
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void reverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

int count(char str[], char c) {
    int cnt = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == c)
            cnt++;
    return cnt;
}

int palindrome(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (str[start] != str[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}


void capitalize(char str[]) {
    for (int i = 0; i < strlen(str); i++)
        str[i] = toupper(str[i]);
}

int main() {
    char str[MAX_LEN];
    printf("Enter a string (max length of %d characters): ", MAX_LEN);
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Original string: %s\n", str);

    // Reverse the string
    reverse(str);
    printf("Reversed string: %s\n", str);

    // Count the number of times a character appears
    char c = 'e';
    int cnt = count(str, c);
    printf("The character '%c' appears %d times.\n", c, cnt);

    // Check if the string is a palindrome
    if(palindrome(str))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    // Capitalize the string
    capitalize(str);
    printf("Capitalized string: %s\n", str);

    return 0;
}