//FormAI DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random password
void generate_password(char *password, int length) {
    srand(time(NULL));
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
    int char_length = sizeof(characters) - 1;

    for(int i = 0; i < length; i++) {
        int index = rand() % char_length;
        password[i] = characters[index];
    }
    password[length] = '\0';
}

int main() {
    int length;
    printf("*** Welcome to the Password Management System ***\n\n");
    printf("How many characters would you like your password to include? ");
    scanf("%d", &length);

    // Validate password length
    if(length < 8) {
        printf("\nInvalid password length! Password should be at least 8 characters long.\n");
    }
    else {
        char password[length + 1];
        generate_password(password, length);
        printf("\nYour newly generated password is: %s\n", password);
    }
    return 0;
}