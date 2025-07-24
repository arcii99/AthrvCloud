//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

char* generate_password() {
    char *password = malloc(sizeof(char) * PASSWORD_LENGTH);

    // Set up possible characters to use in password
    char lower_case[] = "abcdefghijklmnopqrstuvwxyz";
    char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-=[]{}|;':\"<>,./?\\`~";

    char all_chars[72];
    for (int i = 0; i < 26; i++) {
        all_chars[i] = lower_case[i];
        all_chars[i+26] = upper_case[i];
    }
    for (int i = 0; i < 10; i++) {
        all_chars[i+52] = numbers[i];
    }
    for (int i = 0; i < 8; i++) {
        all_chars[i+62] = symbols[i];
    }

    // Generate random password using allowed characters
    srand(time(NULL));
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = all_chars[rand() % 72];
    }

    return password;
}

int main() {
    char *password = generate_password();
    printf("Generated password: %s\n", password);
    free(password);
    return 0;
}