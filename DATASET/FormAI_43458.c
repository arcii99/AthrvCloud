//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: safe
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>

#define NUM_UPPER 26
#define NUM_LOWER 26
#define NUM_DIGITS 10
#define NUM_SPECIAL 8

const char upper_alphabet[NUM_UPPER + 1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char lower_alphabet[NUM_LOWER + 1] = "abcdefghijklmnopqrstuvwxyz";
const char digits[NUM_DIGITS + 1] = "0123456789";
const char special_chars[NUM_SPECIAL + 1] = "!@#$%^&*";

/**
 * Function to generate a random integer between `min` and `max`.
 */
int rand_int(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

/**
 * Function to generate a random character from the given set of `chars`.
 */
char rand_char(const char* chars, size_t len) {
    return chars[rand_int(0, len - 1)];
}

/**
 * Function to generate a secure password of length `password_len`.
 */
void generate_password(char* password, size_t password_len) {
    int num_upper_chars = rand_int(1, password_len / 3);
    int num_lower_chars = rand_int(1, password_len / 3);
    int num_digit_chars = rand_int(1, password_len / 3);
    int num_special_chars = password_len - num_upper_chars - num_lower_chars - num_digit_chars;

    size_t i = 0;
    for (int j = 0; j < num_upper_chars; j++, i++) {
        password[i] = rand_char(upper_alphabet, NUM_UPPER);
    }

    for (int j = 0; j < num_lower_chars; j++, i++) {
        password[i] = rand_char(lower_alphabet, NUM_LOWER);
    }

    for (int j = 0; j < num_digit_chars; j++, i++) {
        password[i] = rand_char(digits, NUM_DIGITS);
    }

    for (int j = 0; j < num_special_chars; j++, i++) {
        password[i] = rand_char(special_chars, NUM_SPECIAL);
    }

    // Shuffle the password
    for (size_t i = password_len - 1; i > 0; i--) {
        size_t j = rand_int(0, i);
        char tmp = password[j];
        password[j] = password[i];
        password[i] = tmp;
    }
}

/**
 * Function to check if a string contains at least one uppercase character.
 */
int contains_upper(const char* str) {
    while (*str) {
        if (isupper(*str)) {
            return 1;
        }
        str++;
    }
    return 0;
}

/**
 * Function to check if a string contains at least one lowercase character.
 */
int contains_lower(const char* str) {
    while (*str) {
        if (islower(*str)) {
            return 1;
        }
        str++;
    }
    return 0;
}

/**
 * Function to check if a string contains at least one digit character.
 */
int contains_digit(const char* str) {
    while (*str) {
        if (isdigit(*str)) {
            return 1;
        }
        str++;
    }
    return 0;
}

/**
 * Function to check if a string contains at least one special character.
 */
int contains_special(const char* str) {
    while (*str) {
        for (int i = 0; i < NUM_SPECIAL; i++) {
            if (*str == special_chars[i]) {
                return 1;
            }
        }
        str++;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    
    // Generate a password of length 16
    char password[17];
    generate_password(password, 16);
    printf("Generated password: %s\n", password);

    // Check if the password meets our security requirements
    if (!contains_upper(password)) {
        printf("Password must contain at least one uppercase letter!\n");
        return 1;
    }

    if (!contains_lower(password)) {
        printf("Password must contain at least one lowercase letter!\n");
        return 1;
    }

    if (!contains_digit(password)) {
        printf("Password must contain at least one digit!\n");
        return 1;
    }

    if (!contains_special(password)) {
        printf("Password must contain at least one special character!\n");
        return 1;
    }

    printf("Password meets all security requirements.\n");

    return 0;
}