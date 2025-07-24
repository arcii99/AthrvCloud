//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

void generate_password(char* password);

int main() {
    char password[PASSWORD_LENGTH + 1];
    
    srand(time(0)); // Seed the random number generator
    
    generate_password(password);
    
    printf("Generated password: %s\n", password);
    
    return 0;
}

void generate_password(char* password) {
    int i;
    char character_set[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}\\|;:'\",.<>/?";
    int num_characters = sizeof(character_set) - 1; // Subtract 1 to exclude the null terminator
    
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = character_set[rand() % num_characters];
    }
    
    password[PASSWORD_LENGTH] = '\0'; // Add null terminator to the end of the password string
}