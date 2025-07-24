//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate secure random password
char * generate_password(int length) {

    // Define the characters that can be used in the password
    const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@!$%&*";
    int characters_count = sizeof(characters) - 1;

    // Allocate a dynamic memory for the password
    char *password = (char*) malloc(sizeof(char) * (length + 1));
    if (password == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    // Generate the password using random numbers
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int random_index = rand() % characters_count;
        password[i] = characters[random_index];
    }

    // Add a null character at the end to terminate the string
    password[length] = '\0';

    return password;
}

// Main function to test the password generator
int main() {

    // Prompt user for password length
    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    // Generate the password and print it
    char *password = generate_password(length);
    printf("Your secure password: %s\n", password);

    // Free allocated memory
    free(password);

    return 0;
}