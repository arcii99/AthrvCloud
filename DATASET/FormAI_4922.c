//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

#define DIGIT_MASK 0x01 // used to check if a digit is present
#define UPPER_MASK 0x02 // used to check if an uppercase letter is present
#define LOWER_MASK 0x04 // used to check if a lowercase letter is present
#define SYMBOL_MASK 0x08 // used to check if a symbol is present

// function to generate a random number between min and max
int rand_range(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// function to generate a secure password
void generate_password(char* password)
{
    int length = rand_range(MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    int flags = 0;
    
    for (int i = 0; i < length; i++)
    {
        int type = rand_range(0, 3);
        char c;
        
        switch (type)
        {
            case 0:
                // generate a random digit
                c = rand_range('0', '9');
                flags |= DIGIT_MASK;
                break;
                
            case 1:
                // generate a random uppercase letter
                c = rand_range('A', 'Z');
                flags |= UPPER_MASK;
                break;
                
            case 2:
                // generate a random lowercase letter
                c = rand_range('a', 'z');
                flags |= LOWER_MASK;
                break;
                
            case 3:
                // generate a random symbol
                c = rand_range('!', '/');
                flags |= SYMBOL_MASK;
                break;
        }
        
        password[i] = c;
    }
    
    // check for required characters
    if ((flags & DIGIT_MASK) == 0)
    {
        // insert a random digit
        password[rand_range(0, length - 1)] = rand_range('0', '9');
    }
    
    if ((flags & UPPER_MASK) == 0)
    {
        // insert a random uppercase letter
        password[rand_range(0, length - 1)] = rand_range('A', 'Z');
    }
    
    if ((flags & LOWER_MASK) == 0)
    {
        // insert a random lowercase letter
        password[rand_range(0, length - 1)] = rand_range('a', 'z');
    }
    
    if ((flags & SYMBOL_MASK) == 0)
    {
        // insert a random symbol
        password[rand_range(0, length - 1)] = rand_range('!', '/');
    }
    
    password[length] = '\0'; // add null terminator
}

int main()
{
    srand(time(NULL)); // seed the random number generator
    
    char password[MAX_PASSWORD_LENGTH + 1];
    generate_password(password);
    
    printf("Your secure password is: %s\n", password);
    
    return 0;
}