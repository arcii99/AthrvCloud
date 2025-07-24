//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_LEN 8 // Minimum password length
#define MAX_LEN 32 // Maximum password length
#define CHARACTERS "!#$%&()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~" // List of valid characters for the password generator

int main()
{
    const int MAX_ATTEMPTS = 50; // Maximum number of attempts to generate a valid password
    char password[MAX_LEN+1]; // The generated password will be stored here, +1 to accommodate for the null character
    int attempts = 0; // Counter for the number of attempts to generate a valid password
    srand(time(0)); // Seed the random number generator with the current time
    memset(password, 0, sizeof password); // Initialize the password buffer with null characters
    
    while (attempts < MAX_ATTEMPTS)
    {
        int pw_len = rand() % (MAX_LEN - MIN_LEN + 1) + MIN_LEN; // Determine the password length between MIN_LEN and MAX_LEN (inclusive)
        int valid_chars_len = strlen(CHARACTERS); // Determine the number of valid characters in the password generator
        int i;
        
        // Generate the password by selecting random characters from the list of valid characters
        for (i = 0; i < pw_len; i++) {
            int char_index = rand() % valid_chars_len;
            password[i] = CHARACTERS[char_index];
        }
        
        // Password must contain at least one uppercase letter, one lowercase letter, and one digit
        int uppercase = 0, lowercase = 0, digit = 0;
        for (i = 0; i < pw_len; i++) {
            if (password[i] >= 'A' && password[i] <= 'Z')
                uppercase = 1;
            else if (password[i] >= 'a' && password[i] <= 'z')
                lowercase = 1;
            else if (password[i] >= '0' && password[i] <= '9')
                digit = 1;
        }
        
        // If the password contains at least one uppercase letter, one lowercase letter, and one digit, we consider it valid
        if (uppercase && lowercase && digit) {
            printf("Generated password: %s\n", password);
            break;
        }
        
        attempts++; // Increment the number of attempts to generate a valid password
    }
    
    // If we've exceeded the maximum number of attempts to generate a valid password, print an error message
    if (attempts == MAX_ATTEMPTS) {
        printf("Error: unable to generate a valid password after %d attempts.\n", MAX_ATTEMPTS);
    }
    
    return 0;
}