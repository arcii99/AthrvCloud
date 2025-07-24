//FormAI DATASET v1.0 Category: Text processing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of occurrences of given character in the string
int count_char_in_string(char *str, char ch) {
    int count = 0;
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        if (str[i] == ch) {
            count++;
        }
    }

    return count;
}

int main() {
    char string[100];
    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = 0;  // Removing the newline character from the string

    char ch;
    printf("Enter a character to count in the string: ");
    scanf(" %c", &ch);

    int count = count_char_in_string(string, ch);

    printf("Number of occurrences of '%c' in the string is: %d\n", ch, count);

    return 0;
}