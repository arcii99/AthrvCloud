//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length, numUpperCase, numLowerCase, numDigits, numSpecial;
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    printf("Enter the number of uppercase letters: ");
    scanf("%d", &numUpperCase);
    printf("Enter the number of lowercase letters: ");
    scanf("%d", &numLowerCase);
    printf("Enter the number of digits: ");
    scanf("%d", &numDigits);
    printf("Enter the number of special characters: ");
    scanf("%d", &numSpecial);

    srand(time(NULL)); // Seed the random number generator

    char password[length+1]; // Create a char array to store the password
    int i, j;
    for(i = 0; i < numUpperCase; i++) { // Generate uppercase letters
        password[i] = rand() % 26 + 'A'; // Generate a random uppercase letter
    }
    for(j = i; j < numUpperCase + numLowerCase; j++) { // Generate lowercase letters
        password[j] = rand() % 26 + 'a'; // Generate a random lowercase letter
    }
    for(i = j; i < numUpperCase + numLowerCase + numDigits; i++) { // Generate digits
        password[i] = rand() % 10 + '0'; // Generate a random digit
    }
    char specialChars[] = "!@#$%^&*()_+{}|:<>?-=[]\\;',./"; // List of special characters
    for(j = i; j < length; j++) { // Generate special characters
        password[j] = specialChars[rand() % 29]; // Generate a random special character
    }

    // Shuffle the password
    for(i = 0; i < length; i++) {
        j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    password[length] = '\0'; // Make sure the string is null-terminated

    printf("Your password is: %s\n", password);

    return 0;
}