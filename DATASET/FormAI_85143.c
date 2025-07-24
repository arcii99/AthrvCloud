//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char generate_char() {
    int type = rand() % 4; // determine type of character to generate
    int ascii_code;
    switch(type) {
        case 0: // generate uppercase letter
            ascii_code = rand() % 26 + 65; // range of uppercase letters in ASCII table
            break;
        case 1: // generate lowercase letter
            ascii_code = rand() % 26 + 97; // range of lowercase letters in ASCII table
            break;
        case 2: // generate digit
            ascii_code = rand() % 10 + 48; // range of digits in ASCII table
            break;
        case 3: // generate special character
            ascii_code = rand() % 15 + 33; // range of common special characters in ASCII table
            break;
    }
    return (char) ascii_code;
}

int main() {
    srand(time(NULL)); // seed random number generator with current time
    int password_length;
    printf("Enter desired password length (at least 8 characters): ");
    scanf("%d", &password_length);
    if(password_length < 8) {
        printf("Invalid password length. Password must be at least 8 characters.\n");
        return 0;
    }
    char* password = malloc(sizeof(char) * (password_length + 1)); // allocate memory for password
    for(int i = 0; i < password_length; i++) {
        password[i] = generate_char(); // generate a random character for each position in password
    }
    password[password_length] = '\0'; // terminate password with null character
    printf("Generated password: %s\n", password);
    free(password); // free memory allocated for password
    return 0;
}