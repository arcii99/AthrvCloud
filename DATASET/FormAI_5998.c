//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This function generates a random character from ASCII 33 to ASCII 126 */
char generate_random_char() {
    return (char)(rand() % 94 + 33);
}

/* This function generates a random password */
void generate_password(int password_length, char *password) {
    srand(time(NULL)); /* Seed the random number generator */
    for (int i = 0; i < password_length; i++) {
        password[i] = generate_random_char();
    }
    password[password_length] = '\0'; /* Terminate the string */
}

int main() {
    int password_length;

    printf("Enter length of password: ");
    scanf("%d", &password_length);

    /* Allocate memory for password */
    char *password = (char *) malloc(password_length + 1);

    /* Generate password */
    generate_password(password_length, password);

    /* Print password */
    printf("Generated Password: %s\n", password);

    /* Free memory */
    free(password);

    return 0;
}