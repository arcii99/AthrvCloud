//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASS_LENGTH 12 // maximum password length
#define NUM_SPECIAL_CHARS 9 // number of special characters available

char specialChars[NUM_SPECIAL_CHARS] = {'!', '@', '#', '$', '%', '^', '&', '*', '('};

void generatePassword(char *password);
void shuffleArray(char *array, size_t size);
char getRandomSpecialChar();

int main()
{
    char password[PASS_LENGTH + 1] = {0}; // initialize password buffer
    
    srand(time(NULL)); // initialize random seed
    
    generatePassword(password);
    
    printf("Generated Password: %s\n", password); // print generated password
    
    return 0;
}

// Function to generate secure password
void generatePassword(char *password)
{
    char lowercaseLetters[26];
    char uppercaseLetters[26];
    char numbers[10];
    char specialCharsUsed[3];
    
    // Fill arrays with their respective characters
    for(int i = 0; i < 26; i++)
    {
        lowercaseLetters[i] = 'a' + i;
        uppercaseLetters[i] = 'A' + i;
        
        if(i < 10)
        {
            numbers[i] = '0' + i;
        }
    }

    // Randomly select characters to be used in password
    for(int i = 0; i < 2; i++)
    {
        specialCharsUsed[i] = getRandomSpecialChar();
    }
    
    // Shuffle arrays for added security
    shuffleArray(lowercaseLetters, sizeof(lowercaseLetters));
    shuffleArray(uppercaseLetters, sizeof(uppercaseLetters));
    shuffleArray(numbers, sizeof(numbers));
    shuffleArray(specialChars, sizeof(specialChars));

    // Build password with shuffled arrays and randomly selected characters
    strncpy(password, lowercaseLetters, 2);
    strncpy(password + 2, uppercaseLetters, 2);
    strncpy(password + 4, numbers, 2);
    strncpy(password + 6, specialCharsUsed, 2);
    strncpy(password + 8, lowercaseLetters + 2, 2);
    strncpy(password + 10, uppercaseLetters + 2, 2);
    
    password[PASS_LENGTH] = '\0'; // null-terminate password
}

// Function to shuffle given array
void shuffleArray(char *array, size_t size)
{
    if(size > 1)
    {
        for(int i = size - 1; i > 0; i--)
        {
            int j = rand() % (i + 1);
            
            char temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
}

// Function to get random special character
char getRandomSpecialChar()
{
    return specialChars[rand() % NUM_SPECIAL_CHARS];
}