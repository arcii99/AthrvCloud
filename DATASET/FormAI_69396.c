//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

// Function to generate a random uppercase letter
char generate_random_uppercase() {
    return 'A' + (rand() % 26);
}

// Function to generate a random lowercase letter
char generate_random_lowercase() {
    return 'a' + (rand() % 26);
}

// Function to generate a random digit
char generate_random_digit() {
    return '0' + (rand() % 10);
}

// Function to generate a random special character
char generate_random_special_character() {
    char special_characters[] = "!@#%^&*()_+-=[]{}|;':\"<>,.?/~`";
    return special_characters[rand() % 25];
}

// Function to generate a random password
void generate_password(char password[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        int random_digit = rand() % 4;
        if (random_digit == 0) {
            password[i] = generate_random_uppercase();
        } else if (random_digit == 1) {
            password[i] = generate_random_lowercase();
        } else if (random_digit == 2) {
            password[i] = generate_random_digit();
        } else {
            password[i] = generate_random_special_character();
        }
    }
    password[length] = '\0';
}

// Function to check if a password is valid
int is_password_valid(char password[]) {
    int i, has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special_character = 0;
    for (i = 0; password[i] != '\0'; i++) {
        has_uppercase |= isupper(password[i]);
        has_lowercase |= islower(password[i]);
        has_digit |= isdigit(password[i]);
        has_special_character |= !isalnum(password[i]);
    }
    return has_uppercase && has_lowercase && has_digit && has_special_character && (i >= MIN_PASSWORD_LENGTH) && (i <= MAX_PASSWORD_LENGTH);
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    srand(time(NULL));
    do {
        generate_password(password, MIN_PASSWORD_LENGTH + (rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1)));
    } while (!is_password_valid(password));
    printf("Your password is: %s\n", password);
    return 0;
}