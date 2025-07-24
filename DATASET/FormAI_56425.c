//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8

int main(void) {
    // Initialize random seed
    srand(time(NULL));
    
    // Define password variables
    int password_length;
    char password[MAX_PASSWORD_LENGTH + 1];
    char password_characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+={}[]|\\;:'\",.<>/?";
    
    // Get user input for password length
    printf("Enter password length (%d-%d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &password_length);
    
    // Validate user input
    if (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length.\n");
        return 1;
    }
    
    // Generate password
    for (int i = 0; i < password_length; i++) {
        password[i] = password_characters[rand() % (sizeof(password_characters) - 1)];
    }
    password[password_length] = '\0';
    
    // Print generated password
    printf("Generated password: %s\n", password);
    
    return 0;
}