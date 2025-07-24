//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// function prototypes
void shuffle(char *array, size_t n);
char generateRandomChar();
void generatePassword(char *password, int length);

int main(void) {
    // seed random number generator
    srand(time(NULL));

    // define password length and initialize password array
    int length = 12;
    char password[length + 1];

    // generate password and print it
    generatePassword(password, length);
    printf("Your new secure password is: %s\n", password);

    return 0;
}

// shuffles char array using Fisher-Yates algorithm
void shuffle(char *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            char t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

// generates a random character for password
char generateRandomChar() {
    char c;
    do {
        int r = rand() % 94 + 33; // ASCII values between 33 and 126
        c = (char)r;
    } while (!isalnum(c)); // make sure char is alphanumeric
    return c;
}

// generates password of specified length
void generatePassword(char *password, int length) {
    // initialize password array with random characters
    for (int i = 0; i < length; i++) {
        password[i] = generateRandomChar();
    }
    password[length] = '\0'; // null terminator

    // shuffle password array for added randomness
    shuffle(password, length);

    // make sure password has at least one uppercase, lowercase, and numeric character
    char uppercase = generateRandomChar();
    char lowercase = generateRandomChar();
    char numeric = generateRandomChar();
    while (!isupper(uppercase) || !islower(lowercase) || !isdigit(numeric)) {
        int index = rand() % length;
        if (!isupper(uppercase)) {
            password[index] = uppercase;
            uppercase = generateRandomChar();
        } else if (!islower(lowercase)) {
            password[index] = lowercase;
            lowercase = generateRandomChar();
        } else if (!isdigit(numeric)) {
            password[index] = numeric;
            numeric = generateRandomChar();
        }
    }
}