//FormAI DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <string.h>

void getPassword(char password[], int max_len, int current_len) {
    char c;

    // If the password has reached its maximum length
    if (current_len == max_len) {
        printf("Password: %s\n", password);
        return;
    }

    // Get a character for the password
    printf("Enter character %d: ", current_len + 1);
    scanf(" %c", &c);

    // Validate the character
    if (c < 'a' || c > 'z') {
        printf("Invalid character. Please enter a lowercase letter.\n");
        getPassword(password, max_len, current_len);
        return;
    }

    // Store the character and get the next one
    password[current_len] = c;
    getPassword(password, max_len, current_len + 1);
}

int main() {
    int max_len;
    char password[100];

    // Get the maximum length for the password
    printf("Enter maximum length for password: ");
    scanf("%d", &max_len);

    // Get the password recursively
    getPassword(password, max_len, 0);

    return 0;
}