//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int password_length;
    char password[100];
    int i, choice;
    
    printf("Welcome to the Secure Password Generator!");
    printf("\n\nPlease choose your password length (minimum 8 characters, maximum 20 characters): ");
    scanf("%d", &password_length);
    
    if (password_length < 8 || password_length > 20) {
        printf("\nInvalid password length. Program exiting.\n");
        exit(0);
    }
    
    srand(time(0)); // initialize random seed
    
    printf("\nPlease choose your password complexity:\n");
    printf("1. Alphabets\n2. Alphanumeric\n3. Alphanumeric + Special Characters\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: // generate password with alphabets only
            for (i = 0; i < password_length; i++) {
                password[i] = 'a' + (rand() % 26);
            }
            break;
        case 2: // generate password with alphabets and numbers
            for (i = 0; i < password_length; i++) {
                if (i % 2 == 0) { // generate alphabet
                    password[i] = 'a' + (rand() % 26);
                } else { // generate number
                    password[i] = '0' + (rand() % 10);
                }
            }
            break;
        case 3: // generate password with alphabets, numbers and special characters
            char special_characters[] = "!@#$%^&*()_+-={}[]|\;:'\"<>,.?/~`";
            int num_special_characters = sizeof(special_characters) / sizeof(special_characters[0]);
            for (i = 0; i < password_length; i++) {
                if (i % 3 == 0) { // generate alphabet
                    password[i] = 'a' + (rand() % 26);
                } else if (i % 3 == 1){ // generate number
                    password[i] = '0' + (rand() % 10);
                } else { // generate special character
                    password[i] = special_characters[rand() % num_special_characters];
                }
            }
            break;
        default:
            printf("\nInvalid choice. Program exiting.\n");
            exit(0);
    }
    
    printf("\nYour generated password is: %s", password);
    
    return 0;
}