//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

/* Function to generate a secure random password */
void generate_password(char*);

int main() {
    char password[PASSWORD_LENGTH+1];
    
    srand(time(NULL));  // Initialize random number generator
    
    // Generate password
    generate_password(password);
    
    printf("Your new password is: %s", password);
    
    return 0;
}

void generate_password(char* password) {
    int i, random_num;
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    
    for(i = 0; i < PASSWORD_LENGTH; i++) {
        random_num = rand() % 74;  // 74 = length of charset
        password[i] = charset[random_num];
    }
    
    password[PASSWORD_LENGTH] = '\0';  // Add null terminator
}