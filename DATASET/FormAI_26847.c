//FormAI DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define PASSWORD_LENGTH 8 // Define password length

int main() {
    char password[PASSWORD_LENGTH + 1]; // Declare the password
    bool is_password_correct = false; // Set the flag for correct password to false
    
    // Loop until the correct password is entered
    while (!is_password_correct) {
        printf("Enter the password (must be %d characters long): ", PASSWORD_LENGTH);
        fgets(password, PASSWORD_LENGTH + 1, stdin); // Read the password from the user input
        password[strcspn(password, "\n")] = 0; // Remove the newline character
        
        // Check if the password has the correct length
        if (strlen(password) != PASSWORD_LENGTH) {
            printf("Invalid password length!\n");
        } else {
            // Check if the password contains only alphabets and numbers
            for (int i = 0; i < PASSWORD_LENGTH; i++) {
                if (!(isalpha(password[i]) || isdigit(password[i]))) {
                    printf("Invalid password characters detected!\n");
                    break;
                }
                
                if (i == PASSWORD_LENGTH - 1) {
                    is_password_correct = true; // Set the flag for correct password to true
                }
            }
        }
    }
    
    // If the loop is exited, that means the correct password has been entered
    printf("Password accepted!\n");
    
    return 0;
}