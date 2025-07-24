//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length, i, randNum;
    char password[100];

    printf("Welcome to the Secure Password Generator!\n");
    printf("How long would you like your password to be? (min 8 characters)\n");
    scanf("%d", &length);

    /* Ensuring password is at least 8 characters long */
    if (length < 8) {
        printf("Invalid password length - defaulting to 8 characters.\n");
        length = 8;
    }

    srand(time(0)); /* seed the random number generator with current time */

    /* Generating random characters for password */
    for (i = 0; i < length; i++) {
        randNum = rand() % 94 + 33; /* ASCII characters 33-126 are printable */
        password[i] = (char)randNum;
    }

    password[length] = '\0'; /* Adding null character to end of string */

    printf("Your secure password is: %s\n", password);

    return 0;
}