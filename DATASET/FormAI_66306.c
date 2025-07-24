//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 15

char generateRandomChar()
{
    int randomNumber = rand() % 94 + 32;   // Random character from ASCII table 32 to 126
    return (char)randomNumber;
}

void shuffleArray(char* array, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size - 1; i++) {
        int j = rand() % (size - i);
        char temp = array[i];
        array[i] = array[i + j];
        array[i + j] = temp;
    }
}

int main()
{
    char password[PASSWORD_LENGTH + 1]; // Password length plus null terminator
    char characters[94];   // Array of all possible characters for password
    
    for (int i = 0; i < 94; i++) {
        characters[i] = generateRandomChar();
    }
    
    shuffleArray(characters, 94);   // Shuffle the array to ensure randomness
    
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = characters[i];
    }
    
    password[PASSWORD_LENGTH] = '\0';   // Add null terminator to end of password
    
    printf("Your password is: %s\n", password);   // Output the generated password
    
    return 0;
}