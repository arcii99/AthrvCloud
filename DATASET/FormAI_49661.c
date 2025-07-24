//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_ATTEMPTS 3 // maximum number of attempts allowed
#define PASSWORD "password" // the password

int main() {
    int attempts = 0; // current number of failed attempts
    char input[20]; // stores user input

    while(attempts < MAX_ATTEMPTS) {
        printf("Enter password: ");
        scanf("%s", input); // read input from user

        if(strcmp(input, PASSWORD) == 0) { // check if password is correct
            printf("Access granted!\n");
            break; // exit loop if password is correct
        } else {
            printf("Incorrect password. Please try again.\n");
            attempts++; // increment failed attempts
        }
    }

    if(attempts == MAX_ATTEMPTS) { // exceeded max attempts
        printf("Access denied. Too many attempts.\n");
        // log intrusion attempt
        FILE *fp = fopen("intrusion_log.txt", "a");
        fprintf(fp, "Intrusion attempt at %s\n", __TIME__);
        fclose(fp);
    }

    return 0;
}