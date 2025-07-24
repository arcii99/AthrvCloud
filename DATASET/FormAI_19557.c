//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random password
void generatePassword(char *password, int length) {
    srand(time(NULL));
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    int maxChar = strlen(charset);
    
    for(int i = 0; i < length; i++) {
        password[i] = charset[rand() % maxChar];
    }
    password[length] = '\0';
}

int main() {
    int length = 0;
    char password[50];
    
    // Prompt user for password length
    printf("Enter desired length of password (between 8 and 50): ");
    scanf("%d", &length);
    
    // Check if length is within valid range
    if(length < 8 || length > 50) {
        printf("Invalid length. Password must be between 8 and 50 characters long.\n");
        return 1;
    }
    
    // Generate password and display to user
    generatePassword(password, length);
    printf("Your secure password is: %s\n", password);
    
    return 0;
}