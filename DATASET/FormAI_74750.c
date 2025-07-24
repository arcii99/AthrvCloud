//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 16

int main(void) {
  
    // Define the character set that can be used in the secure password.
    char charSet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%&*()_+~`|[]{}:;<>?,./-=";
  
    // Seed the random number generator with the current time.
    srand(time(NULL));
  
    // Allocate memory for the password.
    char* password = (char*)malloc(PASSWORD_LENGTH + 1);
  
    if (password == NULL) {
        printf("Error: Unable to allocate memory for password.");
        exit(1);
    }
  
    // Loop through PASSWORD_LENGTH characters and randomly select a character from the character set.
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = charSet[rand() % strlen(charSet)];
    }
  
    // Terminate the password string with the null character.
    password[PASSWORD_LENGTH] = '\0';
  
    // Output the generated password.
    printf("Your secure password is: %s\n", password);
  
    // Free the allocated memory.
    free(password);
  
    return 0;

}