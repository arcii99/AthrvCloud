//FormAI DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_SIZE 10

int main() {
    char stored_password[PASSWORD_SIZE];
    char guess[PASSWORD_SIZE];
    int max_guesses = 3;
    int num_guesses = 0;
    
    // Generate the password
    srand(time(NULL));
    for (int i = 0; i < PASSWORD_SIZE - 1; i++) {
        stored_password[i] = rand() % 26 + 'a';
    }
    stored_password[PASSWORD_SIZE - 1] = '\0';
    
    printf("The password has been generated. Please guess the password:\n");
    
    while (num_guesses < max_guesses) {
        scanf("%s", guess);
        if (strcmp(stored_password, guess) == 0) {
            printf("Congratulations! You have guessed the password.\n");
            return 0;
        } else {
            printf("That was not the correct password. You have %d guesses remaining.\n", max_guesses - num_guesses - 1);
            num_guesses++;
        }
    }
    
    printf("Sorry, you have used your maximum number of guesses. The password was: %s\n", stored_password);
    return 0;
}