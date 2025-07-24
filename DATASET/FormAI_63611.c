//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 3 // maximum number of login attempts
#define MAX_USERNAME_LEN 20 // maximum length of a username
#define MAX_PASSWORD_LEN 20 // maximum length of a password

typedef struct {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
} Credentials;

int main() {
    FILE *log_file;
    char *log_file_name = "log.txt"; // name of log file
    int login_attempts = 0; // number of login attempts
    int max_attempts = MAX_ATTEMPTS; // maximum number of login attempts
    time_t startTime, endTime; // variables to measure execution time

    startTime = time(NULL); // get start time

    log_file = fopen(log_file_name, "a"); // open log file

    if (log_file == NULL) {
        printf("Error: Cannot open log file!\n");
        return 1; // exit with error code 1
    }

    // keep asking for credentials until the maximum number of attempts is reached
    while (login_attempts < max_attempts) {
        Credentials credentials;
        char username[MAX_USERNAME_LEN];
        char password[MAX_PASSWORD_LEN];
        int authenticated = 0; // flag to indicate whether the user is authenticated

        printf("Username: ");
        fgets(username, MAX_USERNAME_LEN, stdin); // get username from user input
        printf("Password: ");
        fgets(password, MAX_PASSWORD_LEN, stdin); // get password from user input

        // remove newline character from username and password
        strtok(username, "\n");
        strtok(password, "\n");

        strcpy(credentials.username, username);
        strcpy(credentials.password, password);

        // write the credentials to the log file
        fprintf(log_file, "Username: %s, Password: %s\n", credentials.username, credentials.password);

        // check if the username and password are correct
        if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
            authenticated = 1; // set authenticated flag to true
        }

        if (authenticated) {
            printf("Authentication Successful!\n");
            fprintf(log_file, "Authentication Successful!\n");

            fclose(log_file); // close log file
            endTime = time(NULL); // get end time
            printf("Execution Time: %d seconds\n", (int) difftime(endTime, startTime)); // print execution time
            return 0; // exit program with success code 0
        } else {
            login_attempts++; // increment login attempts
            printf("Incorrect username or password! Please try again.\n");
            fprintf(log_file, "Incorrect username or password! Please try again.\n");
        }
    }

    printf("Maximum login attempts exceeded! Exiting program.\n");
    fprintf(log_file, "Maximum login attempts exceeded! Exiting program.\n");
    fclose(log_file); // close log file
    endTime = time(NULL); // get end time
    printf("Execution Time: %d seconds\n", (int) difftime(endTime, startTime)); // print execution time

    return 1; // exit with error code 1
}