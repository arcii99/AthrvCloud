//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 20 // Maximum length of the generated password
#define MIN_LENGTH 8 // Minimum length of the generated password

char getRandChar(); // Function to get a random character from an array of characters
void generatePassword(int length, char* password); // Function to generate a password of given length

// List of characters that can appear in the password
const char alphabet[62] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

int main(void) {
    srand(time(NULL)); // Seed random number generator with the current time
    
    printf("Welcome to the Secure Password Generator!\n");
    
    while(1) {
        printf("How long would you like your password to be? (8-20): ");
        char input[10];
        fgets(input, 10, stdin);
        
        int length = atoi(input);
        if(length >= MIN_LENGTH && length <= MAX_LENGTH) {
            char password[MAX_LENGTH+1];
            memset(password, 0, sizeof(password)); // Set all characters in the password to 0
            
            generatePassword(length, password);
            
            printf("Your new password is: %s\n", password);
            break;
        } else {
            printf("Invalid input. Please enter a number between 8 and 20.\n");
        }
    }
    
    return 0;
}

char getRandChar() {
    int index = rand() % 62;
    return alphabet[index];
}

void generatePassword(int length, char* password) {
    for(int i = 0; i < length; i++) {
        password[i] = getRandChar();
    }
}