//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: medieval
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

#define MAX_LENGTH 20 // Maximum length of the password.
#define MIN_LENGTH 8 // Minimum length of the password.
#define MAX_DIGITS 3 // Maximum number of digits allowed.
#define MAX_UPPER 3 // Maximum number of upper case letters allowed.
#define MAX_LOWER 3 // Maximum number of lower case letters allowed.

int main(){
    char password[MAX_LENGTH + 1];
    srand((unsigned int)time(NULL)); // Seed the random number generator.
    int length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH; // Get a random password length between MIN_LENGTH and MAX_LENGTH (inclusive).
    int num_digits = rand() % (MAX_DIGITS + 1); // Get a random number of digits.
    int num_upper = rand() % (MAX_UPPER + 1); // Get a random number of uppercase letters.
    int num_lower = rand() % (MAX_LOWER + 1); // Get a random number of lowercase letters.

    // Fill the password with random characters.
    for(int i = 0; i < length; i++){
        int c;
        do{
            c = rand() % 94 + 33; // ASCII characters between 33 and 126 are printable.
        }while(!isdigit(c) && !isupper(c) && !islower(c)); // Ensure that the character is a digit, uppercase letter or lowercase letter.
        password[i] = (char)c;
    }

    // Insert the required number of digits, uppercase letters and lowercase letters at random positions.
    for(int i = 0; i < num_digits; i++){
        int pos = rand() % length;
        while(!isdigit(password[pos])){
            pos = rand() % length;
        }
        password[pos] = '0' + rand() % 10; // Replace the random digit with a new random digit.
    }
    for(int i = 0; i < num_upper; i++){
        int pos = rand() % length;
        while(!isupper(password[pos])){
            pos = rand() % length;
        }
        password[pos] = 'A' + rand() % 26; // Replace the random uppercase letter with a new random uppercase letter.
    }
    for(int i = 0; i < num_lower; i++){
        int pos = rand() % length;
        while(!islower(password[pos])){
            pos = rand() % length;
        }
        password[pos] = 'a' + rand() % 26; // Replace the random lowercase letter with a new random lowercase letter.
    }

    password[length] = '\0'; // Null-terminate the password string.
    printf("Your medieval secure password is: %s\n", password);

    return 0;
}