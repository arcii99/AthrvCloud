//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    // Cybernetic input manager

    printf("Welcome to the Cyber Input Manager!\n");
    printf("Enter your name: ");

    char name[50];
    fgets(name, sizeof(name), stdin);

    // Sanitize user input
    int len = strlen(name);
    if(len > 0 && name[len - 1] == '\n')  name[len - 1] = '\0';

    char sanitized_name[50];
    for(int i=0; i<len; i++) {
        sanitized_name[i] = tolower(name[i]);
    }

    printf("Welcome, %s!\n", sanitized_name);
    printf("Enter your password: ");

    char password[50];
    fgets(password, sizeof(password), stdin);

    // Sanitize user input
    len = strlen(password);
    if(len > 0 && password[len - 1] == '\n')  password[len - 1] = '\0';

    char sanitized_password[50];
    for(int i=0; i<len; i++) {
        sanitized_password[i] = isdigit(password[i]) ? '*' : password[i];
    }

    printf("Your sanitized password is: %s\n", sanitized_password);

    return 0;
}