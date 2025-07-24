//FormAI DATASET v1.0 Category: Password management ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int main()
{
    char password[20];
    int attempts = 3;
    printf("Please enter your password: ");
    scanf("%s", password);
    while (strcmp(password, "secret") != 0 && attempts > 0) {
        attempts--;
        printf("Wrong password. %d attempts left.\n", attempts);
        printf("Please enter your password: ");
        scanf("%s", password);
    }

    if (attempts == 0) {
        printf("Too many attempts. Your account has been locked.\n");
    } else {
        printf("Welcome!\n");
        // do something here
    }

    return 0;
}