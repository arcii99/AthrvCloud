//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12 // Set the desired password length here

int main() {
    char password[PASSWORD_LENGTH + 1]; // Initialize the password array with space for null terminator

    srand(time(NULL)); // Seed the random number generator with the current time

    // Define arrays for random characters to be chosen from
    const char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char special_characters[] = "!@#$%^&*()_+{}[]|\\/?><,.`~";

    int num_lowercase = PASSWORD_LENGTH / 3; // Determine how many of each type of character to include
    int num_uppercase = PASSWORD_LENGTH / 3;
    int num_digits = PASSWORD_LENGTH / 4;
    int num_special = PASSWORD_LENGTH - num_lowercase - num_uppercase - num_digits;

    // Loop through the password array and randomly assign characters from each array
    for (int i = 0; i < num_lowercase; i++) {
        password[i] = lowercase_letters[rand() % 26];
    }
    for (int i = num_lowercase; i < num_lowercase + num_uppercase; i++) {
        password[i] = uppercase_letters[rand() % 26];
    }
    for (int i = num_lowercase + num_uppercase; i < num_lowercase + num_uppercase + num_digits; i++) {
        password[i] = digits[rand() % 10];
    }
    for (int i = num_lowercase + num_uppercase + num_digits; i < PASSWORD_LENGTH; i++) {
        password[i] = special_characters[rand() % 24];
    }
    // Randomly shuffle the password array to add an extra layer of complexity
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int j = rand() % PASSWORD_LENGTH;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    // Add null terminator to the end of the password array
    password[PASSWORD_LENGTH] = '\0';

    printf("Your secure password is: %s\n", password);

    return 0;
}