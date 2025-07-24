//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 20

int main() {
    char password[MAX_LEN + 1];
    char available_chars[] = "!@#$%^&*()-=_+[]{}|;':\",./<>?0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int num_chars = sizeof(available_chars) - 1;
    int len;
    int i;

    srand(time(NULL));

    printf("Welcome to the C Secure Password Generator!\n");

    // Prompt the user for the desired password length.
    printf("Please enter the desired password length (1-%d): ", MAX_LEN);
    scanf("%d", &len);

    // Check that the desired length is within bounds.
    if (len < 1 || len > MAX_LEN) {
        printf("Error: Invalid password length.\n");
        return 1;
    }

    // Generate the password.
    for (i = 0; i < len; i++) {
        password[i] = available_chars[rand() % num_chars];
    }
    password[len] = '\0';

    // Print the generated password and exit.
    printf("Generated password: %s\n", password);
    return 0;
}