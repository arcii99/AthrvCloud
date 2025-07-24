//FormAI DATASET v1.0 Category: Educational ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the Paranoia Program!\n");
    printf("Enter a password to begin: ");

    // initialize password input array
    char password[50];

    // read password input from user
    fgets(password, 50, stdin);

    // remove newline character from password input
    for (int i = 0; i < 50; i++) {
        if (password[i] == '\n') {
            password[i] = '\0';
            break;
        }
    }

    // check if password is correct
    if (strcmp(password, "paranoia")) {
        printf("Incorrect password. Exiting program...\n");
        return 0;
    }

    // start program
    printf("\nInitiating paranoia sequence...\n\n");

    // initialize program variables
    int count = 0;
    int rand_num;

    // generate random number and print paranoid message
    while (count < 10) {
        rand_num = rand() % 100;
        printf("Warning! Security breach detected! Random number: %d\n", rand_num);
        count++;
    }

    // print final paranoid message and terminate program
    printf("\nParanoia sequence complete. Remember to always trust no one!\n");
    return 0;
}