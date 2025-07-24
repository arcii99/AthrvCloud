//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generatePassword(int length);

int main() {
    // Ask user for password length
    int length;
    printf("Enter password length: ");
    scanf("%d", &length);
    
    // Generate password and print it to the console
    char* password = generatePassword(length);
    printf("Generated password: %s", password);
    
    // Free memory used by password
    free(password);
    
    return 0;
}

char* generatePassword(int length) {
    // Define character set to use for password generation
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";
    const int charsetLength = sizeof(charset) - 1;
    
    // Initialize random seed
    srand(time(NULL));
    
    // Allocate memory for password
    char* password = malloc((length + 1) * sizeof(char));
    
    // Generate random characters
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charsetLength];
    }
    
    // Add null terminator to end of password
    password[length] = '\0';
    
    return password;
}