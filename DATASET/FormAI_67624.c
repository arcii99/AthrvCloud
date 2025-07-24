//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 20

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the number of characters in the character set
#define NUM_CHARS 62

// Define the character set
const char charset[NUM_CHARS] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

// Declare the function that generates the password
void generate_password(int length, char *password);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare the password variable
    char password[MAX_PASSWORD_LENGTH + 1];

    // Generate the password and store it in the password variable
    generate_password(MAX_PASSWORD_LENGTH, password);

    // Print the password
    printf("Your password is: %s\n", password);

    return 0;
}

void generate_password(int length, char *password) {
    // Ensure the length is within bounds
    if (length > MAX_PASSWORD_LENGTH) {
        length = MAX_PASSWORD_LENGTH;
    }
    else if (length < MIN_PASSWORD_LENGTH) {
        length = MIN_PASSWORD_LENGTH;
    }

    // Generate the password
    for (int i = 0; i < length; i++) {
        int index = rand() % NUM_CHARS;
        password[i] = charset[index];
    }

    // Terminate the password string
    password[length] = '\0';
}