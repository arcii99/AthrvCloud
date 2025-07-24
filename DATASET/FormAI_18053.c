//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: mathematical
#include <stdio.h> // Standard Input Output library
#include <stdlib.h> // Standard library for memory allocation, random number generators etc
#include <time.h> // Standard library for time and date functions
#include <string.h> // Standard library for string functions

#define LENGTH 16 // Define the length of password needed

int main() {
    // Seed the random number generator
    srand(time(NULL));

    char password[LENGTH+1]; // Array to hold the generated password
    memset(password, '\0', sizeof(password)); // Fill the array with null terminators to initialize it

    // Characters to use for the password
    const char CHARACTERS[] = { 
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 
        'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
        'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 
        'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 
        'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 
        'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 
        'W', 'X', 'Y', 'Z', '1', '2', '3', '4', 
        '5', '6', '7', '8', '9', '0', '!', '@', 
        '#', '$', '%', '^', '&', '*', '(', ')', 
        '-', '_', '+', '=', '{', '}', '[', ']', 
        '|', '\\', ':', ';', '"', '\'', '<', '>', 
        ',', '.', '?', '/', '`', '~'
    };
    const int CHARACTERS_LENGTH = sizeof(CHARACTERS); // Length of above array

    for (int i = 0; i < LENGTH; i++) {
        int random_index = rand() % CHARACTERS_LENGTH; // Generate random index into character array
        char random_character = CHARACTERS[random_index]; // Get the corresponding character
        password[i] = random_character; // Add to the password array
    }

    printf("Generated Password: %s\n", password);

    return 0;
}