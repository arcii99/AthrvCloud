//FormAI DATASET v1.0 Category: String manipulation ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char new_str[100];
    int str_len, i;

    printf("Enter a string: ");
    gets(str);

    str_len = strlen(str);

    printf("\nThe entered string is: %s", str);
    printf("\nThe length of the string is: %d\n", str_len);

    for (i = 0; i < str_len; i++) {
        if (str[i] == 'e') {
            new_str[i] = 'z';
        } else if (str[i] == 'a') {
            new_str[i] = 'o';
        } else if (str[i] == 'i') {
            new_str[i] = 'y';
        } else {
            new_str[i] = str[i];
        }
    }

    printf("\nSurprise! Here is your new string: %s", new_str);
    printf("\nThe length of the new string is: %d", strlen(new_str));
    printf("\nHope you liked it! Bye!\n");

    return 0;
}