//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20

int main() {
    int i, ascii_value;
    char password[MAX_PASSWORD_LENGTH + 1];
    const char symbols[] = "!@#$%^&*()_+-={}[]\\|<,>.?/';:`\"";
    const char numbers[] = "0123456789";
    const char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    const char* character_set[] = { symbols, numbers, uppercase_letters, lowercase_letters };
    int set_sizes[] = { sizeof(symbols) - 1, sizeof(numbers) - 1, sizeof(uppercase_letters) - 1, sizeof(lowercase_letters) - 1 };
    int total_sets = sizeof(character_set) / sizeof(char*);

    // Randomly select a size for the password between 8 and MAX_PASSWORD_LENGTH.
    int password_length = (rand() % (MAX_PASSWORD_LENGTH - 8 + 1)) + 8;

    srand(time(NULL));

    // Fill the first character of the password with a random uppercase letter.
    password[0] = uppercase_letters[rand() % set_sizes[2]];

    // Fill the rest of the password with characters randomly selected from all the character sets.
    for (i = 1; i < password_length; i++) {
        int set_index = rand() % total_sets;
        ascii_value = character_set[set_index][rand() % set_sizes[set_index]];
        password[i] = ascii_value;
    }

    // Shuffle the password using Fisher-Yates shuffle algorithm.
    for (i = password_length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Print the generated password.
    printf("Generated Password: %s\n", password);

    return 0;
}