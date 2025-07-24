//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a secure password
char* generate_password(int length) {
    // Define the characters to include in the password
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_+-=[]{}|;:,.<>?";
    int num_characters = sizeof(characters) - 1; // subtract 1 to exclude null terminator
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Allocate memory for the password
    char* password = malloc(length + 1);
    
    // Generate the password
    for(int i = 0; i < length; i++) {
        password[i] = characters[rand() % num_characters];
    }
    password[length] = '\0'; // add null terminator
    
    // Return the password
    return password;
}

int main() {
    int password_length;
    
    // Prompt the user for the password length
    printf("Enter the length of the password: ");
    scanf("%d", &password_length);
    
    // Generate the password
    char* password = generate_password(password_length);
    
    // Output the password to the console
    printf("Your secure password is: %s\n", password);
    
    // Free the password memory
    free(password);
    
    return 0;
}