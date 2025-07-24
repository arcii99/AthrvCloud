//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define LENGTH 14 // Length of the password
#define NUM_DIGITS 4 // Number of digits in the password
#define SYMBOLS "!@#$%^&*()-_=+{}[]<>?,.;:"

int main() {

    char password[LENGTH+1]; // +1 for NULL character
    int i, j;
    char c;
    int num_digits = 0;
    
    srand(time(NULL)); // Initialize random seed
    
    printf("Welcome to the Secure Password Generator!\n");
    
    // Generate password
    for (i = 0; i < LENGTH; i++) {
        
        // Generate random ASCII character
        if (i < NUM_DIGITS ||
            (i >= NUM_DIGITS && rand() % 2 == 0 && num_digits < NUM_DIGITS)) {
            
            c = rand() % 10 + '0'; // Generate digit
            num_digits++;
            
        } else {
            
            if (rand() % 2 == 0) {
                c = rand() % 26 + 'a'; // Generate lowercase letter
            } else {
                c = rand() % 26 + 'A'; // Generate uppercase letter
            }
            
        }
        
        // Add symbol to password
        if (rand() % 2 == 0 && i != 0 && i != LENGTH-1) {
            j = rand() % strlen(SYMBOLS);
            c = SYMBOLS[j];
        }
        
        password[i] = c;
        
    }
    
    password[LENGTH] = '\0'; // Add NULL character
    
    // Print password
    printf("\nYour secure password is: %s\n", password);
    
    return 0;
}