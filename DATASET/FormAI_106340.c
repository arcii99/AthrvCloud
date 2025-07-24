//FormAI DATASET v1.0 Category: System administration ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <pwd.h>

/* Define constants */
#define MAX_USERNAME_LEN  32
#define MAX_PASSWORD_LEN  32
#define VALID_USERNAME    "admin"
#define VALID_PASSWORD    "password"

/* Define functions */
int verify_password(char *password);

/* Main method */
int main(void) {
    /* Define variables */
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    int authenticated = 0;

    /* Prompt user for username */
    printf("Username: ");
    fgets(username, MAX_USERNAME_LEN, stdin);

    /* Prompt user for password */
    printf("Password: ");
    fgets(password, MAX_PASSWORD_LEN, stdin);

    /* Remove newline characters */
    username[strcspn(username, "\n")] = 0;
    password[strcspn(password, "\n")] = 0;

    /* Verify credentials */
    if (strcmp(username, VALID_USERNAME) == 0) {
        authenticated = verify_password(password);
    }

    /* Handle authentication */
    if (authenticated) {
        printf("Authentication successful!\n");
        /* Add your desired System administration code here */
    } else {
        printf("Authentication failed.\n");
        /* Terminate program */
        exit(1);
    }

    /* Terminate program */
    return 0;
}

/* Verify password */
int verify_password(char *password) {
    if (strcmp(password, VALID_PASSWORD) == 0) {
        return 1;
    } else {
        return 0;
    }
}