//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a secure password
void generatePassword(char password[], int length) {
    int i;
    srand(time(NULL));  // Seed the random number generator

    // Define the character sets
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char special[] = "!@#$%^&*()_+-=[]{}|;':\"<>,.?/";

    // Randomly select characters from each set and add to password
    for(i = 0; i < length; i++) {
        int r = rand() % 4;  // Randomly select which set to use
        if(r == 0) {
            password[i] = lower[rand() % 26];
        } else if(r == 1) {
            password[i] = upper[rand() % 26];
        } else if(r == 2) {
            password[i] = special[rand() % 31];
        } else {
            password[i] = (rand() % 10) + '0';
        }
    }
    password[length] = '\0';  // Add null terminator to the end of the password
}

int main() {
    // Define the length of the password to be generated
    int length = 12;
    char password[length + 1];

    // Generate the password and print it to the console
    generatePassword(password, length);
    printf("Generated password: %s\n", password);

    return 0;
}