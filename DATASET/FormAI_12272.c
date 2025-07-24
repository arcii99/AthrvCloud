//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a secure password
void generate_password(int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}:<>?|[];',./`~"; // All possible characters for password
    
    // Set seed for random number generator
    srand(time(NULL));
    
    // Allocate memory for password string
    char *password = malloc(sizeof(char) * length + 1);
    
    // Generate password
    for (int i = 0; i < length; ++i) {
        password[i] = charset[rand() % sizeof(charset)];
    }
    
    password[length] = '\0'; // Add terminating NULL byte
    
    // Print password
    printf("Your secure password is: %s\n", password);
    
    free(password); // Free memory allocated for password
}

int main() {
    int password_length;
    
    // Prompt user for password length
    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the number of characters you would like your password to have: ");
    scanf("%d", &password_length);
    
    // Generate password and print it to the console
    generate_password(password_length);
    
    return 0;
}