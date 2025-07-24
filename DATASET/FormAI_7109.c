//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a secure password */
char* generate_password(int length) {
    char* password = malloc(length + 1);  // Allocate memory for password string
    int i = 0;
    int random_num;

    /* Seed the random number generator */
    srand(time(NULL));

    /* Generate password */
    while (i < length) {
        random_num = rand() % 94 + 33;  // Generate random number between 33 and 126 (ASCII printable characters)
        if ((random_num >= 33 && random_num <= 47) || (random_num >= 58 && random_num <= 64) || (random_num >= 91 && random_num <= 96)) {
            /* Exclude special characters such as ",',\,|, etc */
            continue;
        }
        password[i] = (char)random_num;  // Convert random number to ASCII character
        i++;
    }
    password[length] = '\0';  // Null terminate the password string

    return password;
}

int main() {
    int length = 10;  // Length of password
    char* password = generate_password(length);
    printf("Your new secure password is: %s\n", password);
    free(password);  // Free memory used for password string
    return 0;
}