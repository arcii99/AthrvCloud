//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 25

// Function to generate a secure random password
void generate_password(char *password) {
    char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+~`|}{[]\\:;?><,./-=";
    int num_uppercase = 0, num_lowercase = 0, num_numbers = 0, num_symbols = 0;
    int length = 0, i = 0;

    // Generate random values for each type of character in the password
    num_uppercase = rand() % 6 + 1;
    num_lowercase = rand() % 6 + 1;
    num_numbers = rand() % 6 + 1;
    num_symbols = rand() % 6 + 1;

    // Calculate the total length of the password
    length = num_uppercase + num_lowercase + num_numbers + num_symbols;

    // Generate the password using the randomly generated values
    for (i = 0; i < num_uppercase; i++) {
        password[i] = uppercase_letters[rand() % strlen(uppercase_letters)];
    }
    for (i = num_uppercase; i < num_uppercase + num_lowercase; i++) {
        password[i] = lowercase_letters[rand() % strlen(lowercase_letters)];
    }
    for (i = num_uppercase + num_lowercase; i < num_uppercase + num_lowercase + num_numbers; i++) {
        password[i] = numbers[rand() % strlen(numbers)];
    }
    for (i = num_uppercase + num_lowercase + num_numbers; i < length; i++) {
        password[i] = symbols[rand() % strlen(symbols)];
    }

    // Shuffle the password characters
    for (i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate the password string
    password[length] = '\0';
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    srand(time(NULL));

    // Generate a secure random password and print it to the console
    generate_password(password);
    printf("Your secure password is: %s\n", password);

    return 0;
}