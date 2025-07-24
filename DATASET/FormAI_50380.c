//FormAI DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <string.h>

#define MAX_PW_LEN 20

int main()
{
    char passwords[3][MAX_PW_LEN+1]; // array to store up to 3 passwords
    int numPasswords = 0; // number of stored passwords
    int i;

    printf("Welcome to the password management program!\n");

    while (numPasswords < 3) {

        char pw[MAX_PW_LEN+1]; // variable to store new password
        int pwLen;

        // prompt user for new password
        printf("Enter new password (maximum length %d characters): ", MAX_PW_LEN);
        fgets(pw, MAX_PW_LEN+1, stdin);

        // check if password is too long (exceeds buffer size)
        pwLen = strlen(pw)-1; // don't count newline character
        if (pwLen == MAX_PW_LEN && pw[MAX_PW_LEN-1] != '\n') {
            printf("Password is too long! Maximum length is %d characters.\n", MAX_PW_LEN);
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        // check if password is too short
        if (pwLen == 0 || pw[0] == '\n') {
            printf("Password cannot be empty!\n");
            continue;
        }

        // check if password is already stored
        for (i = 0; i < numPasswords; i++) {
            if (strcmp(pw, passwords[i]) == 0) {
                printf("Password is already stored!\n");
                break;
            }
        }
        if (i < numPasswords) {
            continue;
        }

        // store password
        strcpy(passwords[numPasswords], pw);
        numPasswords++;

        printf("Password stored successfully!\n\n");

    }

    // print stored passwords
    printf("The stored passwords are:\n");
    for (i = 0; i < numPasswords; i++) {
        printf("%d. %s\n", i+1, passwords[i]);
    }

    printf("Thank you for using the password management program!\n");

    return 0;
}