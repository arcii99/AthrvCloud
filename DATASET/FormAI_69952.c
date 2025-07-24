//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

int main() {
    char username[20];
    char password[20];

    printf("Enter your username: ");
    fgets(username, 20, stdin);
    printf("Enter your password: ");
    fgets(password, 20, stdin);

    // check for newline character at the end of input
    if (strcmp(&username[strlen(username)-1], "\n") != 0) {
        while (fgetc(stdin) != '\n');
    }
    if (strcmp(&password[strlen(password)-1], "\n") != 0) {
        while (fgetc(stdin) != '\n');
    }

    // remove any non-alphanumeric characters from username
    char sanitized_username[20];
    int j = 0;
    for (int i = 0; i < strlen(username); i++) {
        if (isalnum(username[i])) {
            sanitized_username[j] = username[i];
            j++;
        }
    }
    sanitized_username[j] = '\0';

    // remove any non-alphanumeric characters from password
    char sanitized_password[20];
    j = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isalnum(password[i])) {
            sanitized_password[j] = password[i];
            j++;
        }
    }
    sanitized_password[j] = '\0';

    printf("Sanitized username: %s\n", sanitized_username);
    printf("Sanitized password: %s\n", sanitized_password);

    return 0;
}