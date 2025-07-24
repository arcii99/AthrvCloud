//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALLOWED_LOGINS 3

int main()
{
    int consecutive_failed_logins = 0;
    char username[20], password[20], input_username[20], input_password[20];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    while(consecutive_failed_logins < MAX_ALLOWED_LOGINS)
    {
        printf("\nEnter username: ");
        scanf("%s", input_username);
        printf("Enter password: ");
        scanf("%s", input_password);

        if(strcmp(input_username, username) == 0 && strcmp(input_password, password) == 0) {
            printf("\nSuccessful login!\n");
            break;
        }
        else {
            printf("\nLogin failed. Please try again.\n");
            consecutive_failed_logins++;
        }
    }

    if(consecutive_failed_logins >= MAX_ALLOWED_LOGINS) {
        printf("\nMaximum allowed login attempts exceeded. Intrusion detected!\n");
    }

    return 0;
}