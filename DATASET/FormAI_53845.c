//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 10

// Function to generate a secure password
void generatePassword(char* password) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;:<>?,./";
    int index = 0;
    for (int i = 0; i < LENGTH; i++) {
        int randomIndex = rand() % (sizeof(charset) - 1);
        password[index++] = charset[randomIndex];
    }
    password[index] = '\0';
}

int main() {
    char password[LENGTH + 1];

    // Seed the random number generator
    srand(time(NULL));

    printf("Generating a secure password...\n");
    generatePassword(password);

    printf("Your secure password is: %s\n", password);

    return 0;
}