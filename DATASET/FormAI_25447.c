//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 16  // Maximum length of password
#define NUM_SPECIAL_CHARS 3  // Number of special characters in a password

// Function to generate a random character
char random_char() {
    int r = rand() % 62;
    char c;
    if (r < 26) {
        c = 'A' + r;
    } else if (r < 52) {
        c = 'a' + (r - 26);
    } else {
        c = '0' + (r - 52);
    }
    return c;
}

// Function to generate a random special character
char random_special_char() {
    int r = rand() % 4;
    char c;
    if (r == 0) {
        c = '!';
    } else if (r == 1) {
        c = '@';
    } else if (r == 2) {
        c = '#';
    } else if (r == 3) {
        c = '$';
    }
    return c;
}

// Function to check if a character is a special character
int is_special_char(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$');
}

int main() {
    srand(time(NULL));  // Seed the random number generator with the current time
    char password[MAX_LENGTH + 1];  // Array to store the password
    int num_special_chars = 0;  // Variable to keep track of the number of special characters
    int i;

    // Generate the password
    for (i = 0; i < MAX_LENGTH; i++) {
        if (i < 2 || num_special_chars < NUM_SPECIAL_CHARS) {  // First two characters and special characters
            char c;
            do {
                c = random_char();
            } while (is_special_char(c) && num_special_chars >= NUM_SPECIAL_CHARS);  // Make sure not to exceed number of special characters
            password[i] = c;
            if (is_special_char(c)) {
                num_special_chars++;
            }
        } else {  // Rest of the characters
            password[i] = random_char();
        }
    }
    password[MAX_LENGTH] = '\0';  // Null-terminate the password string

    // Convert the password to lowercase
    for (i = 0; i < MAX_LENGTH; i++) {
        password[i] = tolower(password[i]);
    }

    // Print the password
    printf("Your secure password is: %s\n", password);

    return 0;
}