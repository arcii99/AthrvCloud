//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20

int main(void) {
    char password[MAX_PASSWORD_LENGTH + 1] = ""; // initialize password to empty string
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+[]{};:<>,.?/-=";
    int charset_length = strlen(charset);

    srand(time(0)); // seed random number generator with current time

    printf("Password generator: \n");
    printf("---------------------\n");
    printf("Password length (max %d): ", MAX_PASSWORD_LENGTH);
    int password_length;
    scanf("%d", &password_length);

    if (password_length > MAX_PASSWORD_LENGTH) {
        printf("Password length can be max %d.\n", MAX_PASSWORD_LENGTH);
        exit(1);
    }

    for (int i = 0; i < password_length; i++) {
        int random_index = rand() % (charset_length - 1);
        password[i] = charset[random_index];
    }

    password[password_length] = '\0'; // terminate password with null character

    printf("Your password is: %s\n", password);

    return 0;
}