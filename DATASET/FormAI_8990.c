//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a secure password
void generate_password(char *password, int length) {
    srand(time(NULL)); // Seed random number generator with current time

    // Set of possible characters for password generation
    char char_set[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=<>?,./;:'[]{}|`~";

    // Generate random password character by character
    for (int i = 0; i < length-1; i++) {
        int rand_num = rand() % (sizeof(char_set)-1); // Generate random number between 0 and length of char_set
        password[i] = char_set[rand_num]; // Add random character to password
    }

    password[length-1] = '\0'; // Add null terminator to end of password
}

int main() {
    char password[20]; // Initialize array to store password

    generate_password(password, 20); // Call function to generate password

    printf("Your secure password is: %s\n", password); // Print password
}