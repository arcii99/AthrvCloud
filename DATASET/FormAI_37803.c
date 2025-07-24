//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8  // minimum length of password
#define MAX_PASSWORD_LENGTH 16 // maximum length of password

#define NUM_SPECIAL_CHARS 8    // number of special characters to choose from
const char special_chars[NUM_SPECIAL_CHARS] = {'!', '@', '#', '$', '%', '&', '?', '*'};

// Function to randomly generate a secure password
char* generate_password(int length) {
    char* password = malloc(sizeof(char) * (length + 1)); // allocate memory for password
    password[length] = '\0'; // set null terminator at end of password string

    srand(time(NULL)); // seed random number generator with current time

    int i;
    for (i = 0; i < length; ++i) {
        int type = rand() % 4;

        // Select a character from the corresponding set
        if (type == 0) { // uppercase letter
            password[i] = (char)(rand() % 26 + 'A');
        } else if (type == 1) { // lowercase letter
            password[i] = (char)(rand() % 26 + 'a');
        } else if (type == 2) { // digit
            password[i] = (char)(rand() % 10 + '0');
        } else { // special character
            password[i] = special_chars[rand() % NUM_SPECIAL_CHARS];
        }
    }

    return password;
}

int main(void) {
    int length = MIN_PASSWORD_LENGTH + rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1); // generate random password length

    char* password = generate_password(length);
    printf("Generated Password: %s\n", password);

    free(password); // remember to free allocated memory

    return 0;
}