//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a secure password
void generate_password(char *password, int length) {
    // Define the legal characters that can be used in the password
    const char legal_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-+={}[]\\|<,>.?/~`";
    int char_len = sizeof(legal_chars) - 1; // Subtract 1 to accommodate for null terminator
    srand(time(NULL)); // Seed the random number generator with the current time

    // Generate random characters for the password
    for (int i = 0; i < length; i++) {
        int random_index = rand() % char_len;
        password[i] = legal_chars[random_index];
    }

    password[length] = '\0'; // Add null terminator to the end of the password
}

int main() {
    int length;
    char password[32];

    // Get user input for desired password length
    printf("Enter desired password length (maximum 32): ");
    scanf("%d", &length);

    // Check if length is within range
    if (length < 1 || length > 32) {
        printf("Invalid length input. Please enter a value between 1 and 32.\n");
        return 0; // End program if input is invalid
    }

    // Call function to generate password and print result
    generate_password(password, length);
    printf("Your secure password is: %s\n", password);

    return 0;
}