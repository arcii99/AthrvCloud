//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char generateRandomChar() {
    char c = (rand() % 94) + 33; // Generate a random character between ASCII codes 33 and 126
    return c;
}

void generatePassword(char *password, int len, int index) {
    if (index == len) { // Base case: password string is complete
        password[index] = '\0'; // Add null terminator to string
        return;
    }
    password[index] = generateRandomChar(); // Generate a random character and add it to the password string
    generatePassword(password, len, index+1); // Recursively call the function with incremented index
}

int main() {
    int len;
    printf("Enter password length: ");
    scanf("%d", &len);
    srand(time(NULL)); // Seed random number generator with current time
    char password[len+1]; // Create character array to hold password string
    generatePassword(password, len, 0); // Start recursive function with initial index 0
    printf("Your secure password is: %s\n", password); // Print password string
    return 0;
}