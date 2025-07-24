//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // Declare and initialize variables
    char password[21];
    int num_special_chars = 0;
    int num_uppercase = 0;
    int num_digits = 0;
    int num_lowercase = 0;
    int i;

    srand(time(0)); // Initialize random number generator

    //Welcome Message
    printf("Welcome to the Secure Password Generator!\n");
    printf("Our star-cross'd website requires a password with at least:\n");
    printf("-One uppercase letter,\n");
    printf("-One lowercase letter,\n");
    printf("-One digit, and\n");
    printf("-One special character.\n");

    while(num_special_chars < 1 || num_uppercase < 1 || num_digits < 1 || num_lowercase < 1){
        // Generate a random password
        for(i = 0; i < 20; i++) {
            int rand_num = rand() % 4;
            if(rand_num == 0) {
                password[i] = '!';
                num_special_chars++;
            } else if(rand_num == 1) {
                password[i] = 'a' + rand() % 26;
                num_lowercase++;
            } else if(rand_num == 2) {
                password[i] = 'A' + rand() % 26;
                num_uppercase++;
            } else {
                password[i] = '0' + rand() % 10;
                num_digits++;
            }
        }
        password[20] = '\0'; // Null-terminating character

        // Check if password meets requirements
        if(num_special_chars < 1 || num_uppercase < 1 || num_digits < 1 || num_lowercase < 1) {
            printf("\nAlas, the stars are not aligned and the password generated does not meet our requirements.\n\n");
            printf("Our password hath %d special characters, %d uppercase letters, %d digits, and %d lowercase letters.\n", num_special_chars, num_uppercase, num_digits, num_lowercase);
            printf("Please try again...\n\n");
            num_special_chars = 0;
            num_uppercase = 0;
            num_digits = 0;
            num_lowercase = 0;
        }
    }
    // Password meets requirements
    printf("O happy dagger! Here is thy password: %s\n", password);

    return 0;
}