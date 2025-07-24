//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 16 // Define the length of the password to generate

// Declare function prototypes
char generateRandomCharacter();
void generatePassword(char *password);

// main function
int main()
{
    // Seed the random number generator with time
    srand((unsigned int) time(NULL));
    
    char password[PASSWORD_LENGTH + 1]; // Add one for the null terminator
    
    // Call the generatePassword function to create a secure password
    generatePassword(password);
    
    printf("Generated Password: %s\n", password);
    
    return 0;
}

// Function to generate a random character from a set of characters
char generateRandomCharacter()
{
    const char characterSet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;':\",./<>?`~\\"; // Set of characters to choose from
    
    int setLength = sizeof(characterSet) - 1; // Subtract 1 to account for null terminator
    
    return characterSet[rand() % setLength]; // Return a random character from the set
}

// Function to generate a secure password
void generatePassword(char *password)
{
    for(int i = 0; i < PASSWORD_LENGTH; i++)
    {
        password[i] = generateRandomCharacter(); // Generate a random character and add it to the password string
    }
    
    password[PASSWORD_LENGTH] = '\0'; // Add null terminator to the end of the password string
}