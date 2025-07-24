//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *generate_password(int length);

int main(void) {
    int length;
     
    printf("Welcome to the Secure Password Generator!\n");
    printf("How long do you want your password to be?\n");
    
    // get user input for password length
    scanf("%d", &length);
     
    // generate password
    char *password = generate_password(length);
    
    // output the result
    printf("Your new password is: %s\n", password);
    
    // free the memory allocated for the password
    free(password);
    
    return 0;
}

char *generate_password(int length) {
    // define a string with all possible characters to use in the password
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890~!@#$%^&*()_+-=";
    
    // seed the random number generator
    srand((unsigned int) time(NULL));
    
    // allocate enough memory for the password
    char *password = malloc(sizeof(char) * (length + 1));
    
    // generate random characters to fill the password
    for(int i = 0; i < length; i++) {
        password[i] = characters[rand() % (sizeof(characters) - 1)];
    }
    
    // null terminate the string
    password[length] = '\0';
    
    return password;
}