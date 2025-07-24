//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12 // change this to increase or decrease password length

int main() {
    char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char special_characters[] = "!@#$%^&*()_+{}:\"?><[]',./\\=-`~|";

    char password[PASSWORD_LENGTH + 1]; // extra 1 to include '\0' at the end of the string

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate random characters for the password
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int random_number = rand() % 4; // generate a random number from 0 to 3

        // Select a random character set and a random character from that set
        switch(random_number) {
            case 0:
                password[i] = lowercase_letters[rand() % (sizeof(lowercase_letters) - 1)];
                break;
            case 1:
                password[i] = uppercase_letters[rand() % (sizeof(uppercase_letters) - 1)];
                break;
            case 2:
                password[i] = numbers[rand() % (sizeof(numbers) - 1)];
                break;
            case 3:
                password[i] = special_characters[rand() % (sizeof(special_characters) - 1)];
                break;
            default:
                printf("Error: something went wrong.\n");
                return 1;
        }
    }

    // Add the null character to the end of the password string
    password[PASSWORD_LENGTH] = '\0';

    // Print the password to the console
    printf("Your new password is: %s\n", password);

    return 0;
}