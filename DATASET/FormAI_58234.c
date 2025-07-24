//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10 // Change this to change length of password
#define MIN_ASCII_VALUE 33
#define MAX_ASCII_VALUE 126

char *generate_password(int length);
char random_ascii_char(void);

int main(void)
{
    srand(time(NULL)); // Set random seed

    char *password = generate_password(PASSWORD_LENGTH);
    printf("Your password is: %s", password);
    free(password); // Free memory allocated for password
    return 0;
}

char *generate_password(int length)
{
    char *password = malloc(sizeof(char) * (length + 1)); // Allocate memory for password
    if (password == NULL)
    {
        printf("Error: Unable to allocate memory for password.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < length; i++)
    {
        password[i] = random_ascii_char();
    }
    password[length] = '\0'; // Add null character to end of string
    return password;
}

char random_ascii_char(void)
{
    // Returns a random ASCII character between MIN_ASCII_VALUE and MAX_ASCII_VALUE
    return (char)(rand() % (MAX_ASCII_VALUE - MIN_ASCII_VALUE + 1) + MIN_ASCII_VALUE);
}