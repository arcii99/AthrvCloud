//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Helper function to generate a random character
char rand_char() {
    int r = rand() % 3;
    switch (r) {
        case 0:
            // return a random uppercase letter
            return (char)(rand() % 26 + 65);
        case 1:
            // return a random lowercase letter
            return (char)(rand() % 26 + 97);
        case 2:
            // return a random digit
            return (char)(rand() % 10 + 48);
    }
}

// Function to generate a secure password of given length
void generate_secure_password(char *password, int length) {
    int i;
    for (i = 0; i < length; i++) {
        password[i] = rand_char();
    }
    password[i] = '\0';
}

int main() {
    srand(time(NULL)); // Initialize random seed
    char password[20];
    int length = 10;

    generate_secure_password(password, length);

    printf("Secure Password: %s\n", password);

    return 0;
}