//FormAI DATASET v1.0 Category: String manipulation ; Style: Cyberpunk
// This program is a cyberpunk style example of manipulating C Strings
// It randomly generates a hacker name, replaces letters with numbers and encrypts the final name
// The program illustrates various string manipulation techniques in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to replace vowels with numbers
void replaceVowels(char string[]) {
    int i;
    for (i = 0; i < strlen(string); i++) {
        switch(string[i]) {
            case 'a':
                string[i] = '4';
                break;
            case 'e':
                string[i] = '3';
                break;
            case 'i':
                string[i] = '1';
                break;
            case 'o':
                string[i] = '0';
                break;
            case 'u':
                string[i] = '9';
                break;
            default:
                continue;
        }
    }
}

// Function to encrypt the string using a cypher
void encryptString(char string[]) {
    int i, key = 9; // the key for the cypher

    for (i = 0; i < strlen(string); i++) {
        if (string[i] >= 'a' && string[i] <= 'z') { // if the character is lowercase
            string[i] = ((string[i] - 'a') + key) % 26 + 'a'; // encrypt it using the cypher
        }
    }
}

int main() {
    // Array of available hacker names
    char hackerNames[10][10] = {"Neon", "Matrix", "Ghost", "Raven", "Rebel", "Cypher", "Virus", "Zigzag", "Bullet", "Viper"};

    srand(time(NULL)); // seed for random number generation

    // Generate a random index for the hacker name array
    int randomNumber = rand() % 10;

    // Create a copy of the hacker name and replace vowels with numbers
    char hackerName[10];
    strcpy(hackerName, hackerNames[randomNumber]);
    replaceVowels(hackerName);

    // Encrypt the hacker name
    encryptString(hackerName);

    // Print the results
    printf("Your hacker name is: %s\n", hackerName);

    return 0;
}