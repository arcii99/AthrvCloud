//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a secure password
char* generatePassword() {
    char* password = (char*) malloc(9 * sizeof(char)); // Allocate memory for the password
    srand(time(NULL)); // Seed the random number generator
    for(int i = 0; i < 8; i++) {
        int randomNum = rand() % 3;
        if(randomNum == 0) { // Generate a random lowercase letter
            password[i] = (char)(rand() % 26 + 97);
        } else if(randomNum == 1) { // Generate a random uppercase letter
            password[i] = (char)(rand() % 26 + 65);
        } else { // Generate a random number
            password[i] = (char)(rand() % 10 + 48);
        }
    }
    password[8] = '\0'; // Add null terminator to the end of the password
    return password;
}

int main() {
    char* password = generatePassword(); // Generate a new password
    printf("Your new password is: %s\n", password); // Print the password
    free(password); // Free the memory used by the password
    return 0;
}