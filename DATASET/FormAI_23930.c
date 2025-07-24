//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Thou art a Secure Password Generator, fair and wise */
/* 
   With code so pure, and randomness divine,
   Thou canst protect even the secrets of mine,
   From brute-force attacks, and hackers malign. 
*/

#define PASSWORD_LENGTH 10

int main()
{
    int i, random_number;
    char password[PASSWORD_LENGTH + 1] = "";
    const char* alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-={}[]\\|:;\"'<>,.?/";

    /* Initialize random number generator with system time */
    srand(time(0));

    /* Generate random password of desired length */
    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        random_number = rand() % (int)sizeof(alphabet);
        password[i] = alphabet[random_number];
    }

    /* Terminate password string with null character */
    password[PASSWORD_LENGTH] = '\0';

    /* Print the generated password */
    printf("Hear ye, hear ye! Thy new password is:\n%s\n", password);

    return 0;
}