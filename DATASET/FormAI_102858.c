//FormAI DATASET v1.0 Category: System administration ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ADMIN "root"

int main(){
    char username[20];
    char password[20];
    int tries = 0;

    printf("Please login to the system.\n");

    while(tries < 3){
        printf("Username: ");
        scanf("%s", username);

        printf("Password: ");
        scanf("%s", password);

        if(strcmp(username, ADMIN) == 0 && strcmp(password, "pUzzl3m3Plz!") == 0){
            printf("Welcome, %s!\n", username);
            printf("You have unlocked the secret program.\n");

            // code to run the secret program goes here.
            printf("The secret program is running...\n");

            for(int i = 0; i < 10; i++){
                char command[20];
                sprintf(command, "echo 'Puzzle piece #%d'", i+1);
                system(command);
                sleep(1);
            }

            printf("Program complete. Exiting...\n");

            return 0;
        }

        printf("Invalid username or password. Please try again.\n");
        tries++;
    }

    printf("Too many attempts. Exiting...\n");

    return 0;
}