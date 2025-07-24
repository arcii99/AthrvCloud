//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char message[100];
    char secret_key[] = "rose";

    printf("My dear, please enter the secret key to access the system: ");
    scanf("%s", message);

    if (strcmp(message, secret_key) == 0) {
        printf("Access granted! Welcome to the system, my love.\n");
    } else {
        printf("Intrusion detected! Emergency protocol initiated.\n");

        int count = 0;
        while (count < 3) {
            printf("Please enter the correct secret key to disable the security system: ");
            scanf("%s", message);

            if (strcmp(message, secret_key) == 0) {
                printf("Security system disabled. I forgive your intrusion, my love.\n");
                exit(EXIT_SUCCESS);
            } else {
                printf("Access denied. Intruder alert!\n");
                count++;
            }
        }

        printf("Maximum attempts reached. Initiating self-destruct sequence.\n");

        // Code for self-destruct sequence goes here
    }

   return 0;
}