//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 1024 /* Maximum input length */
#define MAX_ATTEMPTS 5 /* Maximum number of login attempts */

int login_attempts = 0; /* Number of login attempts done */

/* Function to detect intrusion */
void detect_intrusion(char *username, char *password){
    if(strcmp(username,"admin")==0 && strcmp(password,"password123")==0){
        /* Successful login. Do nothing. */
    }
    else{
        /* Intrusion detected. Increment the login attempts. */
        printf("Intrusion Attempt Detected!\n");
        login_attempts++;

        /* If maximum attempts reached, abort the program. */
        if(login_attempts == MAX_ATTEMPTS){
            printf("Maximum login attempts reached! Aborting the program.\n");
            exit(1);
        }
    }
}

int main(){
    char username[MAX_LENGTH], password[MAX_LENGTH];

    /* Get the username and password from the user */
    printf("Enter username: ");
    fgets(username,MAX_LENGTH,stdin);
    username[strcspn(username,"\n")] = 0;

    printf("Enter password: ");
    fgets(password,MAX_LENGTH,stdin);
    password[strcspn(password,"\n")] = 0;

    /* Check for intrusion */
    detect_intrusion(username,password);

    /* Access granted message */
    printf("Access granted!\n");

    return 0;
}