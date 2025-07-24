//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_password(int length) {
    // Declare a character array of size equals to the length of password
    char password[length + 1]; 
    
    // Set the seed for random number generator
    srand(time(NULL));
    
    // Set the characters set for generating the password
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+=-[]{};':\"\\|,.<>/?`~";
    
    int index;
    for (int i = 0; i < length; i++) {
        // Generate a random number within the range of the characters set
        index = rand() % (int)(sizeof(characters) - 1);
        
        // Assign the character at the random index to the current position in password array
        password[i] = characters[index];
    }
    
    // Null terminate the password array
    password[length] = '\0';
    
    printf("Your new secure password: %s\n", password);
}

int main() {
    int length;
    
    // Prompt user for the length of password
    printf("Enter the length of the password you want to generate: ");
    scanf("%d", &length);
    
    // Generate and print the secure password
    generate_password(length);
    
    return 0;
}