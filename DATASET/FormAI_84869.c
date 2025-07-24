//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* generate_password(char* password, int length);
void randomize_password(char* password, int length);
void set_random_character(char* password, int index);
char get_random_char();
int is_special_char(char c);
int has_special_char(char* password);

int main() {
    char password[16];
    printf("Generating a random 16-character secure password...\n");
    generate_password(password, 16);
    printf("Password: %s\n", password);
    return 0;
}

// Generates a secure password of given length
char* generate_password(char* password, int length) {
    if (length == 0) { // base case
        return password;
    }

    randomize_password(password, length); // set random characters
    if (has_special_char(password)) { // check if special char exists
        return password;
    }

    // try again recursively otherwise
    generate_password(password, length);
}

// Randomize the password (set random characters)
void randomize_password(char* password, int length) {
    for (int i = 0; i < length; i++) {
        set_random_character(password, i);
    }
}

// Set a random character at given index of password
void set_random_character(char* password, int index) {
    char c;
    do {
        c = get_random_char();
    } while (index == 0 && is_special_char(c)); // disallow special char at index 0
    password[index] = c;
}

// Get a random character from ASCII table
char get_random_char() {
    return (rand() % 94) + 33; // range from '!' to '~' in ASCII table
}

// Check if given character is a special character
int is_special_char(char c) {
    char special_chars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '_', '<', '>', '?', '/'};
    for (int i = 0; i < sizeof(special_chars); i++) {
        if (c == special_chars[i]) {
            return 1; // is special char
        }
    }
    return 0; // is not special char
}

// Check if password has at least one special character
int has_special_char(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (is_special_char(password[i])) {
            return 1; // has special char
        }
    }
    return 0; // does not have special char
}