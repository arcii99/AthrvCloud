//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate and print password
void generatePassword(int len)
{
    char password[len];
    int i, random;

    // Seed the random generator with the current time
    srand((unsigned) time(NULL));

    // Select characters from a combination of lower and upper case letters, digits, and symbols
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '|', ':', ';', '<', '>', ',', '.', '?'};

    // Generate random password of length len
    for(i=0; i<len; i++) {
        random = rand() % 95;
        password[i] = characters[random];
    }

    // Print generated password
    printf("Generated Password: %s\n", password);
}

int main()
{
    int len;

    // Prompt user for password length
    printf("Enter password length: ");
    scanf("%d", &len);

    // Check if password length is at least 8 characters
    if(len >= 8) {
        generatePassword(len);
    } else {
        printf("Password length must be at least 8 characters.\n");
    }

    return 0;
}